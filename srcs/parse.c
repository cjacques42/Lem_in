/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/22 12:12:33 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_comment(char *line)
{
	if (ft_strcmp(line, "##end") == 0)
		return (0);
	else if (ft_strcmp(line, "##start") == 0)
		return (1);
	else if (ft_strlen(line) > 2 && line[0] == '#' && line[1] != '#')
		return (2);
	else if (line[0] == '#')
		return (2);
	else
		return (3);
}

int			ft_line_ant(t_list *list, char **line, int fd, int *nb_ants)
{
	int		val;

	(void)list;
	if ((val = ft_comment(*line)) < 2)
		ft_error(NULL, list);
	else if (val == 2)
		return (0);
	else if ((*nb_ants = ft_check_int(*line)) >= 0)
	{
		get_next_line(fd, line);
		return (1);
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

int			ft_line_tunnels(char **line, t_graph *graph)
{
	int				len;
	t_listelem		*tmp;
	t_path			*data1;
	t_path			*data2;

	tmp = LIST_HEAD(&graph->adjlists);
	if ((len = ft_comment(*line)) < 2)
		return (0);
	else if (len == 2)
		return (1);
	while (tmp != NULL)
	{
		len = ft_strlen(((t_path*)
					((t_adjlist*)LIST_DATA(tmp))->vertex)->data);
		if (ft_strncmp(*line,
					((t_path*)((t_adjlist*)LIST_DATA(tmp))->vertex)->data,
					len) == 0)
		{
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
		}
		tmp = LIST_NEXT(tmp);
	}
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
	get_next_line(0, &line);
	while (ft_line_ant(list, &line, 0, &nb_ants) == 0)
	{
		ft_list_ins_next(list, list->tail, line);
		get_next_line(0, &line);
	}
	while (ft_line_rooms(&line, graph))
	{
		val = ft_check(list, &line);
		if (ft_check_and_add(graph, list, &line) == 1)
			break ;
		ft_list_ins_next(list, list->tail, line);
		get_next_line(0, &line);
	}
	if (val == 0)
		ft_error(graph, list);
	while (ft_line_tunnels(&line, graph))
	{
		ft_list_ins_next(list, list->tail, line);
		get_next_line(0, &line);
	}
	return (nb_ants);
}
