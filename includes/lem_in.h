/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/11 12:30:36 by cjacques         ###   ########.fr       */
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
# include "ft_list.h"

# define INT_MAX		0x7FFFFFFF

typedef enum	e_command
{
	ROOM, START, END
}				t_command;

typedef struct	s_node
{
	int				index;
	int				weight;
	int				walkable;
	char			*name;
	int				x;
	int				y;
	struct s_link	*edges;
	struct s_node	*back;
	struct s_node	*next;
}				t_node;

typedef	struct	s_spec
{
	int				ants;
	struct s_data	*rooms;
	struct s_data	*tunnels;
}				t_spec;

typedef struct	s_link
{
	int				id;
	struct s_link	*next;
}				t_link;

typedef struct	s_data
{
	char			*str;
	struct s_data	*next;
}				t_data;

void			ft_error(void);
int				ft_parse_file(t_spec *spec);
int				ft_dijkstra(t_node **nodes, t_spec *spec, t_node **start
		, t_node **end);
int				ft_check_int(char *str);
t_node			*ft_new_node(char **room, int index);
void			ft_add_node(t_node **begin, t_node *new);
void			ft_addback_node(t_node **begin, t_node *new);
int				ft_status(char **room, t_command *status, int *start, int *end);
int				ft_nbrstr(char **str);
int				ft_search(char *str, t_node **nodes);
void			ft_dataadd(t_data **begin, t_data *new);
void			ft_addback(t_data **begin, t_data *new);
t_data			*ft_new_data(char *line);
void			ft_link(char **room, t_node **nodes);
void			ft_datadelone(t_data **begin);
void			ft_datadel(t_data **begin);
int				ft_checkdata(t_spec *spec);
int				ft_stock(t_spec *spec, t_node **nodes);
void			ft_addlink(t_link **begin, t_link *new);
t_link			*ft_newlink(int id);

#endif
