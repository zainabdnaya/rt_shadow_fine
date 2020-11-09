/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:29:00 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/19 20:17:51 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_list *creat_new_node(void  *data)
{
  t_list *new;
  
   if(!( new = malloc(sizeof(t_list))))
      return(NULL);
  new->content = data;
  new->next = NULL;
  return(new);

}
