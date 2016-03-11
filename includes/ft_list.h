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

# include "lem_in.h"

typedef struct	s_set
{
	void			*data;
	struct s_set	*next;
}				t_set;

t_set			*ft_setnew(void *data);
void			ft_setadd(t_set **begin, t_set *new);
void			ft_setaddback(t_set **begin, t_set *new);
void			ft_setdestroy(t_set **set);
void			ft_setdestroyone(t_set **begin);

#endif
