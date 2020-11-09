/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:45:19 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/09 13:09:39 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


int         list_size(t_objects *list)
{
    int count ;

    count = 0;
    while(list!= NULL)
    {
        count++;
    list = list->next;
    }
    return(count);    
}

void      calcul_data(t_minirt *rt)
{
            if(rt->check == 1)
                calcul_sphere(rt);
         if (rt->check == 2) 
                calcul_plan(rt);
         if (rt->check == 3)
                calcul_triangle(rt);
          if (rt->check == 4)
                calcul_square(rt);            
         if (rt->check== 5)
                calcul_cylindre(rt);
        else
            return;
}

 
void  object_coloration(t_minirt *rt)
{
    t_list_lights *lgt;
    lgt = NULL;
        rt->Id.x = 0;
    rt->Id.y = 0;
    rt->Id.z = 0;

    rt->Spec.x = 0;
    rt->Spec.y = 0;
    rt->Spec.z = 0;

    lgt = rt->list_light;
    while(rt->list_light != NULL)
        {
           
            rt->result_color = rt->list_obj->color;
            rt->n_norm = rt->list_obj->normal;
            rt->position = rt->list_obj->position;
            rt->list_obj->light_norm = vectorSub(rt->list_light->position, rt->position);
            rt->ratio = rt->list_light->ratio; 
            rt->light_rgb = rt->list_light->rgb;
            rt->l_norm = vectorNorme(rt->list_obj->light_norm);
            rt->Id   = vectorAdd(diffuse(rt),rt->Id);
            rt->Spec = vectorAdd(spec(rt),rt->Spec);

            rt->list_light = rt->list_light->next;
        }
    rt->list_light = lgt;
}

void        wich_object(t_minirt *rt,double *cmp)
{
    double var = 0;
    t_color test = {255,255,255};
    t_objects *tmp;
    t_list_lights *lgt;
    
    rt->exist = 0;
    lgt = NULL;
    tmp = NULL;
    tmp = rt->list_obj;
    // lgt = rt->list_light;
    // while(rt->list_light != NULL)
    //     {
            while( rt->list_obj != NULL)
            {
                if(rt->list_obj->wich_objects == 1)
                    var = sphere_equation(rt,rt->ray_direction,rt->list_camera->look_from);
                if(rt->list_obj->wich_objects == 2)
                        var  = plan_equation(rt,rt->ray_direction,rt->list_camera->look_from);
                if (rt->list_obj->wich_objects == 3)
                         var = triangle_equation(rt,rt->ray_direction,rt->list_camera->look_from);
                if (rt->list_obj->wich_objects == 4)
                        var = square_equation(rt,rt->ray_direction,rt->list_camera->look_from);
                 if(rt->list_obj->wich_objects == 5)
                    var  = cylindre_equation(rt,rt->ray_direction,rt->list_camera->look_from);
                if (var > 0.0 && var < *cmp)
                {
                    *cmp = var;
                    rt->list_obj->solution = *cmp;
                    rt->check = rt->list_obj->wich_objects;
                    calcul_data(rt);
                    object_coloration(rt);
                    rt->exist = 1;
                }
                rt->list_obj  = rt->list_obj->next;
            }
            rt->list_obj =  tmp;
    //     }
    // rt->list_light = lgt;

 }

t_color ray_Tracing(t_minirt *rt)
{
    int i;
    double    cmp = INT_MAX; 
    t_color black = {0, 0, 0};
    t_color test  = {255,0,255};
    t_color result1;
    
    
    wich_object(rt,&cmp);
    if (rt->exist == 1)
     {  
        rt->shadow = 0;
        wich_shadow(rt);
        //if (rt->shadow == 1)
        //{
            if(rt->percent_shadow > 1)
              rt->percent_shadow = 1;
            rt->percent_shadow = 1-rt->percent_shadow;
            result1.g = 255  * (ambiant(rt).y +rt->percent_shadow *(rt->Id.y + rt->Spec.y ));
            result1.r = 255  * (ambiant(rt).x +rt->percent_shadow *( rt->Id.x + rt->Spec.x));
            result1.b = 255  * (ambiant(rt).z +rt->percent_shadow *(rt->Id.z + rt->Spec.z ));
        //}
        //else if ( rt->shadow == 0)
        //{
        //    result1.r = 255  * (ambiant(rt).x + rt->Id.x + rt->Spec.x );
        //    result1.g = 255  * (ambiant(rt).y + rt->Id.y + rt->Spec.y );
        //    result1.b = 255  * (ambiant(rt).z + rt->Id.z + rt->Spec.z );
        //}
        result1.r = min(255, max(0, result1.r));
        result1.g = min(255, max(0, result1.g));
        result1.b = min(255, max(0, result1.b));
    }
 

    else
            result1 = black;
    return(result1);

}
