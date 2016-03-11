/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/11 12:57:48 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_node	*nodes;
	t_spec	spec;
	t_set	*list;
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
	/*ft_dijkstra(&nodes, &spec, &nodes->next->next->next
			, &nodes->next);
	while (nodes != NULL)
	{
		printf("id: %d name: %s edge: %d \n", nodes->index, nodes->name,
				nodes->edges->id);
		if (nodes->edges->next != NULL)
			ft_putnbr(nodes->edges->next->id);
		ft_putchar('\n');
		nodes = nodes->next;
	}*/
//	ft_error();
	ft_setadd(&list, ft_setnew(ft_strdup("0\0")));
	ft_setadd(&list, ft_setnew(ft_strdup("1\0")));
	ft_setadd(&list, ft_setnew(ft_strdup("2\0")));
	ft_setdestroy(&list);
	ft_datadel(&spec.rooms);
	ft_datadel(&spec.tunnels);
	return (0);
}
