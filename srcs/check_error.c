/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/27 18:40:19 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_free_data_path(t_graph *graph, t_list *list, t_path *path)
{
	ft_free_path(path);
	ft_error(graph, list);
}

int				ft_check_and_add(t_graph *graph, t_list *list, char **line)
{
	char	**data;
	int		i;
	t_path	*path;

	i = 0;
	if (ft_comment(*line) == 3)
	{
		data = ft_strsplit(*line, ' ');
		(data[0][0] == 'L') ? ft_error(graph, list) : 0;
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
				, path = ft_newpath(ft_strdup(data[0]))) != 0)
			ft_free_data_path(graph, list, path);
		ft_free_dcharcom(data);
	}
	return (0);
}
