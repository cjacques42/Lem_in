/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 09:45:25 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

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
	t_list		list;
	char		*tmp;
	ft_list_init(&list, free);
	ft_list_ins_next(&list, NULL, ft_strdup("1"));
	ft_list_ins_next(&list, NULL, ft_strdup("2"));
	ft_list_ins_next(&list, NULL, ft_strdup("3"));
	ft_list_ins_next(&list, NULL, ft_strdup("4"));
	ft_list_rem_next(&list, NULL, (void**)&tmp);
	ft_putstr(tmp);
	ft_putchar('\n');
	while (list.head != NULL)
	{
		printf("%s\n", list.head->data);
		list.head = ft_list_next(list.head);
	}
	return (0);
}
