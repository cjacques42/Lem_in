/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:30:18 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 14:34:57 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_nbr(char c, int total)
{
	int		tmp;

	tmp = total * 10;
	if (c - '0' > INT_MAX - tmp)
		return (0);
	return (1);
}

int				ft_search(char *str, t_node **nodes)
{
	if ((*nodes)->next != NULL)
		return (0);
	if (ft_strcmp(str, (*nodes)->name) == 0)
		return (1);
	(*nodes) = (*nodes)->next;
	return (ft_search(str, nodes));
}

int				ft_check_int(char *str)
{
	size_t	i;
	int		neg;
	int		total;

	total = 0;
	neg = 1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_nbr(str[i], total) == 0)
			return (-1);
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		return (-1);
	return (total);
}

int		ft_nbrstr(char **str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

/*void	ft_link(char **room, t_node **nodes)
{
	int			index;
	t_node		*tmp;
	t_node		*ptr;

	tmp = *nodes;
	ptr = *nodes;
	while (tmp != NULL)
	{
		if (ft_strcmp(room[0], tmp->name) == 0)
		{
			index = tmp->index;
			while (ft_strcmp(room[1], ptr->name) != 0)
				ptr = ptr->next;
			ft_addlink(&ptr->edges, ft_newlink(index));
			ft_addlink(&tmp->edges, ft_newlink(ptr->index));
			break ;
		}
		tmp = tmp->next;
	}
}*/
