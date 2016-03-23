/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/23 09:37:46 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void		ft_print_list(t_list *list)
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

int			ft_print(t_path *end)
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

int			ft_ant(t_path *path, int nb_ants)
{
	if (path->parent == NULL)
		return (0);
	ft_ant(path->parent, nb_ants);
	ft_putstr("L1-");
	ft_putendl(path->data);
	return (1);
}

int			main(void)
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
	if (end->parent == NULL)
		ft_error(&graph, &list);
//	ft_print_list(&list);
	ft_print(end);
	ft_ant(end, nb_ants);
	ft_graph_destroy(&graph);
	ft_list_destroy(&list);
	return (0);
}
