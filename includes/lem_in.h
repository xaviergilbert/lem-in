/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:16:55 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/19 19:23:09 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft/libft.h"

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	int				*matrice;
	int				nb_links;
}					t_room;

typedef struct		s_link
{
	t_room			*room;
	int				ant_in;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	t_link			*first;
	int				path_len;
	int				path_close;
	struct s_path	*prev;
	struct s_path	*next;
}					t_path;

typedef struct		s_ant
{
	t_link			*place;
	int				still_in_path;
}					t_ant;

typedef struct		s_liste
{
	int				value;
	int				i;
	int				k;
	struct s_liste	*prev;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_struct
{
	t_room			**room;
	t_ant			**ant;
	char			**tab;
	t_path			*fpath;
	t_path			*lpath;
	t_liste			*liste;
	char			*str;
	int				vmatrice;
	int				path_found;
	int				nb_rooms;
	int				nb_links;
	int				nb_path;
	int				nb_ants;
	int				nb_coups;
}					t_struct;

/*
** Files parsing/check error/building matrice
*/

int					check_errors(t_struct *s, int c, int flag, int flag2);
int					check_errors2(t_struct *s);
int					parsing(t_struct *s);
void				build_room(t_struct *s, int c, int i);
int					build_link(t_struct *s, int c, int l, int i);
int					ft_isnumber(char *str);

/*
** Files building path/select path(s)
*/

void				modif_matrix(t_struct *s);
void				del_matrix_list(t_struct *s);
void				create_matrix_list(t_struct *s);
int					find_shorter_link(t_struct *s, int i);
void				del_col(t_struct *s, int i);
void				get_info(t_struct *s);
void				path_finding(t_struct *s);
int					new_link(t_struct *s, t_path *cpath, int *i);
void				sort_path(t_struct *s);
void				elimination(t_struct *s);
void				ants_going_in(t_struct *s);

/*
** Display
*/

void				display_matrice(t_struct *s);
void				display_path(t_struct *s);
void				display_one_path(t_path *cpath);

/*
** Free
*/

void				free_all(t_struct *s);
void				free_path(t_struct *s, t_path *cpath);
void				free_tab(t_struct *s);

/*
** Test
*/

void				free_rooms(t_struct *s);

#endif
