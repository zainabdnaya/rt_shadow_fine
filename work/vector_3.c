/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:35:49 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/06 14:07:28 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector vectorSplit(char *str)
{
    t_vector w;
    char **split;

    split = ft_split(str, ',');
    if (ft_count(split) != 3 || ft_charCount(str, ',') != 2)
    {
        ft_free_split(split);
        p_error(11);
        exit(1);
    }
    w.x = convert_to_double(split[0]);
    w.y = convert_to_double(split[1]);
    w.z = convert_to_double(split[2]);
    ft_free_split(split);
    return (w);
}

t_color  org(t_color r)
{
      t_color  result = {r.r / 255, r.g / 255, r.b / 255};
      return (result);
}


void        initial_all_objects(t_minirt *rt)
{
        rt->it_cylindre = 0;
        rt->it_plan = 0;
        rt->it_sphere = 0;
        rt->it_square = 0;
        rt->it_triangle = 0;
}