/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:31:36 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 10:31:38 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

int		ft_set_union(t_set *setu, t_set *set1, t_set *set2)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(set1);
	ft_set_init(setu, set1->ft_match, NULL);
	while (tmp != NULL)
	{
		if (ft_list_ins_next(setu, LIST_TAIL(setu), LIST_DATA(tmp)) != 0)
		{
			SET_DESTROY(setu);
			return (-1);
		}
		tmp = LIST_NEXT(tmp);
	}
	tmp = LIST_HEAD(set2);
	while (tmp != NULL)
	{
		if (ft_set_ismember(setu, LIST_DATA(tmp)) == 0)
			if (ft_list_ins_next(setu, LIST_TAIL(setu), LIST_DATA(tmp)) != 0)
			{
				SET_DESTROY(setu);
				return (-1);
			}
		tmp = LIST_NEXT(tmp);
	}
	return (0);
}

int		ft_set_diff(t_set *setd, t_set *set1, t_set *set2)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(set1);
	ft_set_init(setd, set1->ft_match, NULL);
	while (tmp != NULL)
	{
		if (ft_set_ismember(set2, LIST_DATA(tmp)) == 0)
			if (ft_list_ins_next(setd, LIST_TAIL(setd), LIST_DATA(tmp)) != 0)
			{
				SET_DESTROY(setd);
				return (-1);
			}
		tmp = LIST_NEXT(tmp);
	}
	return (0);
}

int		ft_set_inter(t_set *seti, t_set *set1, t_set *set2)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(set1);
	ft_set_init(seti, set1->ft_match, NULL);
	while (tmp != NULL)
	{
		if (ft_set_ismember(set2, LIST_DATA(tmp)) == 1)
			if (ft_list_ins_next(seti, LIST_TAIL(seti), LIST_DATA(tmp)) != 0)
			{
				SET_DESTROY(seti);
				return (-1);
			}
		tmp = LIST_NEXT(tmp);
	}
	return (0);
}

int		ft_set_isequal(t_set *set1, t_set *set2)
{
	t_listelem		*tmp;

	if (LIST_SIZE(set1) != LIST_SIZE(set2))
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
