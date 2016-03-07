/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:10:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/04 16:19:04 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_status(char **room, t_command *status, int *start, int *end)
{
	if (ft_strcmp(room[0], "##start") == 0)
	{
		if (*start == 1)
			return (1);
		*status = START;
		(*start)++;
		return (0);
	}
	else if (ft_strcmp(room[0], "##end") == 0)
	{
		if (*end == 1)
			return (1);
		*status = END;
		(*end)++;
		return (0);
	}
	return (1);
}

void		ft_add_node(t_node **begin, t_node *tmp)
{
	if (*begin == NULL)
		*begin = tmp;
	else
	{
		tmp->next = *begin;
		*begin = tmp;
	}
}

t_node		*ft_new_node(char **room, t_command status)
{
	t_node	*tmp;
	int		coord;

	tmp = NULL;
	if ((tmp = (t_node*)malloc(sizeof(*tmp))) == NULL)
		return (NULL);
	if ((coord = ft_check_int(room[1])) == -1)
		return (NULL);
	tmp->x = coord;
	if ((coord = ft_check_int(room[2])) == -1)
		return (NULL);
	tmp->y = coord;
	tmp->name = ft_strdup(room[0]);
	if (tmp->name[0] == 'L')
		return (NULL);
	tmp->status = status;
	tmp->next = NULL;
	tmp->back = NULL;
	if (status == START)
		tmp->weight = 0;
	else
		tmp->weight = -1;
	tmp->parse = 0;
	tmp->edges = NULL;
	return (tmp);
}