/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/17 15:50:09 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_list			list;
	t_listelem		*tmp;
	t_graph			graph;
	int				nb_ants;

	ft_graph_init(&graph, (int (*)(void*, void*))ft_strcmp, free);
	nb_ants = ft_parse_file(&list, &graph);
	tmp = LIST_HEAD(&list);
/*	while (tmp != NULL)
	{
		printf("%s\n", LIST_DATA(tmp));
		tmp = LIST_NEXT(tmp);
	}
	ft_putnbr(nb_ants);
	ft_putchar('\n');
	ft_putnbr(list.size);*/
//	ft_putstr("\n!!");
//	ft_graph_ins_vertex(&graph, ft_strdup("mercredi"));
//	ft_graph_ins_vertex(&graph, ft_strdup("jeudi"));
//	ft_graph_ins_vertex(&graph, ft_strdup("vendredi"));
//	ft_graph_ins_vertex(&graph, ft_strdup("samedi"));
//	ft_graph_ins_vertex(&graph, ft_strdup("dimanche"));
	ft_putstr("!!");
	ft_putnbr(GRAPH_VCOUNT(&graph));
	ft_putstr("!!");
	ft_putnbr(GRAPH_ECOUNT(&graph));
	ft_putstr("!!\n");
//	ft_putstr(((t_adjlist*)LIST_DATA(LIST_HEAD(&GRAPH_ADJLISTS(&graph))))->vertex);
//	ft_list_destroy(&list);
	return (0);
}
