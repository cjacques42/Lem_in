/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:10:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/26 17:52:20 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_add_node(t_node **begin, t_node *tmp)
{
	if (*begin == NULL)
		*begin = tmp;
	else
	{
		tmp->next =	 *begin;
		*begin = tmp;	
	}
}

t_node		*ft_new_node(char **room)
{
	t_node	*tmp;
	int		coord;

	tmp = NULL;
	if ((tmp = (t_node*)malloc(sizeof(*tmp))) == NULL)
		return (NULL);
	if ((coord = ft_check_int(room[1])) == -1)
		return (NULL);
	tmp->x = coord;
	if ((coord = ft_check_int(room[2])) == -1)
		return (NULL);
	tmp->y = coord;
	tmp->name = ft_strdup(room[0]);
	if (tmp->name[0] == 'L')
		return (NULL);
	tmp->next = NULL;
	tmp->back = NULL;
	tmp->weight = -1;
	tmp->parse = 0;
	tmp->edge = NULL;
	return (tmp);
}
