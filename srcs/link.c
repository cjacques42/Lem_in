/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:19:17 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/09 15:45:49 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_addlink(t_link **begin, t_link *new)
{
	if (*begin == NULL)
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}

t_link	*ft_newlink(int id)
{
	t_link	*tmp;

	tmp = NULL;
	if ((tmp = (t_link*)malloc(sizeof(*tmp))) == NULL)
		ft_error();
	if ((tmp->id = (int*)malloc(sizeof(*(tmp->id)))) == NULL)
		ft_error();
	*(tmp->id) = id;
	tmp->next = NULL;
	return (tmp);
}
