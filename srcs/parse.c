/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/03 14:38:31 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_comment(char *line)
{
	if (ft_strlen(line) > 2  && line[0] == '#' && line[1] != '#')
	{
		free(line);
		return (1);
	}
	return (0);
}

int		ft_line_ant(int fd, char **line, t_spec *spec)
{
	int		nb_ants;

	spec->ants = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_comment(*line) == 1)
			continue ;
		if ((nb_ants = ft_check_int(*line)) == -1)
			return (1);
		spec->ants = nb_ants;
		free(*line);
		return (0);
	}
	return (1);
}

/*int		ft_line_room(int fd, char **line, t_node **nodes)
{
	char		**room;
	t_node		*tmp;
	t_command	status;

	while (get_next_line(fd, line) > 0)
	{
		if (ft_comment(*line) == 1)
			continue ;
		room = ft_strsplit(*line, ' ');
		if (ft_nbrstr(room) == 1 && (status = ft_status(room)) != ROOM)
			continue ;
		if (ft_nbrstr(room) != 3)
			return (0);
		if ((tmp = ft_new_node(room, status)) == NULL)
			return (1);
		ft_add_node(nodes, tmp);
		free(*line);
	}
	return (0);
}*/

int		ft_check_room(char **line, t_node **nodes, int *start, int *end
		, t_command	*status)
{
	int			index;
	char		**room;
	t_node		*tmp;
	int			ret;

	index = 0;
	room = ft_strsplit(*line, ' ');
	index = ft_nbrstr(room);
	if (index == 1)
	{
		if ((ret = ft_status(room, status, start, end)) == 0)
			return (0);
		else if (ret == 1)
			return (1);
	}
	if (index != 3)
		return (1);
	if ((tmp = ft_new_node(room, *status)) == NULL)
		return (1);
	ft_add_node(nodes, tmp);
	*status = ROOM;
	return (0);
}

int		ft_line_room(int fd, char **line, t_node **nodes)
{
	int			start;
	int			end;
	t_command	status;

	status = ROOM;
	start = 0;
	end = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_comment(*line) == 1)
			continue ;
		if (ft_check_room(line, nodes, &start, &end, &status) == 1)
			return (0);
		free(*line);
	}
	return (1);
}

int		ft_check_tunnel(char **room, t_node **nodes, t_spec *spec)
{
	int		i;
	(void)spec;
	i = 0;
	if (ft_search(room[0], nodes) == 0 && ft_search(room[1], nodes) == 0)
	{
		return (1);
	}
	else
		return (0);
}

int		ft_line_tunnel(int fd, char **line, t_node **nodes, t_spec *spec)
{
	char	**room;
	int		index;

	while (get_next_line(fd, line) > 0)
	{
		if (ft_comment(*line) == 1)
			continue ;
		room = ft_strsplit(*line, '-');
		index = ft_nbrstr(room);
		if (index == 2 && ft_check_tunnel(room, nodes, spec) == 1)
		{
			ft_edgeadd(&(spec->tunnels), ft_new_edge(*line));
			ft_add_link(room, nodes, 1, 1);
		}
		else
			return (0);
		free(*line);
	}
	return (0);
}

int		ft_file(int fd, t_node **nodes, t_spec *spec)
{
	char	*line;

	if (ft_line_ant(fd, &line, spec) == 1)
		return (1);
	if (ft_line_room(fd, &line, nodes) == 1)
		return (1);
	ft_line_tunnel(fd, &line, nodes, spec);
	return (0);
}

int		ft_parse_file(char *name, t_node **nodes, t_spec *spec)
{
	int			fd;

	fd = open(name, O_RDONLY);
	if (ft_file(fd, nodes, spec) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
