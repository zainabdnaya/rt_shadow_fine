/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:16:23 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/06 10:19:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void add_objects(t_objects **head, t_objects *new_obj)
{
    t_objects *new;

    if (!head || !new_obj)
        return;
    new = *head;
    if (new)
    {
        while (new->next)
            new = new->next;
        new->next = new_obj;
    }
    else
    {
        *head = new_obj;
    }
}

void add_lights(t_list_lights **head, t_list_lights *new_obj)
{
    t_list_lights *new;

    if (!head || !new_obj)
        return;
    new = *head;
    if (new)
    {
        while (new->next)
            new = new->next;
        new->next = new_obj;
    }
    else
    {

        *head = new_obj;
    }
}

void add_camera(t_list_camera **head, t_list_camera *new_obj)
{
    t_list_camera *new;

    if (!head || !new_obj)
        return;
    new = *head;
    if (new)
    {
        while (new->next)
            new = new->next;
        new->next = new_obj;
    }
    else
    {

        *head = new_obj;
    }
}
t_list_lights *copy_light(t_vector position, double ratio, t_color color_light)
{
    t_list_lights *light;

    light = malloc(sizeof(t_list_lights));

    light->position = position;
    light->ratio = ratio;
    light->rgb = color_light;

    light->next = NULL;
    return (light);
}

t_list_camera *copy_camera(t_vector look_from,t_vector look_at,double fov)
{
    t_list_camera  *camera;

    camera = malloc(sizeof(t_list_camera));

    camera->look_from = look_from;
    camera->look_at = look_at;
    camera->fov = fov;

    camera->next = NULL;
    return(camera);
}