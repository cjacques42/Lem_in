/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/07 10:26:38 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkname(t_data *spec)
{
	(void)spec;
	return (0);
}

int		ft_checkstend(t_data *spec)
{
	int		start;
	int		end;
	t_data	*tmp;
	int		value;

	start = 0;
	end = 0;
	tmp = spec;
	value = 0;
	while (tmp != NULL)
	{
		if (tmp->str[0] == '#' && tmp->str[2] == 's')
		{
			(value == 1) ? ft_error() : 1;
			start++;
			value = 1;
		}
		else if (tmp->str[0] == '#' && tmp->str[2] == 'e')
		{
			(value == 1) ? ft_error() : 1;
			end++;
			value = 1;
		}
		else
			value = 0;
		tmp = tmp->next;
	}
	if (start > 1 || end > 1)
		ft_error();
	return (0);
}

int		ft_checktunnels(t_data *spec)
{
	(void)spec;
	return (0);
}

int		ft_checkdata(t_spec *spec)
{
	if (spec->rooms == NULL || spec->tunnels == NULL)
		ft_error();
	ft_checkname(spec->rooms);
	ft_checkstend(spec->rooms);
	ft_checktunnels(spec->tunnels);
	return (0);
}
