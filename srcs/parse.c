/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 17:46:52 by cjacques         ###   ########.fr       */
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

int			ft_line_ant(t_list *list, char **line, int fd)
{
	int		nb_ants;

	(void)list;
	nb_ants = -1;
	if ((nb_ants = ft_check_int(*line)) == -1 && ft_comment(*line) != 2)
		ft_error(NULL, list);
	else if (nb_ants != -1)
	{
		get_next_line(fd, line);
		return (nb_ants);
	}
	return (nb_ants);
}

int			ft_line_rooms(char **line, t_graph *graph)
{
	(void)graph;
	if (ft_count_char(*line, ' ') != 2 && ft_comment(*line) == 3)
		return (0);
	return (1);
}

int			ft_line_tunnels(t_listelem **elem, t_graph *graph)
{
	char		*line;
	t_listelem	*tmp;
	t_path		*data1;
	t_path		*data2;
	int			len;

	while (*elem != NULL)
	{
		tmp = LIST_HEAD(&graph->adjlists);
		line = LIST_DATA(*elem);
		while (tmp != NULL)
		{
			len = ft_strlen(((t_path*)
						((t_adjlist*)LIST_DATA(tmp))->vertex)->data);
			if (ft_strncmp(line,
						((t_path*)((t_adjlist*)LIST_DATA(tmp))->vertex)->data,
						len) == 0)
			{
				if (line[len] == '-')
				{
					data1 = ft_newpath(ft_strsub(line, 0, len));
					data2 = ft_newpath(ft_strsub(line, len + 1
								, ft_strlen(line) - (len + 1)));
					if (ft_graph_ins_edge(graph, data1, data2) == 0
							&& ft_graph_ins_edge(graph, data2, data1) == 0)
						break ;
				}
			}
			tmp = LIST_NEXT(tmp);
		}
		if (tmp == NULL)
			return (0);
		*elem = LIST_NEXT(*elem);
	}
	return (0);
}

int			ft_parse_file(t_list *list, t_graph *graph)
{
	char			*line;
	int				ant;
	//	t_listelem		*tmp;

	int fd = open("Test", O_RDONLY);
	ft_list_init(list, free);
	get_next_line(fd, &line);
	while ((ant = ft_line_ant(list, &line, fd)) < 0)
	{
		ft_list_ins_next(list, list->tail, line);
		get_next_line(fd, &line);
	}
	while (ft_line_rooms(&line, graph))
	{
		ft_check(list, &line);
		if (ft_check_and_add(graph, list, &line) == 1)
			break ;
		ft_list_ins_next(list, list->tail, line);
		get_next_line(fd, &line);
	}
	while (ft_line_tunnels(&tmp, graph))
	{
		get_next_line(fd, &line);
		ft_list_ins_next(list, list->tail, line);
	}
	return (ant);
}
