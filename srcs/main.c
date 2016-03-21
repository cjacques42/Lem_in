/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 09:00:21 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_list			list;
	t_graph			graph;
	int				nb_ants;
	char			*start;
//	char			*end;

	ft_graph_init(&graph, (int (*)(void*, void*))ft_strcmp, free);
	nb_ants = ft_parse_file(&list, &graph);
	start = ft_search_start(&list);
	ft_putstr(start);
	ft_graph_destroy(&graph);
	ft_list_destroy(&list);
	return (0);
}
