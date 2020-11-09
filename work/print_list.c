/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:43:14 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 13:23:35 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


void print_list_sphere(t_objects *ip)
{

    while (ip != NULL)
    {
        printf("Radiuds ===>%f\n", ip->radius);
        printf("Center==> %f\n", ip->center.x);
        printf("Center==> %f\n", ip->center.y);
        printf("Center==> %f\n", ip->center.z);
        printf("Color==> %f\n",  ip->color.r);
        printf("Color==> %f\n",  ip->color.g);
        printf("Color==> %f\n",  ip->color.b);
        ip = ip->next;
    }
    printf("\n");
}

void print_list_pal(t_objects *ip)
{

    while (ip != NULL)
    {
        printf("point==> %f\n", ip->point.x);
        printf("point==> %f\n", ip->point.y);
        printf("point==> %f\n", ip->point.z);
        printf("p_norm==> %f\n", ip->p_norm.x);
        printf("p_norm==> %f\n", ip->p_norm.y);
        printf("p_norm==> %f\n", ip->p_norm.z);
        printf("Color==> %f\n",  ip->color.r);
        printf("Color==> %f\n",  ip->color.g);
        printf("Color==> %f\n",  ip->color.b);
        ip = ip->next;
    }
    printf("\n");
}


void print_list_tr(t_objects *ip)
{

    while (ip != NULL)
    {
        printf("point_a==> %f\n", ip->point_a.x);
        printf("point_a==> %f\n", ip->point_a.y);
        printf("point_a==> %f\n", ip->point_a.z);
        printf("point_b==> %f\n", ip->point_b.x);
        printf("point_b==> %f\n", ip->point_b.y);
        printf("point_b==> %f\n", ip->point_b.z);
        printf("point_c==> %f\n", ip->point_c.x);
        printf("point_c==> %f\n", ip->point_c.y);
        printf("point_c==> %f\n", ip->point_c.z);
        printf("Color==> %f\n",  ip->color.r);
        printf("Color==> %f\n",  ip->color.g);
        printf("Color==> %f\n",  ip->color.b);
        ip = ip->next;
    }
    printf("\n");
}


void    print_list(t_minirt *rt,t_objects *ip)
{
    while(ip != NULL)
    {

        if(rt->check == 1)
            {
                write(1, "i am in sphere\n",15);
            }
        if(rt->it_plan == 2)
                write(1, "i am in Plan \n",15);
        if (rt->it_triangle== 3)
                write(1, "i am in Triangle\n",15);
        if (rt->check == 4)
            {
                            write(1, "i am in square\n",15);
              //  rt->result_color = test;
            }
             
         if(rt->it_cylindre == 5)
        {

                write(1, "i am in Cylindre\n",15);
        }
                  ip = ip->next;
    }
    printf("\n");
}


void        print_light(t_list_lights *light)
{

    while(light != NULL)
    {

        printf("light origin ==>%f==>%f==>%f\n", light->position.x, light->position.y, light->position.z);
        printf("light_colors ==>%f\n", light->rgb.r);
        printf("light_colors ==>%f\n", light->rgb.g);
        printf("light_colors ==>%f\n", light->rgb.b);
        printf("light_intensity==>%f\n", light->ratio);
        light = light->next;
    }
}


void        print_light1(t_minirt *rt)
{

    // while(rt->list_light!= NULL)
    // {

        printf("light origin ==>%f==>%f==>%f\n",rt->list_light->position.x, rt->list_light->position.y, rt->list_light->position.z);
        printf("light_colors ==>%f\n", rt->light_rgb.r);
        printf("light_colors ==>%f\n", rt->light_rgb.g);
        printf("light_colors ==>%f\n", rt->light_rgb.b);
        printf("light_intensity==>%f\n", rt->ratio);
    //     rt->list_light = rt->list_light->next;
    // }
}

void print_camera(t_list_camera *camera)
{

    while (camera != NULL)
    {

        printf("camera origin ==>%f==>%f==>%f\n", camera->look_from.x, camera->look_from.y, camera->look_from.z);
        printf("camera_look_at ==>%f\n", camera->look_at.x);
        printf("camera_look_at ==>%f\n", camera->look_at.y);
        printf("camera_look_at ==>%f\n", camera->look_at.z);
        printf("light_intensity==>%f\n", camera->fov);
        camera = camera->next;
    }
}