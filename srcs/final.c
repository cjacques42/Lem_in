/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:13:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/25 17:43:38 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_valueandprint(t_path **tmp, int *index)
{
	((*tmp)->mark)++;
	((*tmp)->weight)++;
	((*tmp)->parent->mark)--;
	if (*index == 0)
		ft_putstr(" L");
	else
	{
		*index = 0;
		ft_putstr("L");
	}
	ft_putnbr((*tmp)->weight);
	ft_putchar('-');
	ft_putstr((*tmp)->data);
}

static void		ft_print(t_path *start, t_path *end, int nb_ants)
{
	t_path	*tmp;
	int		index;

	tmp = end;
	index = 1;
	while (end->mark != nb_ants)
	{
		if (tmp == start)
		{
			ft_putchar('\n');
			index = 1;
		}
		else if (tmp->parent->mark != 0)
			ft_valueandprint(&tmp, &index);
		tmp = tmp->parent;
	}
	ft_putchar('\n');
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
		path = LIST_DATA(LIST_HEAD((t_set*)LIST_DATA(elem)));
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
}

void			ft_final_print(t_path *start, t_path *end, int nb_ants
		, t_list *multi)
{
	t_listelem	*elem;
	t_path		*path;

	ft_circular(multi, end, start, nb_ants);
	elem = LIST_HEAD(multi);
	start->parent = end;
	while (elem != NULL)
	{
		path = LIST_DATA(LIST_HEAD((t_set*)LIST_DATA(elem)));
		end->parent = path;
		ft_print(start, end, nb_ants);
		elem = LIST_NEXT(elem);
	}
}
