/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:59:09 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/05 18:46:09 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void build_image(t_minirt *rt,t_vector look_from, t_vector look_at)
{
    int j = 0;

    rt->mlx.draw_x = 0;
    rt->mlx.draw_y = 0;
    //printf("|height ===> %f|\t|width ==> %f|\n", rt->resol.HEIGHT, rt->resol.WIDTH);

    // here is A loop that will draw each pixel each time there is
    // an intersection  with an object it will colore it
    // aplying shadow ..... whereever it require in
    while (rt->mlx.draw_y < (int) rt->resol.HEIGHT)
    {
        rt->mlx.draw_x = 0;
        while (rt->mlx.draw_x < (int) rt->resol.WIDTH)
        {
            config_camera(rt, rt->list_camera->look_from, rt->list_camera->look_at);
            rt->color = ray_Tracing(rt);
            rt->color.r = (int) rt->color.r;
            rt->color.g = (int) rt->color.g;
            rt->color.b = (int) rt->color.b;
            rt->mlx.image[j] = ft_color(rt->color.r, rt->color.g, rt->color.b);
            //write(1, "fuck u where the hell I am\n", 26);
            j++;
            ++rt->mlx.draw_x;
        }
       ++rt->mlx.draw_y;
    }
}

