/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:57:01 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 09:38:17 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void		ft_list_init(t_list *list, void (*ft_destroy)(void *data))
{
	list->head = NULL;
	list->tail = NULL;
	list->ft_destroy = ft_destroy;
	list->size = 0;
}

void			ft_list_destroy(t_list *list)
{
	void	*data;

	if (ft_list_size(list) == 0)
	{
		ft_memset(list, '\0', sizeof(list));
		return ;
	}
	if (ft_list_rem_next(list, NULL, &data) == 0 && list->ft_destroy != NULL)
		list->ft_destroy(data);
	ft_list_destroy(list);
}

int				ft_list_ins_next(t_list *list, t_listelem *elem
		, const void *data)
{
	t_listelem	*new_elem;

	if ((new_elem = (t_listelem*)malloc(sizeof(*new_elem))) == NULL)
		return (-1);
	new_elem->data = (void*)data;
	if (elem == NULL)
	{
		new_elem->next = list->head;
		list->head = new_elem;
		if (ft_list_size(list) == 0)
			list->tail = new_elem;
	}
	else
	{
		if (elem->next == NULL)
			list->tail = new_elem;
		new_elem->next = elem->next;
		elem->next = new_elem;
	}
	(list->size)++;
	return (0);
}

int				ft_list_rem_next(t_list *list, t_listelem *elem, void **data)
{
	t_listelem		*tmp;

	if (ft_list_size(list) == 0)
		return (-1);
	if (elem == NULL)
	{
		tmp = list->head;
		*data = tmp->data;
		list->head = ft_list_next(tmp);
		if (ft_list_size(list) == 1)
			list->tail = NULL;
	}
	else
	{
		tmp = ft_list_next(elem);
		*data = tmp->data;
		elem->next = ft_list_next(tmp);
		if (elem->next == NULL)
			list->tail = elem;
	}
	free(tmp);
	(list->size)--;
	return (0);
}
