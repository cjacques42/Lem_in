/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:31:51 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/25 09:58:29 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"
#include "libft.h"

static int	ft_search(t_graph *graph, t_listelem **tmp, t_adjlist **ptr
		, void *data)
{
	*tmp = LIST_HEAD(&graph->adjlists);
	while (*tmp != NULL)
	{
		*ptr = LIST_DATA(*tmp);
		if (graph->ft_match(data, (*ptr)->vertex) == 0)
			break ;
		*tmp = LIST_NEXT(*tmp);
	}
	if (*tmp == NULL)
		return (-1);
	return (0);
}

int			ft_graph_ins_edge(t_graph *graph, void *data1, void *data2)
{
	t_listelem		*tmp;
	int				val;
	t_adjlist		*ptr1;
	t_adjlist		*ptr2;

	val = 0;
	if (ft_search(graph, &tmp, &ptr1, data2) == -1)
		return (-1);
	if (ft_search(graph, &tmp, &ptr2, data1) == -1)
		return (-1);
	if ((val = ft_set_insert(&((t_adjlist*)LIST_DATA(tmp))->adjacent
					, ptr1->vertex)) == -1)
		return (val);
	GRAPH_ECOUNT(graph)++;
	return (0);
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
	ft_memset(graph, 0, sizeof(graph));
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
