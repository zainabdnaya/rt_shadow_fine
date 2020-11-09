/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:21:25 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/06 19:07:18 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	*ft_calloc(size_t count, size_t size)
{
	int				i;
	char			*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = (size * count) - 1;
	while (i >= 0)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}
