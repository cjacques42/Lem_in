/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:36:00 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 14:17:15 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_start(t_graph *graph, t_path *start)
{
	t_listelem		*tmp;
	t_path			*path;
	int				found;

	found = 0;
	tmp = LIST_HEAD(&GRAPH_ADJLISTS(graph));
	while (tmp != NULL)
	{
		path = LIST_DATA(tmp);
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

/*TANT-QUE NON f.vide() FAIRE
  s = f.defiler();
  afficher(s);
  POUR-TOUT voisin t de s dans G FAIRE
  SI t non marqué FAIRE
  f.enfiler(t);
  marquer(t);
  FIN SI
  FIN POUR-TOUT*/

int		ft_dijkstra(t_graph *graph, t_path *start)
{
//	t_list			file;
//	t_listelem		*tmp;
//	t_path			*path;
//	t_adjlist		*adjlist;
//	int				index;

	ft_start(graph, start);
/*	ft_list_ins_next(&file, LIST_TAIL(&file), LIST_DATA(start));
	start->mark = 1;
	while (LIST_SIZE(&file) > 0)
	{
		ft_list_rem_next(&file, NULL, (void**)&path);
		ft_graph_adjlist(graph, path, &adjlist);
//		while (adjlist != NULL)
//		{
//			
//		}
		break ;
	}*/
	return (0);
}
