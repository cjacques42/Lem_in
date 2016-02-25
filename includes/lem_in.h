/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/25 17:06:53 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_node
{
	int				id;
	int				weight;
	struct s_node	*back;
	int				parse;
}				t_node;

int		ft_error(void);
int		ft_parse_file(char *name);
int		ft_dijkstra(int **matrix);

#endif
