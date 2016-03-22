/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 09:49:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/22 13:27:37 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_vertexcmp(t_path *s1, t_path *s2)
{
	int		i;
	char	*p1;
	char	*p2;

	p1 = s1->data;
	p2 = s2->data;
	i = 0;
	while (p1[i] == p2[i] && p1[i] != '\0' && p2[i] != '\0')
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}

t_path		*ft_newpath(char *str)
{
	t_path		*path;

	path = (t_path*)malloc(sizeof(*path));
	if (path == NULL)
		ft_error(NULL, NULL);
	path->data = str;
	return (path);
}
