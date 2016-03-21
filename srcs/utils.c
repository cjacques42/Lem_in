/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 09:09:37 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 09:17:33 by cjacques         ###   ########.fr       */
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

int				ft_count_char(char *str, char c)
{
	int		nbr;
	int		index;

	nbr = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			nbr++;
		if (str[0] == c)
			return (-1);
		index++;
	}
	return (nbr);
}

int				ft_check(t_list *list, t_listelem *start, t_listelem *end)
{
	int		nbs;
	int		nbe;
	int		value;

	nbs = 0;
	nbe = 0;
	value = 0;
	while (start != end)
	{
		if (ft_strcmp(LIST_DATA(start), "##start") == 0)
		{
			(value == 1) ? ft_error(NULL, list) : 1;
			nbs++;
			value = 1;
		}
		else if (ft_strcmp(LIST_DATA(start), "##end") == 0)
		{
			(value == 1) ? ft_error(NULL, list) : 1;
			nbe++;
			value = 1;
		}
		else if (ft_comment(LIST_DATA(start)) == 3
				&& ft_count_char(LIST_DATA(start), ' ') == 2)
			value = 0;
		start = LIST_NEXT(start);
	}
	if (nbs > 1 || nbe > 1 || value == 1 || nbe == 0 || nbs == 0)
		ft_error(NULL, list);
	return (0);
}

char			*ft_search_start(t_list *list)
{
	t_listelem		*tmp;
	char			*str;

	tmp = LIST_HEAD(list);
	while (tmp != NULL)
	{
		if (ft_strcmp("##start", LIST_DATA(tmp)) == 0)
		{
			while (tmp != NULL)
			{
				str = LIST_DATA(tmp);
				if (str[0] != '#')
					return (ft_strsub(str, 0, ft_strchr(str, ' ') - str));
				tmp = LIST_NEXT(tmp);
			}
		}
		tmp = LIST_NEXT(tmp);
	}
	return (NULL);
}
