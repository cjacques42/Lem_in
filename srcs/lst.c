/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:05:48 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/04 16:52:57 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_dataadd(t_data **begin, t_data *new)
{
	t_data	*tmp;

	tmp = NULL;
	tmp = *begin;
	*begin = new;
	(*begin)->next = tmp;
}

void	ft_addback(t_data **begin, t_data *new)
{
	if ((*begin) == NULL)
	{
		(*begin) = new;
		return ;
	}
	ft_addback(&(*begin)->next, new);
}

void	ft_datadelone(t_data **begin)
{
	if ((*begin)->next == NULL)
	{
		free((*begin)->str);
		free(*begin);
		*begin = NULL;
		return ;
	}
	ft_datadelone(&(*begin)->next);
}

t_data	*ft_new_data(char *line)
{
	t_data	*elem;

	elem = (t_data*)malloc(sizeof(*elem));
	if (elem == NULL)
		return (NULL);
	elem->str = ft_strdup(line);
	elem->next = NULL;
	return (elem);
}
