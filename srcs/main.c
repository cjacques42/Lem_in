/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/27 17:57:26 by cjacques         ###   ########.fr       */
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

static void		ft_destroy_multi(t_list *multi, t_path *start, t_path *end)
{
	t_set			*ptr;
	t_listelem		*elem;
	t_path			*path;

	while (LIST_SIZE(multi) > 0)
	{
		ft_list_rem_next(multi, NULL, (void**)&ptr);
		elem = LIST_HEAD(ptr);
		while (LIST_SIZE(ptr) > 0)
		{
			ft_list_rem_next(ptr, NULL, (void**)&path);
			if (path != start && path != end)
				ft_free_path(path);
		}
		free(ptr);
	}
}

static void		ft_putnbrendl(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}

int				main(int ac, char **av)
{
	t_list			list;
	t_graph			graph;
	int				nb_ants;
	t_info			info;
	t_list			multi;

	ft_graph_init(&graph, (int (*)(void*, void*))ft_vertexcmp
			, (void (*)(void*))ft_free_path);
	nb_ants = ft_parse_file(&list, &graph);
	info.start = ft_search_room(&graph, &list, "##start");
	info.end = ft_search_room(&graph, &list, "##end");
	ft_set_init(&multi, (int (*)(void*, void*))ft_vertexcmp
			, (void (*)(void*))ft_free_path);
	ft_dijkstra(&graph, info.start, info.end, &multi);
	(LIST_SIZE(&multi) == 0) ? ft_error(&graph, &list) : 0;
	ft_print_list(&list);
	nb_ants = ft_final_print(info.start, info.end, nb_ants, &multi);
	if (ft_strcmp("-l", av[ac - 1]) == 0)
		ft_putnbrendl(nb_ants);
	ft_destroy_multi(&multi, info.start, info.end);
	ft_list_destroy(&list);
	ft_graph_destroy(&graph);
	return (0);
}
