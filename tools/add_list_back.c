/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:14:20 by zdnaya            #+#    #+#             */
/*   Updated: 2020/10/19 20:22:54 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void add_list_back(t_list *(*head), t_list *last)
{
    t_list *tmp;

    if (!head || !last)
        return;
    if (*head)
    {
        tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = last;
    }
    else
        *head = last;
}