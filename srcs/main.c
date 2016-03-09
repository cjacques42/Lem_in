/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/09 14:54:41 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_node	*nodes;
	t_spec	spec;
	int		val;

	nodes = NULL;
	spec.rooms = NULL;
	spec.tunnels = NULL;
	if ((val = ft_parse_file(&spec)) == 1)
		ft_error();
	else if (val == -1)
		return (1);
	ft_checkdata(&spec);
	ft_stock(&spec, &nodes);
//	ft_dijkstra(graph);
/*	ft_putnbr(spec.ants);
	ft_putchar('\n');
	while (spec.rooms != NULL)
	{
		ft_putstr(spec.rooms->str);
		ft_putstr("\n");
		spec.rooms = spec.rooms->next;
	}
	while (spec.tunnels != NULL)
	{
		ft_putstr(spec.tunnels->str);
		ft_putstr("\n");
		spec.tunnels = spec.tunnels->next;
	}*/
	while (nodes != NULL)
	{
		ft_putnbr(nodes->index);
		ft_putchar(' ');
		ft_putstr(nodes->name);
//		ft_putchar(' ');
//		ft_putnbr(nodes->edges->id);
		ft_putchar('\n');
		nodes = nodes->next;
	}
	ft_datadel(&spec.rooms);
	ft_datadel(&spec.tunnels);
	return (0);
}
