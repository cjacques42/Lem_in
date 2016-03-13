/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:57:39 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/11 17:33:33 by cjacques         ###   ########.fr       */
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
	int					(*ft_match)(void *, void *);
	void				(*ft_destroy)(void *data);
	struct s_listelem	*head;
	struct s_listelem	*tail;
}				t_list;

void			ft_list_init(t_list *list, void (*ft_destroy)(void *data));
void			ft_list_destroy(t_list *list);
int				ft_list_ins_next(t_list *list, t_listelem *elem
		, const void *data);
int				ft_list_rem_next(t_list *list, t_listelem *elem, void **data);

#define ft_list_size(list)			(list->size)
#define ft_list_head(list)			(list->head)
#define ft_list_tail(list)			(list->tail)
#define ft_list_ishead(list, elem)	((list->head == elem) ? 1 : 0)
#define ft_list_istail(list, elem)	((list->tail == elem) ? 1 : 0)
#define ft_list_data(elem)			(elem->data)
#define ft_list_next(elem)			(elem->next)

#endif
