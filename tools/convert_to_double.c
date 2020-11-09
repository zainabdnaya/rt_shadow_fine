/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:22:19 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/29 11:44:26 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double convert_to_double(char *string)
{
    int sign;
    double decimal;
    int moy;
    double dexieme;
    double dec;

    dec = 0.0;
    moy = 0;
    sign = 1;
    decimal = 0.0;
    dexieme = 10;
    if (string[0] == '-')
        {
            sign = -1;
            string++;
        }
    while (*string>= '0' && *string<= '9')
        moy = moy * 10 + (*(string)++ - '0');
    while (*string == '.')
        (string)++;
    while (*string>= '0' && *string<= '9' && *string != '\0')  
    {
        dec = *string - '0';
            decimal = decimal + dec/ dexieme;
            dexieme *= 10;
            string++;
    }
    decimal +=moy;
    return ((decimal) * sign);
}
