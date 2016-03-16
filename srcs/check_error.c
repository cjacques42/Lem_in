/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 11:14:27 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_check_and_add(t_listelem *start, t_listelem *end, t_graph *graph)
{
	char	*data;

	(void)graph;
	while (start != end)
	{
		data = LIST_DATA(start);
		ft_strchr(data, ' ');
		start = LIST_NEXT(start);
	}
	return (0);
}
