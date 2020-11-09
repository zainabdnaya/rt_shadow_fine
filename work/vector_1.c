/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:06:57 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/22 11:43:13 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector vectorAdd(t_vector v1, t_vector v2)
{
    t_vector w;

    w.x = v1.x + v2.x;
    w.y = v1.y + v2.y;
    w.z = v1.z + v2.z;
    return (w);
}

t_vector vectorSub(t_vector v1, t_vector v2)
{
    t_vector w;

    w.x = v1.x - v2.x;
    w.y = v1.y - v2.y;
    w.z = v1.z - v2.z;
    return (w);
}

t_vector vectorScale(t_vector v1, double m)
{
    t_vector w;

    w.x = v1.x * m;
    w.y = v1.y * m;
    w.z = v1.z * m;
    return (w);
}

t_vector vectorDiv(t_vector v1, double d)
{
    t_vector w;

    w.x = v1.x / d;
    w.y = v1.y / d;
    w.z = v1.z / d;
    return (w);
}

double vectorDot(t_vector v1, t_vector v2)
{
    double m;

    m = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return (m);
}