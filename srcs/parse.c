/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 18:41:23 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_comment(char *line)
{
		if (ft_strlen(line) > 2 && line[0] == '#' && line[1] != '#')
			return (1);
		else if (line[0] == '#' && line[1] == '#' && 
				 ft_strcmp(line, "##end") != 0 &&
				 ft_strcmp(line, "##start") != 0)
			return (1);
		else
			return (0);
}

int				ft_line_ant(char **line, t_spec *spec, int *val)
{
	int		nb_ants;

	spec->ants = 0;
	if ((nb_ants = ft_check_int(*line)) == -1)
		ft_error();
	spec->ants = nb_ants;
	(*val)++;
	return (0);
}

/*int				ft_line_room(char **line, t_spec *spec, int *val)
{
	int		index;
	char	*tmp;
	int		j;

	index = 0;
	ft_addback(&(spec->rooms), ft_new_data(*line));
	if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
		return (0);
	tmp = ft_strtok(*line, " ");
	while (tmp != NULL)
	{
		if (index == 0 && tmp[0] != 'L')
			;
		else if (index == 1 || index == 2)
		{
			j = 0;
			while (ft_isdigit(tmp[j]) == 1)
				j++;
			if (tmp[j] != 0)
				return (1);
		}
		else
			break ;
		tmp = ft_strtok(NULL, " ");
		index++;
	}
	if (index == 1 || index == 3)
		(*val) += (index == 1) ? 1 : 0;
	else
		return (1);
	return (0);
}

int				ft_line_tunnel(char **line, t_spec *spec, int *val)
{
	char	*tmp;
	int		index;

	index = 0;
	ft_list_ins_next(spec->tunnels,NULL , ft_new_data(*line));
	tmp = ft_strtok(*line, "-");
	while (tmp != NULL)
	{
		tmp = ft_strtok(NULL, "-");
		index++;
	}
	if (index != 2)
	{
		ft_datadelone(&(spec->tunnels));
		(*val)++;
	}
	return (0);
}*/

int				ft_file(int *val, t_spec *spec, char *line)
{
	int			(*function[3]) (char**, t_spec*, int*);
	int			tmp;
	char		*ptr;

	function[0] = ft_line_ant;
	function[1] = ft_line_room;
	function[2] = ft_line_tunnel;
	tmp = *val;
	if (ft_comment(line) == 1)
		;
	else if ((*function[*val])(&line, spec, val) == 1)
	{
		return (1);
	}
	if (*val == 2 && *val != tmp)
	{
		ft_list_rem_next(spec->rooms, spec->rooms->tail, (void**)&ptr);
		free(ptr);
		(*function[*val])(&line, spec, val);
	}
	if (*val == 3)
		return (0);
	return (0);
}

int				ft_parse_file(t_list *list, t_spec *spec)
{
	char		*line;
	int			val;
	char		*tmp;

	(void)spec;
	val = 0;
	ft_list_init(list, free);
	while (get_next_line(0, &line) > 0)
	{
		ft_list_ins_next(list, list->tail, line);
		tmp = ft_strdup(line);
		ft_file(&val, spec, tmp);
		free(tmp);
	}
	return (0);
}
