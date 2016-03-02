/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/02 14:49:06 by cjacques         ###   ########.fr       */
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

typedef enum	e_command
{
	ROOM, START, END
}				t_command;

typedef struct	s_node
{
	char			*name;
	int				weight;
	struct s_node	*back;
	int				parse;
	int				x;
	int				y;
	struct s_edge	*edges;
	struct s_node	*next;
	enum e_command	status;
}				t_node;

typedef	struct	s_spec
{
	int				ants;
	struct s_edge	*tunnels;
}				t_spec;

typedef struct	s_edge
{
	char			*link;
	struct s_edge	*next;
}				t_edge;

int				ft_error(void);
int				ft_parse_file(char *name, t_node **nodes, t_spec *spec);
int				ft_dijkstra(int **matrix);
int				ft_check_int(char *str);
t_node			*ft_new_node(char **room, t_command status);
void			ft_add_node(t_node **begin, t_node *tmp);
t_command		ft_status(char **room);
int				ft_nbrstr(char **str);
int				ft_search(char *str, t_node **nodes);
void			ft_edgeadd(t_edge **begin, t_edge *new);
t_edge			*ft_new_edge(char *line);


#endif
