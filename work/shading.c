/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:29:40 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/09 13:34:43 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


void       shadow_objects(t_minirt *rt)
{
       t_objects *tmp;
       int i;

       i = 0;

       tmp = NULL;
        tmp = rt->list_obj;
        rt->shadow = 0;
        rt->hit_shadow = 0;
         while( rt->list_obj != NULL)
             { 
                rt->shadow_origin.x = rt->list_light->position.x +  0.001 * rt->list_obj->light_norm.x;
                rt->shadow_origin.y = rt->list_light->position.y + 0.001 * rt->list_obj->light_norm.y;
                rt->shadow_origin.z = rt->list_light->position.z + 0.001 * rt->list_obj->light_norm.z;
                 rt->shadow_direction.x = rt->position.x - rt->list_light->position.x ;// p - light.origin
                 rt->shadow_direction.y = rt->position.y - rt->list_light->position.y ;// p - light.origin
                 rt->shadow_direction.z = rt->position.z - rt->list_light->position.z ;// p - light.origin
                 rt->shadow_direction = vectorNorme(rt->shadow_direction);
                 if (rt->list_obj->wich_objects == 1)
                     rt->hit_shadow = sphere_equation(rt,rt->shadow_direction,rt->shadow_origin);
                 if (rt->list_obj->wich_objects == 2 )
                     rt->hit_shadow = plan_equation(rt,rt->shadow_direction,rt->shadow_origin);
                 if (rt->list_obj->wich_objects == 3)
                     rt->hit_shadow = triangle_equation(rt,rt->shadow_direction,rt->shadow_origin);
                 if (rt->list_obj->wich_objects == 4 )
                     rt->hit_shadow = square_equation(rt,rt->shadow_direction,rt->shadow_origin);
                 if(rt->list_obj->wich_objects == 5 )
                        rt->hit_shadow  = cylindre_equation(rt,rt->shadow_direction,rt->shadow_origin);
                 if (rt->hit_shadow > 0.0)
                    {
                            if ( rt->hit_shadow < distance(rt->list_light->position,rt->position))
                                {
                                    rt->shadow = 1;
                                    rt->percent_shadow += 0.4;
                                    break;
                                }

                    }
                rt->list_obj = rt->list_obj->next;
            }
        rt->list_obj =  tmp;
}


void       wich_shadow(t_minirt *rt)
{
        static double sh = 0;
        t_list_lights *lgt;
        lgt = NULL;
        lgt = rt->list_light;
        //rt->hit_shadow = 0;
        rt->percent_shadow =0;
        while(rt->list_light != NULL)
            {
                shadow_objects(rt);   
                rt->list_light = rt->list_light->next;
           }
        rt->list_light = lgt; 
        // rt->percent_shadow = sh;       
}