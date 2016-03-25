/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:13:41 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/25 15:43:41 by cjacques         ###   ########.fr       */
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
	t_path *tmp;

	tmp = end;
	ft_circular(end, nb_ants);
	ft_print(start, end, nb_ants);
}
