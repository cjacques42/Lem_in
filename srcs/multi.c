/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:57:25 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/25 10:03:23 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_destroy(t_list *list)
{
	void	*data;

	if (LIST_SIZE(list) == 0)
	{
		ft_memset(list, 0, sizeof(list));
		return ;
	}
	ft_list_rem_next(list, NULL, &data);
	ft_list_destroy(list);
}

static void		ft_rem_last_edge(t_graph *graph, t_path **data)
{
	t_listelem	*elem;
	t_set		*set;
	t_path		*path;

	elem = LIST_HEAD(&graph->adjlists);
	while (elem != NULL)
	{
		path = ((t_adjlist*)LIST_DATA(elem))->vertex;
		set = &((t_adjlist*)LIST_DATA(elem))->adjacent;
		ft_set_remove(set, (void**)data);
		elem = LIST_NEXT(elem);
	}
}

void			ft_rem_shortpath(t_graph *graph, t_path *start, t_path *end)
{
	t_path			*tmp;
	t_listelem		*ptr;
	t_set			*set;
	int				val;

	start->parent = NULL;
	tmp = end->parent;
	while (tmp != start)
	{
		ptr = LIST_HEAD(&graph->adjlists);
		while (ptr != NULL)
		{
			if (graph->ft_match(tmp, ((t_adjlist*)LIST_DATA(ptr))->vertex) == 0)
				break ;
			ptr = LIST_NEXT(ptr);
		}
		set = &((t_adjlist*)LIST_DATA(ptr))->adjacent;
		val = LIST_SIZE(set);
		ft_rem_last_edge(graph, &tmp);
		ft_destroy(set);
		ft_graph_rem_vertex(graph, (void**)&tmp);
		ft_free_path(tmp);
		GRAPH_ECOUNT(graph) -= val;
		tmp = tmp->parent;
	}
}
