/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:32:19 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/27 18:33:29 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_several_path(t_path *data1, t_path *data2)
{
	ft_free_path(data1);
	ft_free_path(data2);
}

void	ft_free_path(t_path *data)
{
	if (data != NULL)
	{
		free(data->data);
		free(data);
	}
}

void	ft_free_dcharcom(char **data)
{
	int		index;

	index = 0;
	while (data[index] != NULL)
		free(data[index++]);
	free(data[index]);
	free(data);
}
