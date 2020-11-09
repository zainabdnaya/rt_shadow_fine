/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 22:06:20 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 09:46:49 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void square_parsing(t_minirt *rt) 
{
    int count;
    t_square   *square;

    if (!(square = malloc(sizeof(t_square))))
        {
            obj_error(23);
            exit(1);
        }
    count = ft_count(rt->pars.splitrest);
    if (count != 5)
    {
        free(square);
        obj_error(27);
        exit(1);
    }
    square->center = vectorSplit(rt->pars.splitrest[1]);
    square->normal = vectorSplit(rt->pars.splitrest[2]);
    if ((square->normal.x > 1 || square->normal.x < -1) || (square->normal.y > 1 || square->normal.y < -1) || (square->normal.z > 1 || square->normal.z < -1))
        {
            obj_error(24);
            exit(1);
        }
    square->color = colorSplit(rt, rt->pars.splitrest[4]);
    square->side_size = convert_to_double(rt->pars.splitrest[3]);
    if(square->side_size < 0 )
    {
        obj_error(30);
        exit(1);
    }
    add_objects(&rt->list_obj, copy_square(square->center, square->normal, square->side_size, square->color));
    free(square);
}

double  square_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin)
{
    t_use scal;

    scal.one = vectorDot(ray_direction,rt->list_obj->normal);
    if(scal.one != 0)
    {
        scal.up = vectorSub(origin,rt->list_obj->sq_center);
        rt->solution = (-1/scal.one)*vectorDot(scal.up,rt->list_obj->normal);
    }
    if(rt->solution > 0)
    {
        scal.produit = vectorScale(ray_direction, rt->solution);
        scal.point_pos = vectorAdd(origin,scal.produit);
        scal.q_ed =  vectorSub(scal.point_pos,rt->list_obj->sq_center);
        scal.edge = rt->list_obj->side_size/ 2;

        if (fabs(scal.q_ed.x) > scal.edge || fabs(scal.q_ed.y) > scal.edge || fabs(scal.q_ed.z) > scal.edge)
            return (0);
        return (rt->solution);
    }
    return(0);
}

void calcul_square(t_minirt *rt )
{
    t_use scal;

    scal.one_scal = vectorScale(rt->ray_direction, rt->list_obj->solution);
    rt->list_obj->position = vectorAdd(rt->list_camera->look_from, scal.one_scal);
    scal.denominator = vectorDot(rt->list_obj->normal,rt->ray_direction);
        if(scal.denominator > 0)
        rt->list_obj->normal = vectorScale(rt->list_obj->normal,(-1));
    rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
}