/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:30:18 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/07 15:56:05 by cjacques         ###   ########.fr       */
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

void			ft_add_link(char **room, t_node **nodes, int r1, int r2)
{
	if ((r1 == 0 && r2 == 0) || *nodes == NULL)
		return ;
	if (r1 != 0)
	{
		r1 = ft_strcmp(room[0], (*nodes)->name);
		if (r1 == 0)
			ft_dataadd(&((*nodes)->edges), ft_new_data(room[1]));
	}
	else if (r2 != 0)
	{
		r2 = ft_strcmp(room[1], (*nodes)->name);
		if (r2 == 0)
			ft_dataadd(&((*nodes)->edges), ft_new_data(room[0]));
	}
	ft_add_link(room, &((*nodes)->next), r1, r2);
}
