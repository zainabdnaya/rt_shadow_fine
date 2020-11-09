/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:53:42 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/06 19:06:03 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int		words(char *str, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] && str[i] != c)
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (j);
}

static void		*leak(char **spl, int j)
{
	j = j - 1;
	while (spl[j])
	{
		free(spl[j]);
		j--;
	}
	free(spl);
	return (NULL);
}

static int		carcts(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char		*alloc(char **tab, char *src, char c)
{
	int			i;
	int			j;
	int			o;

	j = 0;
	o = 0;
	while (src[o] == c)
		o++;
	while (j < words(src, c))
	{
		i = 0;
		if (!(tab[j] = malloc(sizeof(char) * (carcts(&src[o], c) + 1))))
			return (leak(tab, j));
		while (src[o] != c && src[o])
			tab[j][i++] = src[o++];
		tab[j][i] = '\0';
		while (src[o] == c && src[o])
			o++;
		j++;
	}
	tab[j] = NULL;
	return (*tab);
}

char			**ft_split(char  *s, char c)
{
	int			i;
	int			j;
	int			o;
	char		**tab;
	char		*str;

	o = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (words(str, c) + 1));
	if (!tab)
		return (NULL);
	tab[j] = alloc(tab, str, c);
	return (tab);
}