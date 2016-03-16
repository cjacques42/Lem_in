/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:40:31 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/16 13:37:37 by cjacques         ###   ########.fr       */
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
int				ft_parse_file(t_list *list, t_graph *graph);
int				ft_check_int(char *str);
int				ft_count_char(char *str, char c);
int				ft_check(t_listelem *start, t_listelem *end);
int				ft_comment(char *line);
int				ft_check_and_add(t_listelem **start, t_listelem **end
		, t_graph *graph);
void			ft_free_dcharcom(char **data);

#endif
