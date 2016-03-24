/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/24 09:25:54 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_line_ant(t_list *list, char **line, int fd, int *nb_ants)
{
	int		val;

	while (get_next_line(fd, line) > 0)
	{
		ft_list_ins_next(list, LIST_TAIL(list), *line);
		if ((val = ft_comment(*line)) < 2)
			ft_error(NULL, list);
		else if (val == 3 && (*nb_ants = ft_check_int(*line)) > 0)
		{
			if (get_next_line(fd, line) < 1)
				ft_error(NULL, list);
			return (1);
		}
		else
			ft_error(NULL, list);
	}
	ft_error(NULL, list);
	return (-1);
}

int			ft_line_rooms(char **line, t_graph *graph)
{
	(void)graph;
	if (ft_count_char(*line, ' ') != 2 && ft_comment(*line) == 3)
		return (0);
	return (1);
}

void		ft_tunnels(t_listelem **tmp, char **line, t_graph *graph)
{
	int		len;
	t_path	*data1;
	t_path	*data2;
	t_path	*path;

	while (*tmp != NULL)
	{
		path = (t_path*)((t_adjlist*)LIST_DATA(*tmp))->vertex;
		len = ft_strlen(LIST_DATA(path));
		if (ft_strncmp(*line, LIST_DATA(path), len) == 0)
			if (line[0][len] == '-')
			{
				data1 = ft_newpath(ft_strsub(*line, 0, len));
				data2 = ft_newpath(ft_strsub(*line, len + 1
							, ft_strlen(*line) - (len + 1)));
				if (ft_graph_ins_edge(graph, data1, data2) == 0
						&& ft_graph_ins_edge(graph, data2, data1) == 0)
				{
					ft_free_path(data1);
					ft_free_path(data2);
					break ;
				}
			}
		*tmp = LIST_NEXT(*tmp);
	}
}

int			ft_line_tunnels(char **line, t_graph *graph)
{
	int				len;
	t_listelem		*tmp;

	tmp = LIST_HEAD(&graph->adjlists);
	if ((len = ft_comment(*line)) < 2)
		return (0);
	else if (len == 2)
		return (1);
	ft_tunnels(&tmp, line, graph);
	if (tmp == NULL)
		return (0);
	return (1);
}

int			ft_parse_file(t_list *list, t_graph *graph)
{
	char			*line;
	int				nb_ants;
	int				val;

	val = 0;
	ft_list_init(list, free);
	ft_line_ant(list, &line, 0, &nb_ants);
	while (ft_line_rooms(&line, graph))
	{
		val = ft_check(list, &line);
		if (ft_check_and_add(graph, list, &line) == 1)
			break ;
		ft_list_ins_next(list, list->tail, line);
		(get_next_line(0, &line) < 1) ? ft_error(graph, list) : 0;
	}
	(val == 0) ? ft_error(graph, list) : 0;
	while (ft_line_tunnels(&line, graph))
	{
		ft_list_ins_next(list, list->tail, line);
		if (get_next_line(0, &line) < 1)
			break ;
	}
	return (nb_ants);
}
