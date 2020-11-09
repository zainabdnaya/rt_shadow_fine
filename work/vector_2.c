/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:36:24 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/03 15:28:04 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vector vectorCross(t_vector v1, t_vector v2)
{
    t_vector w;

    w.x = v1.y * v2.z - v1.z * v2.y;
    w.y = v1.z * v2.x - v1.x * v2.z;
    w.z = v1.x * v2.y - v1.y * v2.x;
    return (w);
}

double vectorLenght(t_vector v)
{
    double lenght;

    lenght = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
    return (lenght);
}

t_vector vectorNorme(t_vector p)
{
    t_vector norme;
    double lenght;

    lenght = vectorLenght(p);

    norme.x = p.x / lenght;
    norme.y = p.y / lenght;
    norme.z = p.z / lenght;
    return (norme);
}

t_vector produit_Vect(t_vector v1, t_vector v2)
{
    double e1 = v1.y * v2.z - v1.z * v2.y;
    double e2 = v1.z * v2.x - v1.x * v2.z;
    double e3 = v1.x * v2.y - v1.y * v2.x;
    t_vector prod = {e1, e2, e3};
    return (prod);
}


double      distance(t_vector one,t_vector two)
{
    double result;

    result = sqrt((pow((two.x - one.x),2) +pow((two.y - one.y),2)+ pow((two.z - one.z ),2) ));
    return(result);
}