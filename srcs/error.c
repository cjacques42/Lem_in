/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:14:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 11:08:53 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(t_graph *graph, t_list *list)
{
	ft_putstr_fd("ERROR\n", 2);
	if (graph != NULL)
		ft_graph_destroy(graph);
	ft_list_destroy(list);
	exit(1);
}
