/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:57:39 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/24 15:48:10 by cjacques         ###   ########.fr       */
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
int				ft_list_ins_next(t_list *list, t_listelem *elem, void *data);
int				ft_list_rem_next(t_list *list, t_listelem *elem, void **data);

# define LIST_SIZE(list)				((list)->size)
# define LIST_HEAD(list)				((list)->head)
# define LIST_TAIL(list)				((list)->tail)
# define LIST_ISHEAD(list, elem)		(((list)->head == (elem)) ? 1 : 0)
# define LIST_ISTAIL(list, elem)		(((list)->tail == (elem)) ? 1 : 0)
# define LIST_DATA(elem)				((elem)->data)
# define LIST_NEXT(elem)				((elem)->next)

#endif
