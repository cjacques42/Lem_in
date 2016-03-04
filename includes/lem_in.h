/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/04 13:03:53 by cjacques         ###   ########.fr       */
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
	struct s_data	*edges;
	struct s_node	*next;
	enum e_command	status;
}				t_node;

typedef	struct	s_spec
{
	int				ants;
	struct s_data	*rooms;
	struct s_data	*tunnels;
}				t_spec;

typedef struct	s_data
{
	char			*str;
	struct s_data	*next;
}				t_data;

int				ft_error(void);
int				ft_parse_file(char *name, t_node **nodes, t_spec *spec);
int				ft_dijkstra(int **matrix);
int				ft_check_int(char *str);
t_node			*ft_new_node(char **room, t_command status);
void			ft_add_node(t_node **begin, t_node *tmp);
int				ft_status(char **room, t_command *status, int *start, int *end);
int				ft_nbrstr(char **str);
int				ft_search(char *str, t_node **nodes);
void			ft_dataadd(t_data **begin, t_data *new);
void			ft_addback(t_data **begin, t_data *new);
t_data			*ft_new_data(char *line);
void			ft_add_link(char **room, t_node **nodes, int r1, int r2);

#endif
