/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/22 18:24:07 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_and_add(t_graph *graph, t_list *list, char **line)
{
	char	**data;
	int		i;

	i = 0;
	if (ft_comment(*line) == 3)
	{
		data = ft_strsplit(*line, ' ');
		if (data[0][0] == 'L')
			ft_error(graph, list);
		while (data[i] != NULL)
			i++;
		if (i != 3)
		{
			ft_free_dcharcom(data);
			return (1);
		}
		ft_check_int(data[1]);
		ft_check_int(data[2]);
		if (ft_graph_ins_vertex(graph
					, ft_newpath(ft_strdup(data[0]))) != 0)
			ft_error(graph, list);
		ft_free_dcharcom(data);
	}
	return (0);
}
