/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:13:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/27 15:10:25 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_print(t_path *start, t_path *end, int *index, t_list *head)
{
	t_path		*path;
	int			diff;

	(void)start;
	(void)end;
	path = LIST_DATA(LIST_HEAD(head));
	diff = LIST_SIZE(head);
	while (path != start)
	{
		if ((path->parent == start && start->mark - diff > 0) || (path->parent->mark > 0 && path->parent != start))
		{
			path->mark++;
			path->parent->mark--;
			if (path->parent == start)
				path->weight = (*index)++;
			else
				path->weight = path->parent->weight;
			ft_putstr(" L");
			ft_putnbr(path->weight);
			ft_putchar('-');
			ft_putstr(path->data);
		}
		path = path->parent;
	}
	path = path->parent;
}

static void		ft_circular(t_list *multi, t_path *end, t_path *start
		, int nb_ants)
{
	t_listelem	*elem;
	t_path		*path;

	elem = LIST_HEAD(multi);
	end->mark = 0;
	end->weight = 0;
	while (elem != NULL)
	{
		path = LIST_DATA(LIST_NEXT(LIST_HEAD((t_set*)LIST_DATA(elem))));
		end->parent = path;
		while (path->parent != NULL)
		{
			path->mark = 0;
			path->weight = 0;
			path = path->parent;
		}
		elem = LIST_NEXT(elem);
	}
	start->mark = nb_ants;
	elem = LIST_TAIL(multi);
	elem->next = LIST_HEAD(multi);
}

static void		ft_res_size(t_list *multi, t_listelem *elem, int val)
{
	t_listelem	*ptr;
	t_set		*set;
	int			index;

	set = LIST_DATA(elem);
	ptr = LIST_HEAD(multi);
	index = 0;
	if (elem == ptr)
		LIST_SIZE(set) = val;
	else
	{
		while (ptr != elem)
		{
			LIST_SIZE(set) += LIST_SIZE((t_set*)LIST_DATA(ptr));
			index++;
			ptr = LIST_NEXT(ptr);
		}
		LIST_SIZE(set) /= index;
	}
	if (LIST_NEXT(elem) != NULL)
		ft_res_size(multi, LIST_NEXT(elem), val);
}

static int		ft_diff_between_path(t_list *multi, t_listelem *elem)
{
	int			retval;
	t_listelem	*ptr;
	t_set		*set;
	int			value;

	if (LIST_NEXT(elem) != NULL)
		ft_diff_between_path(multi, LIST_NEXT(elem));
	set = LIST_DATA(elem);
	retval = LIST_SIZE(set);
	ptr = LIST_HEAD(multi);
	LIST_SIZE(set) = 0;
	while (ptr != elem)
	{
		value = LIST_SIZE((t_set*)LIST_DATA(ptr));
		LIST_SIZE(set) += retval - value;
		ptr = LIST_NEXT(ptr);
	}
	return (retval);
}

void			ft_final_print(t_path *start, t_path *end, int nb_ants
		, t_list *multi)
{
	t_listelem	*elem;
	t_path		*path;
	int			val;
	int			index;

	index = 1;
	elem = LIST_HEAD(multi);
	val = ft_diff_between_path(multi, elem);
	ft_circular(multi, end, start, nb_ants);
	start->parent = end;
	while (end->mark != nb_ants)
	{
		path = LIST_DATA(LIST_NEXT(LIST_HEAD((t_set*)LIST_DATA(elem))));
		end->parent = path;
		ft_print(start, end, &index, LIST_DATA(elem));
		if (elem == LIST_TAIL(multi))
			ft_putchar('\n');
		elem = LIST_NEXT(elem);
	}
	elem = LIST_TAIL(multi);
	elem->next = NULL;
	ft_res_size(multi, LIST_HEAD(multi), val);
}
