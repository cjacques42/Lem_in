/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:57:39 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 14:21:38 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct	s_listelem
{
	void				*data;
	struct s_listelem	*next;
}				t_listelem;

typedef struct	s_list
{
	int					size;
	int					(*ft_match)(void *k1, void *k2);
	void				(*ft_destroy)(void *data);
	struct s_listelem	*head;
	struct s_listelem	*tail;
}				t_list;

void			ft_list_init(t_list *list, void (*ft_destroy)(void *data));
void			ft_list_destroy(t_list *list);
int				ft_list_ins_next(t_list *list, t_listelem *elem
		, const void *data);
int				ft_list_rem_next(t_list *list, t_listelem *elem, void **data);

# define SIZE(list)				(list->size)
# define HEAD(list)				(list->head)
# define TAIL(list)				(list->tail)
# define ISHEAD(list, elem)		((list->head == elem) ? 1 : 0)
# define ISTAIL(list, elem)		((list->tail == elem) ? 1 : 0)
# define DATA(elem)				(elem->data)
# define NEXT(elem)				(elem->next)

#endif
