/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:13:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/25 16:07:31 by cjacques         ###   ########.fr       */
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

static void		ft_circular(t_path *end, int nb_ants)
{
	t_path		*tmp;

	tmp = end;
	while (tmp->parent != NULL)
	{
		ft_putendl(tmp->data);
		tmp->mark = 0;
		tmp->weight = 0;
		tmp = tmp->parent;
	}
	tmp->mark = nb_ants;
	tmp->parent = end;
}

void			ft_final_print(t_path *start, t_path *end, int nb_ants
		, t_list *multi)
{
	t_listelem	*elem;
	t_path		*path;

	(void)start;
	(void)ft_print;
	(void)nb_ants;
	(void)ft_circular;
	elem = LIST_HEAD(multi);
	while (elem != NULL)
	{
		path = LIST_DATA(LIST_HEAD((t_set*)LIST_DATA(elem)));
		end->parent = path;
	//	ft_circular(end, nb_ants);
//		ft_print(start, end, nb_ants);
		elem = LIST_NEXT(elem);
	}
}
/*	t_listelem	*tmp;
	t_set	*ptr;
	t_listelem	*elem;
	t_path		*path;

	(void)start;
	tmp = LIST_HEAD(multi);
	while (tmp != NULL)
	{
		ptr = LIST_DATA(tmp);
		ft_putnbr(LIST_SIZE(ptr));
		ft_putstr("\n");
		elem = LIST_HEAD(ptr);
		while (elem != NULL)
		{
			path = LIST_DATA(elem);
			ft_putendl(path->data);
			elem = LIST_NEXT(elem);
		}
		tmp = LIST_NEXT(tmp);
	}*/

