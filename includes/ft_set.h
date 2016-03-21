/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 09:04:01 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 09:04:06 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include "ft_list.h"

typedef t_list		t_set;

void	ft_set_init(t_set *set, int (*ft_match)(void *k1, void *k2)
		, void (*ft_destroy)(void *data));
int		ft_set_insert(t_set *set, void *data);
int		ft_set_remove(t_set *set, void **data);
int		ft_set_union(t_set *setu, t_set *set1, t_set *set2);
int		ft_set_inter(t_set *seti, t_set *set1, t_set *set2);
int		ft_set_diff(t_set *setd, t_set *set1, t_set *set2);
int		ft_set_ismember(t_set *set, void *data);
int		ft_set_issubset(t_set *set1, t_set *set2);
int		ft_set_isequal(t_set *set1, t_set *set2);

# define SET_DESTROY ft_list_destroy
# define SET_SIZE(set)		((set)->size)

#endif
