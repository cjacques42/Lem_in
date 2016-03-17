/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:31:46 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/17 08:10:48 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

void	ft_set_init(t_set *set, int (*ft_match)(void *k1, void *k2)
		, void (*ft_destroy)(void *data))
{
	set->head = NULL;
	set->tail = NULL;
	set->ft_destroy = ft_destroy;
	set->size = 0;
	set->ft_match = ft_match;
}

int		ft_set_insert(t_set *set, void *data)
{
	if (ft_set_ismember(set, data) == 1)
		return (1);
	if (ft_list_ins_next(set, set->tail, data) == -1)
		return (-1);
	return (0);
}

int		ft_set_remove(t_set *set, void **data)
{
	t_listelem		*tmp;
	t_listelem		*ptr;

	tmp = LIST_HEAD(set);
	while (tmp != NULL)
	{
		if (set->ft_match(*data, LIST_DATA(tmp)) == 0)
			break ;
		ptr = tmp;
		tmp = LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	return (ft_list_rem_next(set, ptr, data));
}

int		ft_set_ismember(t_set *set, void *data)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(set);
	while (tmp != NULL)
	{
		if (set->ft_match(data, LIST_DATA(tmp)) == 0)
			return (1);
		tmp = LIST_NEXT(tmp);
	}
	return (0);
}

int		ft_set_issubnet(t_set *set1, t_set *set2)
{
	t_listelem		*tmp;

	if (LIST_SIZE(set1) > LIST_SIZE(set2))
		return (0);
	tmp = LIST_HEAD(set1);
	while (tmp != NULL)
	{
		if (ft_set_ismember(set2, LIST_DATA(tmp)) == 0)
			return (0);
		tmp = LIST_NEXT(tmp);
	}
	return (1);
}
