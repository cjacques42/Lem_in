/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/24 12:29:48 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_print_list(t_list *list)
{
	t_listelem	*tmp;

	tmp = LIST_HEAD(list);
	while (tmp != NULL)
	{
		ft_putendl(LIST_DATA(tmp));
		tmp = LIST_NEXT(tmp);
	}
	ft_putchar('\n');
}

static void		ft_rem_shortpath(t_path *start, t_path *end)
{
	t_path	*tmp;

	start->parent = NULL;
	tmp = end->parent;
	while (tmp != start)
	{
		
	}
}

int				main(void)
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
	end = ft_search_room(&graph, &list, "##end");
	while (end->parent != NULL)
	{
		ft_dijkstra(&graph, start);
		ft_final_print(start, end, nb_ants);
		ft_rem_shortpath(start, end);
	}
	ft_print_list(&list);
	ft_list_destroy(&list);
	ft_graph_destroy(&graph);
	return (0);
}
