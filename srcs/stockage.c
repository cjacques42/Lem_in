/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 09:59:30 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/09 12:39:02 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_putinstruct(t_spec *spec, t_node **nodes)
{
	char	**ptr;
	t_data	*tmp;
	int		index;

	index =  0;
	tmp = spec->rooms;
	while (tmp != NULL)
	{
		if (tmp->str[0] != '#')
		{
			ptr = ft_strsplit(tmp->str, ' ');
			ft_addback_node(nodes, ft_new_node(ptr, index));
			index++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_stock(t_spec *spec, t_node **nodes)
{
	char	**ptr;
	t_data	*tmp;

	ft_putinstruct(spec, nodes);
	tmp = spec->tunnels;
	while (tmp != NULL)
	{
		ptr = ft_strsplit(tmp->str, '-');
		ft_add_link(ptr, nodes);
		tmp = tmp->next;
	}
	return (0);
}
