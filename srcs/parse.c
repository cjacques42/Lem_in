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
		if (ft_strcmp(line, "##end") == 0 ||
				 ft_strcmp(line, "##start") == 0)
			return (-1);
		else if (ft_strlen(line) > 2 && line[0] == '#' && line[1] != '#')
			return (1);
		else if (line[0] == '#')
			return (1);
		else
			return (0);
}

int		ft_line_ant(t_list *list, t_listelem **elem)
{
	char	*line;
	int		val;
	int		nb_ants;

	nb_ants = 0;
	while (*elem != NULL)
	{
		line = (*elem)->data;
		if ((val = ft_comment(line)) == 1)
			;
		else if (val  == -1)
		{
			ft_list_destroy(list);
			ft_error();
		}
		else if ((nb_ants = ft_check_int(line)) == -1)
			ft_error();
		else
		{
			*elem = LIST_NEXT(*elem);
			return (nb_ants);
		}
		*elem = LIST_NEXT(*elem);
	}
	return (nb_ants);
}

/*
   int				ft_line_room(t_listelem **list)
   {
   int		index;
   char	*tmp;
   int		j;


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
/*
   int				ft_file(t_list *list, int *nb, t_graph *graph)
   {
   t_listelem		*tmp;

   (void)graph;
   tmp = LIST_HEAD(list);
   while (ft_line_ant(&tmp, nb) == 0)
   {
   tmp = LIST_NEXT(tmp);
   if (tmp == NULL)
   return (-1);
   }
   while (ft_line_room(LIST_DATA(tmp)))
   {
   tmp = LIST_NEXT(tmp);
   if (tmp == NULL)
   return (-1);
   }
   while (ft_line_tunnel(LIST_DATA(tmp)))
   {
   tmp = LIST_NEXT(tmp);
   if (tmp == NULL)
   return (0);
   }
   return (0);
   }*/

int				ft_parse_file(t_list *list, t_graph *graph)
{
	char		*line;
	int			ant;
	t_listelem	*tmp;

	(void)graph;
	ft_list_init(list, free);
	while (get_next_line(0, &line) > 0)
		ft_list_ins_next(list, list->tail, line);
	tmp = LIST_HEAD(list);
	ant = ft_line_ant(list, &tmp);
	if (tmp == NULL)
	{
		ft_list_destroy(list);
		ft_error();
	}
	if (tmp == NULL)
	{
		ft_list_destroy(list);
		ft_error();
	}
	//	ft_line_rooms();
	//	ft_line_tunnels();
	return (ant);
}
