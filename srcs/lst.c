/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:05:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/02 14:43:18 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_edgeadd(t_edge **begin, t_edge *new)
{
	t_edge	*tmp;

	tmp = NULL;
	tmp = *begin;
	*begin = new;
	(*begin)->next = tmp;
}

t_edge	*ft_new_edge(char *line)
{
	t_edge	*elem;

	elem = (t_edge*)malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->link = ft_strdup(line);
	elem->next = NULL;
	return (elem);
}
