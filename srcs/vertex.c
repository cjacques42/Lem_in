/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 09:49:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/23 09:20:50 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_cmp(t_graph *graph, void *data, t_path **ptr)
{
	t_listelem		*tmp;
	t_path			*path;

	tmp = LIST_HEAD(&graph->adjlists);
	while (tmp != NULL)
	{
		path = ((t_adjlist*)LIST_DATA(tmp))->vertex;
		if (ft_strcmp(data, path->data) == 0)
		{
			*ptr = path;
			return (0);
		}
		tmp = LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	return (0);
}

t_path			*ft_search_room(t_graph *graph, t_list *list, char *s)
{
	t_listelem		*tmp;
	char			*str;
	t_path			*ptr;

	tmp = LIST_HEAD(list);
	while (tmp != NULL)
	{
		if (ft_strcmp(s, LIST_DATA(tmp)) == 0)
		{
			while (tmp != NULL)
			{
				str = LIST_DATA(tmp);
				if (str[0] != '#')
				{
					str = ft_strsub(str, 0, ft_strchr(str, ' ') - str);
					ft_cmp(graph, str, &ptr);
					free(str);
					return (ptr);
				}
				tmp = LIST_NEXT(tmp);
			}
		}
		tmp = LIST_NEXT(tmp);
	}
	return (NULL);
}

int				ft_vertexcmp(t_path *s1, t_path *s2)
{
	int				i;
	char			*p1;
	char			*p2;

	p1 = s1->data;
	p2 = s2->data;
	i = 0;
	while (p1[i] == p2[i] && p1[i] != '\0' && p2[i] != '\0')
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}

t_path			*ft_newpath(char *str)
{
	t_path		*path;

	path = (t_path*)malloc(sizeof(*path));
	if (path == NULL)
		ft_error(NULL, NULL);
	path->data = str;
	return (path);
}
