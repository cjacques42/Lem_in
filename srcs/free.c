/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:32:19 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 13:40:53 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_dcharcom(char **data)
{
	int		index;

	index = 0;
	while (data[index] != NULL)
		free(data[index++]);
	free(data[index]);
	free(data);
}
