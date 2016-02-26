/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/26 16:22:31 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_line_ant(char *line, t_spec *spec)
{
	int		nb_ants;

	spec->ants = 0;
	if ((nb_ants = ft_check_int(line)) == -1)
		return (1);
	spec->ants = nb_ants;
	return (0);
}

int		ft_line_room(char *line, t_node **nodes)
{
	char	**one;
	int		index;

	index = 0;
	one = ft_strsplit(line, ' ');
	while ()
	return (0);	
}

//int		ft_line_tunnel(line)
//{
//}

int		ft_file(int fd, t_node **nodes, t_spec *spec)
{
	char	*line;
	int		ant;
	int		room;
	int		tunnel;
	(void)nodes;
	ant = 0;
	room = 0;
	tunnel = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) > 2  && line[0] == '#' && line[1] != '#')
		{
			free(line);
			continue ;
		}
		if (ant == 0 && ft_line_ant(line, spec) == 0)
			ant++;
		if (ant != 0 && ft_line_room(line, nodes) == 0)
			room++;
		if (ft_line_tunnel(line, nodes, spec))
			tunnel++;
		free(line);
	}
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
