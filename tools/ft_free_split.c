/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:12:53 by mac               #+#    #+#             */
/*   Updated: 2020/10/03 20:37:48 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char                 **ft_free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		ft_stringdel(&(split[i]));
		i++;
	}
	free(*split);
	*split = NULL;
	return(split);
}