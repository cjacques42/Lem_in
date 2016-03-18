/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:31:42 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/17 15:17:18 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include "libft.h"

void		ft_graph_init(t_graph *graph, int (*ft_match)(void *k1, void *k2)
			, void (*ft_destroy)(void *data))
{
	graph->vcount = 0;
	graph->ecount = 0;
	graph->ft_match = ft_match;
	graph->ft_destroy = ft_destroy;
	ft_list_init(&graph->adjlists, NULL);
}

int			ft_graph_ins_vertex(t_graph *graph, void *data)
{
	t_adjlist		*adjlist;
	t_listelem		*element;
	int				retval;

	element = LIST_HEAD(&graph->adjlists);
	while (element != NULL)
	{
		if (graph->ft_match(data
				, ((t_adjlist*)LIST_DATA(element))->vertex) == 0)
			return 1;
		element = LIST_NEXT(element);
	}
	if ((adjlist = (t_adjlist*)malloc(sizeof(adjlist))) == NULL)
		return -1;
//	ft_set_init(&adjlist->adjacent, graph->ft_match, NULL);
	adjlist->vertex = (void *)data;
	if ((retval = ft_list_ins_next(&graph->adjlists
			, LIST_TAIL(&graph->adjlists), adjlist)) != 0)
		return retval;
	GRAPH_VCOUNT(graph)++;
	return 0;
}

int			ft_graph_ins_edge(t_graph *graph, void *data1, void *data2)
{
	t_listelem		*tmp;
	int				val;

	val = 0;
	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		if (graph->ft_match(data2, ((t_adjlist*)LIST_DATA(tmp))->vertex) == 0)
			break ;
		tmp = LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		if (graph->ft_match(data1, ((t_adjlist*)LIST_DATA(tmp))->vertex) ==  0)
			break ;
		tmp = LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	if ((val = ft_set_insert(&((t_adjlist*)LIST_DATA(tmp))->adjacent
					, data2)) != 0)
		return (val);
	GRAPH_ECOUNT(graph)++;
	return (0);
}

int			ft_graph_rem_vertex(t_graph *graph, void **data)
{
	t_listelem		*tmp;
	t_listelem		*ptr;
	t_listelem		*prec;
	int				val;
	t_adjlist		*adjlist;

	val = 0;
	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		if (ft_set_ismember(&((t_adjlist*)LIST_DATA(tmp))->adjacent
					, *data) == 1)
			return (-1);
		if (graph->ft_match(*data, ((t_adjlist*)LIST_DATA(tmp))->vertex) == 0)
		{
			ptr = tmp;
			val = 1;
		}
		if (val == 0)
			prec = tmp;
		tmp = LIST_NEXT(tmp);
	}
	if (val == 0 || LIST_SIZE(&((t_adjlist*)LIST_DATA(tmp))->adjacent) > 0)
		return (-1);
	if (ft_list_rem_next(&graph->adjlists, prec, (void**)&adjlist) != 0)
		return (-1);
	*data = adjlist->vertex;
	free(adjlist);
	GRAPH_VCOUNT(graph)--;
	return (0);
}

int			ft_graph_rem_edge(t_graph *graph, void *data1, void **data2)
{
	(void)graph;
	(void)data1;
	(void)data2;
	return (0);
}
