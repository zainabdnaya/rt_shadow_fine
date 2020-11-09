/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:01:54 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/06 19:31:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

unsigned int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}