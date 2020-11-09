/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:05:29 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 09:46:23 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void resolution_parsing(t_minirt *rt)
{
    int count;

    // if (!(resol_check(rt->pars.splitrest[1])) || !(resol_check(rt->pars.splitrest[2])) )
    //     {
    //         error(0.1);
    //         exit(1);
    //     }
    count = ft_count(rt->pars.splitrest);
    if (count != 3)
       {
           error(8);
           exit(1);
       } 
    rt->resol.WIDTH = ft_atoi(rt->pars.splitrest[1]);
    rt->resol.HEIGHT = ft_atoi(rt->pars.splitrest[2]);
    if ((rt->resol.WIDTH < 1) || (  rt->resol.HEIGHT < 1))
        {
            error(7);
            exit(1);
        }
    rt->resol.WIDTH > 2560 ? rt->resol.WIDTH = 2560 : 0;
    rt->resol.HEIGHT > 1395 ? rt->resol.HEIGHT = 1395 : 0;
}

void camera_parsing(t_minirt *rt)
{
    t_camera *camera;
    int result;

    result = ft_count(rt->pars.splitrest);
    if (!(camera = malloc(sizeof(t_camera))))
        {
            p_error(13);
            exit(1);
        }
    if (result != 4)
    {
        free(camera);
        p_error(10);
        exit(1);
    }
    camera->look_from = vectorSplit(rt->pars.splitrest[1]);
    camera->look_at = vectorSplit(rt->pars.splitrest[2]);
    if ((camera->look_at.x > 1 || camera->look_at.x < -1) || (camera->look_at.y > 1 || camera->look_at.y < -1) || (camera->look_at.z > 1 || camera->look_at.z < -1))
    {
        obj_error(24);
        exit(1);
    }
    camera->fov = ft_atoi(rt->pars.splitrest[3]);
    if(camera->fov < 0 || camera->fov > 180)
    {
        error(7);
        exit(1);
    }
    add_camera(&rt->list_camera,copy_camera(camera->look_from,camera->look_at,camera->fov));
    free(camera);
}

void ambient_parsing(t_minirt *rt)
{
    if (ft_count(rt->pars.splitrest) != 3)
       {
           p_error(16);
           exit(1);
       }
    rt->ambient.ratio = convert_to_double(rt->pars.splitrest[1]);
    rt->ambient.color = colorSplit(rt, rt->pars.splitrest[2]);
    if (rt->ambient.ratio > 1 || rt->ambient.ratio < 0)
        {
            p_error(17);
            exit(1);
        }
}

void light_parsing(t_minirt *rt)
{
    t_light *light;

    if (!(light = malloc(sizeof(t_light))))
       {
           free(light);
           p_error(13);
           exit(1);
       } 
    if (ft_count(rt->pars.splitrest) != 4)
    {
        free(light);
        p_error(15);
        exit(1);
    }
    light->position = vectorSplit(rt->pars.splitrest[1]);
    light->ratio = convert_to_double(rt->pars.splitrest[2]);
    light->rgb = colorSplit(rt, rt->pars.splitrest[3]);
    if (light->ratio > 1 || light->ratio < 0)
        {
            p_error(20);
            exit(1);
        }
    add_lights(&rt->list_light,copy_light(light->position,light->ratio,light->rgb));
    free(light);
}
