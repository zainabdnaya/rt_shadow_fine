/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:59:41 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 13:55:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void plan_parsing(t_minirt *rt)
{
    int count;
    t_plan *plan;

    if (!(plan = malloc(sizeof(t_plan))))
        {
            obj_error(23);
            exit(1);
        }
    count = ft_count(rt->pars.splitrest);
    if (count != 4)
    {
        free(plan);
        obj_error(25);
        exit(1);
    }
    plan->point = vectorSplit(rt->pars.splitrest[1]);
    plan->norm = vectorSplit(rt->pars.splitrest[2]);
    if((plan->norm.x > 1 ||  plan->norm.x < -1) || (plan->norm.y > 1 || plan->norm.y < -1) || (plan->norm.z > 1 || plan->norm.z < -1))
          {
              obj_error(24);
              exit(1);
          } 
    plan->color = colorSplit(rt, rt->pars.splitrest[3]);
    add_objects(&rt->list_obj, copy_plan(plan->point, plan->norm, plan->color));
    free(plan);
}


double      plan_equation(t_minirt *rt,t_vector ray_direction,t_vector origin)
{
    t_use scal;
    
    scal.denominator = vectorDot(rt->list_obj->p_norm,ray_direction);
     if ( scal.denominator != 0.0)
    {
        scal.one_scal = vectorSub(origin,rt->list_obj->point);
        rt->solution = (-1) * (vectorDot(scal.one_scal,rt->list_obj->p_norm)) / scal.denominator;
        if ( rt->solution > 0)
            return (rt->solution);
        rt->list_obj->normal =rt->list_obj->p_norm;
        if(scal.denominator < 0)
            rt->list_obj->normal = vectorScale(rt->list_obj->p_norm,(-1));
        rt->list_obj->normal = vectorNorme(rt->list_obj->normal);
    }
    return (0);
}


void    calcul_plan(t_minirt *rt)
{
  
    
    rt->list_obj->position.x = rt->list_camera->look_from.x + rt->list_obj->solution * rt->ray_direction.x;
    rt->list_obj->position.y = rt->list_camera->look_from.y + rt->list_obj->solution * rt->ray_direction.y;
    rt->list_obj->position.z = rt->list_camera->look_from.z + rt->list_obj->solution * rt->ray_direction.z;

}