/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/25 12:46:27 by cjacques         ###   ########.fr       */
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

static void		ft_destroy_multi(t_list *multi, t_path *start)
{
/*	t_listelem	*tmp;
	t_set	*ptr;
	t_listelem	*elem;
	t_path		*path;

	(void)start;
	tmp = LIST_HEAD(multi);
	while (tmp != NULL)
	{
		ptr = LIST_DATA(tmp);
		ft_putnbr(LIST_SIZE(ptr));
		ft_putstr("\n");
		elem = LIST_HEAD(ptr);
		while (elem != NULL)
		{
			path = LIST_DATA(elem);
			ft_putendl(path->data);
			elem = LIST_NEXT(elem);
		}
		tmp = LIST_NEXT(tmp);
	}*/
//	t_listelem	*tmp;
	t_set	*ptr;
//	t_listelem	*elem;
//	t_path		*path;
	(void)start;
	while (LIST_SIZE(multi) > 0)
	{
		ft_putstr("!");
//		tmp = LIST_HEAD(multi);
//		ptr = LIST_DATA(tmp);
//		elem = LIST_HEAD(ptr);
		ft_list_rem_next(multi, NULL, (void**)&ptr);
//		if (path != start)
//				ft_free_path(path);
	}
}

int				main(void)
{
	t_list			list;
	t_graph			graph;
	int				nb_ants;
	t_path			*start;
	t_path			*end;
	t_list			multi;

	ft_graph_init(&graph, (int (*)(void*, void*))ft_vertexcmp
			, (void (*)(void*))ft_free_path);
	nb_ants = ft_parse_file(&list, &graph);
	start = ft_search_room(&graph, &list, "##start");
	end = ft_search_room(&graph, &list, "##end");
	ft_set_init(&multi, (int (*)(void*, void*))ft_vertexcmp
			, (void (*)(void*))ft_free_path);
	ft_dijkstra(&graph, start, end, &multi);
	ft_putstr("!");
	ft_putnbr(LIST_SIZE(&multi));
	ft_putstr("!");
	if (LIST_SIZE(&multi) == 0)
		ft_error(&graph, &list);
	ft_print_list(&list);
/*	while (end->parent != NULL)
	{
		ft_final_print(start, end, nb_ants);
		ft_rem_shortpath(&graph, start, end);
		ft_dijkstra(&graph, start, end, &multi);
	}*/
	ft_destroy_multi(&multi, start);
	ft_list_destroy(&list);
	ft_graph_destroy(&graph);
	return (0);
}
