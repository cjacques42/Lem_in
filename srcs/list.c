/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:57:01 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/11 15:12:58 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_setadd(t_set **begin, t_set *new)
{
	t_set  *tmp;

	tmp = NULL;
	tmp = *begin;
	*begin = new;
	(*begin)->next = tmp;
}

void    ft_setaddback(t_set **begin, t_set *new)
{
	if ((*begin) == NULL)
	{
		(*begin) = new;
		return ;
	}
	ft_setaddback(&(*begin)->next, new);
}

void    ft_setdestroyone(t_set **begin)
{
	if ((*begin)->next == NULL)
	{
		free((*begin)->data);
		free(*begin);
		*begin = NULL;
		return ;
	}
	ft_setdestroyone(&(*begin)->next);
}

void    ft_setdestroy(t_set **begin)
{
	if ((*begin) == NULL)
		return ;
	ft_setdestroy(&(*begin)->next);
	free((*begin)->data);
	free(*begin);
	(*begin) = NULL;
}

t_set  *ft_setnew(void *data)
{
	t_set  *elem;

	elem = (t_set*)malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
