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
	t_adjlist		*adjlist;

	while (LIST_SIZE(&graph->adjlists) > 0)
	{
		if (ft_list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0)
		{
			SET_DESTROY(&adjlist->adjacent);
			if (graph->ft_destroy != NULL)
				graph->ft_destroy(adjlist->vertex);
			free(adjlist);
		}
	}
	ft_list_destroy(&graph->adjlists);
}

int			ft_graph_adjlist(t_graph *graph, void *data, t_adjlist **adjlist)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		if (graph->ft_match(data, ((t_adjlist*)LIST_DATA(tmp))->vertex) == 0)
			break ;
		tmp = LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	*adjlist = LIST_DATA(tmp);
	return (0);
}

int			ft_graph_is_adjacent(t_graph *graph, void *data1, void *data2)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		if (graph->ft_match(data1, ((t_adjlist*)LIST_DATA(tmp))->vertex) == 0)
			break ;
		tmp = LIST_DATA(tmp);
	}
	if (tmp == NULL)
		return (-1);
	return (ft_set_ismember(&((t_adjlist*)LIST_DATA(tmp))->adjacent, data2));
}
