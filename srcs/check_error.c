/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:57:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 11:35:49 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checkname(t_listelem *rooms)
{
	t_listelem	*tmp;

	if (rooms->head->next !=  NULL)
		tmp = rooms->head->next;
	else
		return (0);
	while (tmp)
	{
		if (ft_strcmp(tmp->data, rooms->head->data) == 0)
			ft_error();
		tmp = tmp->next;
	}
	ft_checkname(ft_list_next(rooms->head));
	return (0);
}

int		ft_checkstend(t_list *rooms)
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

int		ft_checkbegin(t_list *rooms, t_list *tunnels)
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

int		ft_checkend(t_list *rooms, t_list *tunnels)
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

int		ft_checktunnels(t_list *rooms, t_list *tunnels)
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

int		ft_checkdata(t_spec *spec)
{
	if (ft_list_size(spec->tunnels) || ft_list_size(spec->rooms) == 0)
		ft_error();
	ft_checkname(spec->rooms->head);
//	ft_checkstend(spec->rooms->head);
//	ft_checktunnels(spec->rooms->head, spec->tunnels->head);
	return (0);
}
