/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/14 18:41:26 by cjacques         ###   ########.fr       */
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

typedef struct	s_path
{
	void			*data;
	int				weigth;
	struct s_path	*parent;
}				t_path;

typedef	struct	s_spec
{
	int					ants;
	struct s_list		*rooms;
	struct s_list		*tunnels;
}				t_spec;

void			ft_error(void);
int				ft_parse_file(t_list *list, t_spec *spec);
int				ft_dijkstra(t_node **nodes, t_spec *spec, t_node **start
		, t_node **end);
int				ft_check_int(char *str);
t_node			*ft_new_node(char **room, int index);
void			ft_add_node(t_node **begin, t_node *new);
void			ft_addback_node(t_node **begin, t_node *new);
int				ft_nbrstr(char **str);
int				ft_search(char *str, t_node **nodes);
void			ft_link(char **room, t_node **nodes);
int				ft_checkdata(t_spec *spec);
int				ft_stock(t_spec *spec, t_node **nodes);

#endif
