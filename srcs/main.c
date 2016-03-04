/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/04 13:03:51 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_node	*nodes;
	t_spec	spec;

	nodes = NULL;
	spec.tunnels = NULL;
	if (ac != 2)
		return (ft_error());
	if (ft_parse_file(av[1], &nodes, &spec) == 1)
		return (ft_error());
//	ft_dijkstra(graph);
//	ft_putnbr(spec.ants);
/*	while (nodes != NULL)
	{
		ft_putstr(nodes->name);
		ft_putchar(' ');
		ft_putnbr(nodes->x);
		ft_putchar(' ');
		if (nodes->status == END)
			ft_putchar('E');
		if (nodes->status == START)
			ft_putchar('S');
		if (nodes->status == ROOM)
			ft_putchar('R');
		ft_putchar(' ');
		ft_putnbr(nodes->x);
		ft_putchar('\n');
		while (nodes->edges != NULL)
		{
			ft_putstr(nodes->edges->str);
			ft_putstr("->");
			nodes->edges = nodes->edges->next;
		}
		ft_putstr("\n");
		nodes = nodes->next;
	}*/
	while (spec.rooms != NULL)
	{
		ft_putstr(spec.rooms->str);
		ft_putstr("\n");
		spec.rooms = spec.rooms->next;
	}
	return (0);
}
