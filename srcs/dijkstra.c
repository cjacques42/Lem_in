/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 11:35:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/10 18:18:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_dijkstra(t_node **nodes, t_spec *spec, t_node **start, t_node ** end)
{
	t_list	*openl;
	t_list	*closel;
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	openl = NULL;
	closel = NULL;
//	ft_putstr((*start)->name);
//	ft_putchar('\n');
//	ft_putstr((*end)->name);
//	ft_putchar('\n');
	(*start)->weight = 0;
	(*start)->walkable = 1;
	while (i < 4)
	{
		while ((*start) != NULL)
		{
			ft_addlink(&openl, ft_newlink(tmp->index));
			(*start) = (*start)->next;
		}
	}
	 return (0);
}
