/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:23:59 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 09:48:00 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minirt.h"

void  cylindre_parsing(t_minirt *rt)
{
    int count;
    t_cylindre *cylindre;
    if(!(cylindre = malloc(sizeof(t_cylindre))))
            {
                obj_error(23);
                exit(1);
            }
    count = ft_count(rt->pars.splitrest);
    if(count != 6)
    {
        free(cylindre);
        obj_error(28);
        exit(1);
    }
    cylindre->center = vectorSplit(rt->pars.splitrest[1]);
    cylindre->cy_normal = vectorSplit(rt->pars.splitrest[2]);
    if ((cylindre->cy_normal.x > 1 || cylindre->cy_normal.x < -1) || (cylindre->cy_normal.y > 1 || cylindre->cy_normal.y < -1) || (cylindre->cy_normal.z > 1 || cylindre->cy_normal.z < -1))
        {
            obj_error(24);
            exit(1);
        }
    cylindre->color = colorSplit(rt,rt->pars.splitrest[3]);
    cylindre->diameter = convert_to_double(rt->pars.splitrest[4]);
    cylindre->height = convert_to_double(rt->pars.splitrest[5]);
    if(cylindre->diameter < 0 || cylindre->height < 0)
        {
            obj_error(29);
            exit(1);   
        }
    add_objects(&rt->list_obj,copy_cylindre(cylindre->center,cylindre->cy_normal,cylindre->diameter, cylindre->height,cylindre->color));
    free(cylindre);
}


double      cylindre_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin)
{
    t_use scal;
    double   radius;
    
    radius = rt->list_obj->diameter/2;
    scal.a = vectorDot(ray_direction,ray_direction) - pow(vectorDot(ray_direction,rt->list_obj->cy_normal),2);
    scal.x_vect = vectorSub(origin,rt->list_obj->cy_center);
    scal.b = 2 * (vectorDot(ray_direction,scal.x_vect)-(vectorDot(ray_direction,rt->list_obj->cy_normal)* vectorDot(scal.x_vect,rt->list_obj->cy_normal)));
    scal.c = vectorDot(scal.x_vect,scal.x_vect) - (pow(vectorDot(scal.x_vect,rt->list_obj->cy_normal),2)) - (pow(radius,2));
    scal.discriminant = scal.b * scal.b - 4 * scal.a * scal.c;
    if (scal.discriminant < 0)
             return (0);
    scal.t3 = (-scal.b + sqrt(scal.discriminant)) / (2 * scal.a);
    scal.t4 = (-scal.b - sqrt(scal.discriminant)) / (2 * scal.a);
    scal.m = vectorDot(ray_direction,rt->list_obj->cy_normal) * scal.t3 + vectorDot(scal.x_vect,rt->list_obj->cy_normal);
    scal.m1 = vectorDot(ray_direction,rt->list_obj->cy_normal) * scal.t4 + vectorDot(scal.x_vect,rt->list_obj->cy_normal);
    if (scal.m1 >= 0 && scal.m1 <= rt->list_obj->height)
    {
        rt->solution = scal.t4;
        rt->m = scal.m1;
    } 
    else if (scal.m >= 0 && scal.m <= rt->list_obj->height)
    {
         rt->solution = scal.t3;
         rt->m = scal.m;
    }
    else
        rt->solution = 0;
    return(rt->solution);
}

void    calcul_cylindre(t_minirt *rt)
{
    t_use scal;
    
    scal.one_scal = vectorScale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectorAdd(rt->list_camera->look_from, scal.one_scal);
    scal.vect = vectorSub(rt->list_obj->position,rt->list_obj->cy_center);
    scal.vect1 = vectorScale(rt->list_obj->cy_normal,rt->m);
    scal.vect2 =  vectorSub(scal.vect,scal.vect1);
    rt->list_obj->normal = vectorNorme(scal.vect2);
    if(vectorDot(rt->ray_direction,rt->list_obj->normal) > 0.0)
                rt->list_obj->normal = vectorScale(rt->list_obj->normal,(-1));
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);

    //  printf("normal  x===>%f\n", rt->list_obj->normal.x);
    //  printf("normal  y===>%f\n", rt->list_obj->normal.y);
    //  printf("normal  z===>%f\n", rt->list_obj->normal.z);
}





