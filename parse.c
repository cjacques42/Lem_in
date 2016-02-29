/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/29 11:37:49 by cjacques         ###   ########.fr       */
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

int		ft_line_room(int fd, char **line, t_node **nodes)
{
	char		**room;
	t_node		*tmp;
	t_command	status;
	int			st;
	int			end;

	start = 0;
	end = 0;
	while (get_next_line(fd, line) > 0)
	{
		if (ft_comment(*line) == 1)
			continue ;
		room = ft_strsplit(*line, ' ');
		if (ft_nbrstr(room) == 1 && (status = ft_status(room, st, end)) != ROOM)
				continue ;
		if (ft_nbrstr(room) != 3)
			return (0);
		if ((tmp = ft_new_node(room, status)) == NULL)
			return (1);
		ft_add_node(nodes, tmp);
		free(*line);
	}
	return (0);
}

//int		ft_line_tunnel(line)
//{
//}*/

int		ft_file(int fd, t_node **nodes, t_spec *spec)
{
	char	*line;

	if (ft_line_ant(fd, &line, spec) == 1)
		return (1);
	if (ft_line_room(fd, &line, nodes) == 1)
		return (1);
	//	ft_line_tunnel(fd, &line, nodes, spec);
	return (0);
}

int		ft_parse_file(char *name, t_node **nodes, t_spec *spec)
{
	int			fd;

	fd = open(name, O_RDONLY);
	ft_file(fd, nodes, spec);
	close(fd);
	return (0);
}
