/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/07 18:16:38 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkname(t_data *rooms)
{
	t_data	*tmp;

	if (rooms->next !=  NULL)
		tmp = rooms->next;
	else
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->str, rooms->str) == 0)
			ft_error();
		tmp = tmp->next;
	}
	ft_checkname(rooms->next);
	return (0);
}

int		ft_checkstend(t_data *rooms)
{
	int		start;
	int		end;
	t_data	*tmp;
	int		value;

	start = 0;
	end = 0;
	tmp = rooms;
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
	(start > 1 || end > 1) ? ft_error() : 0;
	return (0);
}

int		ft_checkbegin(t_data *rooms, t_data *tunnels)
{
	t_data	*tmp;
	char	*str_r;
	char	*str_t;
	char	*ptr_r;
	char	*ptr_t;

	tmp = rooms;
	str_t = ft_strdup(tunnels->str);
	ptr_t = ft_strtok(str_t, "-");
	while (tmp != NULL)
	{
		str_r = ft_strdup(tmp->str);
		ptr_r = ft_strtok(str_r, " ");
		if (ft_strcmp(ptr_t, ptr_r) == 0)
		{
			free(str_t);
			return (0);
		}
		tmp = tmp->next;
		free(str_r);
	}
	free(str_t);
	return (1);
}

int		ft_checkend(t_data *rooms, t_data *tunnels)
{
	t_data	*tmp;
	char	*str_r;
	char	*str_t;
	char	*ptr_r;
	char	*ptr_t;

	tmp = rooms;
	str_t = ft_strdup(tunnels->str);
	ft_strtok(str_t, "-");
	ptr_t = ft_strtok(NULL, "-");
	while (tmp != NULL)
	{
		str_r = ft_strdup(tmp->str);
		ft_strtok(str_r, " ");
		ptr_r = ft_strtok(str_r, " ");
		if (ft_strcmp(ptr_t, ptr_r) == 0)
		{
			free(str_t);
			return (0);
		}
		tmp = tmp->next;
		free(str_r);
	}
	free(str_t);
	return (1);
}

int		ft_checktunnels(t_data *rooms, t_data *tunnels)
{
	if (tunnels == NULL)
		return (0);
	if (ft_checkbegin(rooms, tunnels) == 1)
		ft_error();
	if (ft_checkend(rooms, tunnels) == 1)
		ft_error();
	ft_checktunnels(rooms, tunnels->next);
	return (0);
}

int		ft_checkdata(t_spec *rooms)
{
	if (rooms->rooms == NULL || rooms->tunnels == NULL)
		ft_error();
	ft_checkname(rooms->rooms);
	ft_checkstend(rooms->rooms);
	ft_checktunnels(rooms->rooms, rooms->tunnels);
	return (0);
}
