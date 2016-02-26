/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/02/26 17:46:40 by cjacques         ###   ########.fr       */
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

# define INT_MAX		0x7FFFFFFF

typedef struct	s_node
{
	char			*name;
	int				weight;
	struct s_node	*back;
	int				parse;
	int				x;
	int				y;
	t_list			*edge;
	struct s_node	*next;
}				t_node;

typedef enum	e_command
{
	ROOM, START, END
}				t_command;

typedef	struct	s_spec
{
	int		ants;
	t_list	*tunnels;
}				t_spec;

int				ft_error(void);
int				ft_parse_file(char *name, t_node **nodes, t_spec *spec);
int				ft_dijkstra(int **matrix);
int				ft_check_int(char *str);
t_node			*ft_new_node(char **room);
void			ft_add_node(t_node **begin, t_node *tmp);

#endif
