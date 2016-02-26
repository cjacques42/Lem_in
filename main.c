/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/26 17:52:22 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_node	*nodes;
	t_spec	spec;

	nodes = NULL;
//	int		graph[4][4] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};
	if (ac != 2)
		return (ft_error());
	if (ft_parse_file(av[1], &nodes, &spec) == 1)
		return (ft_error());
//	ft_dijkstra(graph);
	ft_putnbr(spec.ants);
	while (nodes != NULL)
	{
		ft_putstr(nodes->name);
		nodes = nodes->next;
	}
	return (0);
}
