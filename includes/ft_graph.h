/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:03:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 11:04:14 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include <stdlib.h>
# include "ft_list.h"
# include "ft_set.h"

typedef struct		s_adjlist
{
	void	*vertex;
	t_set	adjacent;
}					t_adjlist;

typedef struct		s_graph
{
	int		ecount;
	int		vcount;
	int		(*ft_match)(void *k1, void *k2);
	void	(*ft_destroy)(void *data);
	t_list	adjlists;
}					t_graph;

void		ft_graph_init(t_graph *graph, int (*match)(void *k1, void *k2)
		, void (*destroy)(void *data));
void		ft_graph_destroy(t_graph *graph);
int			ft_graph_ins_vertex(t_graph *graph, void *data);
int			ft_graph_ins_edge(t_graph *graph, void *data1, void *data2);
int			ft_graph_rem_vertex(t_graph *graph, void **data);
int			ft_graph_rem_edge(t_graph *graph, void *data1, void **data2);
int			ft_graph_adjlist(t_graph *graph, void *data, t_adjlist **adjlist);
int			ft_graph_is_adjacent(t_graph *graph, void *data1, void *data2);

# define GRAPH_ADJLISTS(graph)		((graph)->adjlists)
# define GRAPH_VCOUNT(graph)		((graph)->vcount)
# define GRAPH_ECOUNT(graph)		((graph)->ecount)

#endif
