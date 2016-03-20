/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/17 15:50:18 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_and_add(t_listelem **start, t_listelem **end, t_graph *graph
		, t_list *list)
{
	char	*line;
	char	**data;
	int		i;

	(void)graph;
	i = 0;
	while (*start != *end)
	{
		line = LIST_DATA(*start);
		if (ft_comment(line) == 3)
		{
			data = ft_strsplit(line, ' ');
			if (data[0][0] == 'L')
				ft_error(graph, list);
			while (data[i] != NULL)
				i++;
			if (i != 3)
			{
				*end = *start;
				ft_free_dcharcom(data);
				return (0);
			}
			if (ft_check_int(data[1]) == -1 || ft_check_int(data[2]) == -1)
				ft_error(graph, list);
			if (ft_graph_ins_vertex(graph, ft_strdup(data[0])) != 0)
				ft_error(graph, list);
			ft_free_dcharcom(data);
		}
		*start = LIST_NEXT(*start);
	}
	return (0);
}
