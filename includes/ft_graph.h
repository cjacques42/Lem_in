/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:03:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 17:51:45 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

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

#endif
