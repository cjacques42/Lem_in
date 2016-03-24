/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:36:00 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/23 16:44:33 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_start(t_graph *graph, t_path *start)
{
	t_listelem		*tmp;
	t_adjlist		*adjlist;
	t_path			*path;
	int				found;

	found = 0;
	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		adjlist = LIST_DATA(tmp);
		path = adjlist->vertex;
		if (path == start)
		{
			path->weight = 0;
			found = 1;
		}
		else
			path->weight = INT_MAX;
		path->mark = 0;
		path->parent = NULL;
		tmp = LIST_NEXT(tmp);
	}
	if (found == 0)
		return (-1);
	return (0);
}

void	ft_weight(t_graph *graph, t_list *file)
{
	t_listelem		*tmp;
	t_path			*other;
	t_adjlist		*adjlist;
	t_path			*path;

	ft_list_rem_next(file, NULL, (void**)&path);
	ft_graph_adjlist(graph, path, &adjlist);
	tmp = LIST_HEAD(&adjlist->adjacent);
	while (tmp != NULL)
	{
		other = LIST_DATA(tmp);
		if (other->mark == 0)
		{
			ft_list_ins_next(file, LIST_TAIL(file), other);
			other->weight = path->weight + 1;
			other->parent = path;
			other->mark = 1;
		}
		tmp = LIST_NEXT(tmp);
	}
}

int		ft_dijkstra(t_graph *graph, t_path *start)
{
	t_list			file;

	ft_start(graph, start);
	ft_list_init(&file, free);
	ft_list_ins_next(&file, LIST_TAIL(&file), start);
	start->mark = 1;
	while (LIST_SIZE(&file) > 0)
		ft_weight(graph, &file);
	return (0);
}
