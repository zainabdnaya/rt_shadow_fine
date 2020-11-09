/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:46:14 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/03 20:37:39 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int ft_compare_end(char *str, char *end)
{
    int i;
    int j;

    i = ft_strlen(str) - 1;
    j = ft_strlen(end) - 1;
    if (i < j)
        return (0);
    while (str[i] && end[j])
    {
        if (str[i] != end[j])
            return (0);
        j--;
        i--;
    }
    return (1);
}