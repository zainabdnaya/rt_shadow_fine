/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:54:17 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/03 20:20:11 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main(int argc,char **argv)
{
    t_minirt rt;
    t_mlx    mlx;


    if (argc < 2 || argc > 3)
    {
            error(1);
            exit(1);
    }
    if (ft_compare_end(argv[1], ".rt") != 1)
     {
           error(2);
           exit(1);
     }
    ft_bzero(&rt,sizeof(t_minirt));
     rt.name = argv[1];
     initial_all_objects(&rt);
    parsing_RT(argv[1],&rt);
    rt.mlx.mlx_ptr = mlx_init();
    init_graphics(&rt, &mlx, rt.resol.WIDTH, rt.resol.HEIGHT);
}