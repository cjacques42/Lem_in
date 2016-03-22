/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 12:00:30 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_list			list;
	t_graph			graph;
//	t_listelem		*tmp;
	int				nb_ants;
	t_path			*start;

	ft_graph_init(&graph, (int (*)(void*, void*))ft_vertexcmp
			, (void (*)(void*))ft_free_path);
	nb_ants = ft_parse_file(&list, &graph);
	start = ft_search_start(&graph, &list);
	ft_dijkstra(&graph, start);
/*	ft_putstr("\n");
	ft_putnbr(GRAPH_VCOUNT(&graph));
	ft_putstr(" ");
	ft_putnbr(GRAPH_ECOUNT(&graph));
	ft_putstr("\n");*/
//	tmp = LIST_HEAD(&list);
//	while (tmp != NULL)
//	{
//		ft_putstr(tmp->data);
//		ft_putstr("\n");
//		tmp = LIST_NEXT(tmp);
//	}
//	ft_graph_destroy(&graph);
//	ft_list_destroy(&list);
	return (0);
}
