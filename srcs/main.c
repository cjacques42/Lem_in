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

void	ft_print_list(t_list *list)
{
	t_listelem	*tmp;

	tmp = LIST_HEAD(list);
	while (tmp != NULL)
	{
		ft_putendl(LIST_DATA(tmp));
		tmp = LIST_NEXT(tmp);
	}
}

int		ft_print(t_path *end)
{
	if (end->parent == NULL)
		return (-1);
	while (end != NULL)
	{
		ft_putendl(end->data);
		end = end->parent;
	}
	return (0);
}

int		main(void)
{
	t_list			list;
	t_graph			graph;
	int				nb_ants;
	t_path			*start;
	t_path			*end;

	ft_graph_init(&graph, (int (*)(void*, void*))ft_vertexcmp
			, (void (*)(void*))ft_free_path);
	nb_ants = ft_parse_file(&list, &graph);
	start = ft_search_room(&graph, &list, "##start");
	ft_dijkstra(&graph, start);
	end = ft_search_room(&graph, &list, "##end");
	if (ft_print(end) == -1)
		ft_error(&graph, &list);
	ft_print_list(&list);


	ft_graph_destroy(&graph);
	ft_list_destroy(&list);
	return (0);
}
