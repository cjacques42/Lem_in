/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/26 16:21:46 by cjacques         ###   ########.fr       */
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
	ft_parse_file(av[1], &nodes, &spec);
//	ft_dijkstra(graph);
	ft_putnbr(spec.ants);
	return (0);
}
