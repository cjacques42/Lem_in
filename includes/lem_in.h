/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/21 17:19:41 by cjacques         ###   ########.fr       */
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
# include "ft_graph.h"

# define INT_MAX		0x7FFFFFFF
# define INT_MIN		(int)0x80000000

typedef struct	s_path
{
	void			*data;
	int				weight;
	int				mark;
	struct s_path	*parent;
}				t_path;

typedef	struct	s_spec
{
	int					ants;
	struct s_list		*rooms;
	struct s_list		*tunnels;
}				t_spec;

void			ft_error(t_graph *graph, t_list *list);
int				ft_parse_file(t_list *list, t_graph *graph);
int				ft_check_int(char *str);
int				ft_count_char(char *str, char c);
int				ft_check(t_list *list, char **line);
int				ft_comment(char *line);
int				ft_check_and_add(t_graph *graph, t_list *list, char **line);
void			ft_free_dcharcom(char **data);
t_path			*ft_search_start(t_graph *graph, t_list *list);
int				ft_vertexcmp(t_path *s1, t_path *s2);
t_path			*ft_newpath(char *str);
int				ft_dijkstra(t_graph *graph, t_path *start);

#endif
