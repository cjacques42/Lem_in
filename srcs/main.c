/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:33:20 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 15:03:11 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_list	list;

	ft_parse_file(&list);
	while (list.head != NULL)
	{
		printf("%s\n", list.head->data);
		list.head = LIST_NEXT(list.head);
	}
//	ft_putnbr(list.size);
//	ft_list_destroy(&list);
	return (0);
}
