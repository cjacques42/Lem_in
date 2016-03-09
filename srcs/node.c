/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:10:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/09 11:58:03 by cjacques         ###   ########.fr       */
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

void		ft_add_node(t_node **begin, t_node *new)
{
	if (*begin == NULL)
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}

void		ft_addback_node(t_node **begin, t_node *new)
{
	if (*begin == NULL)
	{
		*begin = new;
		return ;
	}
	ft_addback_node(&(*begin)->next, new);
}

t_node		*ft_new_node(char **room, int index)
{
	t_node	*tmp;
	int		coord;

	tmp = NULL;
	if ((tmp = (t_node*)malloc(sizeof(*tmp))) == NULL)
		ft_error();
	if ((coord = ft_check_int(room[1])) == -1)
		ft_error();
	tmp->x = coord;
	if ((coord = ft_check_int(room[2])) == -1)
		ft_error();
	tmp->index = index;
	tmp->y = coord;
	tmp->name = ft_strdup(room[0]);
	tmp->next = NULL;
	tmp->back = NULL;
	tmp->weight = -1;
	tmp->walkable = 0;
	tmp->edges = NULL;
	return (tmp);
}
