/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 15:03:11 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_list			list;
	t_listelem		*tmp;
	int				nb_ants;
	t_graph			graph;

	nb_ants = ft_parse_file(&list, &graph);
	tmp = LIST_HEAD(&list);
	while (tmp != NULL)
	{
		printf("%s\n", LIST_DATA(tmp));
		tmp = LIST_NEXT(tmp);
	}
	ft_putnbr(nb_ants);
	ft_putchar('\n');
	ft_putnbr(list.size);
	ft_list_destroy(&list);
	return (0);
}
