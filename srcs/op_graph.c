/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:31:51 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 10:31:57 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void		ft_graph_init(t_graph *graph, int (*ft_match)(void *k1, void *k2)
			, void (*ft_destroy)(void *data))
{
	graph->vcount = 0;
	graph->ecount = 0;
	graph->ft_match = ft_match;
	graph->ft_destroy = ft_destroy;
	ft_list_init(&graph->adjlists, NULL);
}

void		ft_graph_destroy(t_graph *graph)
{
	(void)graph;
}

int			ft_graph_adjlist(t_graph *graph, void *data, t_adjlist **adjlist)
{
	(void)graph;
	(void)data;
	(void)adjlist;
	return (0);
}

int			ft_graph_is_adjacent(t_graph *graph, void *data1, void *data2)
{
	(void)graph;
	(void)data1;
	(void)data2;
	return (0);
}
