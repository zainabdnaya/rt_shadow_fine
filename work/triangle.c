/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:07:48 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 09:47:43 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void triangle_parsing(t_minirt *rt)
{
    int count;
    t_triangle *triangle;

    if (!(triangle = malloc(sizeof(t_triangle))))
        {
                obj_error(23);
                exit(1);
        }
    count = ft_count(rt->pars.splitrest);
    if (count != 5)
    {
        free(triangle);
        obj_error(26);
        exit(1);
    }
    triangle->point_a = vectorSplit(rt->pars.splitrest[1]);
    triangle->point_b = vectorSplit(rt->pars.splitrest[2]);
    triangle->point_c = vectorSplit(rt->pars.splitrest[3]);
    triangle->color = colorSplit(rt, rt->pars.splitrest[4]);
    add_objects(&rt->list_obj, copy_triangle(triangle->point_a, triangle->point_b, triangle->point_c, triangle->color));
    free(triangle);
}


double    triangle_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin)
{
    t_use scal;
    
    scal.edge1 = vectorSub(rt->list_obj->point_b,rt->list_obj->point_a);
    scal.edge2 = vectorSub(rt->list_obj->point_c,rt->list_obj->point_a);
    scal.vect = vectorCross(ray_direction,scal.edge2);
    scal.determinant = vectorDot(scal.vect,scal.edge1);
    if (fabs(scal.determinant) < __DBL_EPSILON__ )
        return(0);
//calculate distance from point_a to ray origin
    scal.diffrence= vectorSub(origin,rt->list_obj->point_a);
    scal.inverse_determinant = 1.0/scal.determinant;
// calculate U parameter and test bounds
    scal.u = (scal.inverse_determinant)* (vectorDot(scal.diffrence,scal.vect));
    if(scal.u < 0.0 || scal.u > 1.0 )
        return(0);
    scal.vect1 = vectorCross(scal.diffrence,scal.edge1);
    scal.v = (vectorDot(scal.vect1,ray_direction))*(scal.inverse_determinant);
//prepare to test V parameter 
    if(scal.v < 0 || scal.v + scal.u > 1.0)
            return(0);

    rt->solution = (vectorDot(scal.vect1,scal.edge2)) * (scal.inverse_determinant);
        //if(rt->solution > __DBL_EPSILON__)
            return(rt->solution);
        //else
           // return(0);
}   

void    calcul_triangle(t_minirt *rt)
{
    t_use scal;

        scal.edge1 = vectorSub(rt->list_obj->point_b,rt->list_obj->point_a);
    scal.edge2 = vectorSub(rt->list_obj->point_c,rt->list_obj->point_a);
    scal.one_scal = vectorScale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectorAdd(rt->list_camera->look_from, scal.one_scal);
        rt->list_obj->normal = vectorCross(scal.edge1,scal.edge2);
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
        if(vectorDot( rt->list_obj->normal,rt->ray_direction) > __DBL_EPSILON__)
            rt->list_obj->normal = vectorScale(rt->list_obj->normal,(-1));
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);

    //rt->l_norm = vectorSub(rt->light->position, rt->list_obj->position);
}