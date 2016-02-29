/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:30:18 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/29 11:30:55 by cjacques         ###   ########.fr       */
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
	while(str[index])
		index++;
	return (index);
}
