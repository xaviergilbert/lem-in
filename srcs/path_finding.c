/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:40:41 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/19 14:57:54 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Initialize the tab in which we will have the different path
** Initialize the first path and the first link which is the start room
*/

void			init_path_finding(t_struct *s)
{
	if (!(s->fpath = (t_path*)malloc(sizeof(t_path))))
		exit(0);
	if (!(s->fpath->first = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	s->fpath->first->room = s->room[0];
	s->fpath->first->next = NULL;
	s->fpath->path_len = 0;
	s->fpath->prev = NULL;
	s->fpath->next = NULL;
	s->lpath = s->fpath;
}

int				num_in_path(t_struct *s, int i)
{
	int			k;

	k = -1;
	while (++k < s->nb_rooms)
	{
		if (s->room[i]->matrice[k] != 0)
			return (0);
	}
	return (1);
}

t_path			*new_path(t_struct *s, t_path *cpath)
{
	t_path		*tmp;

	tmp = (t_path*)malloc(sizeof(t_path));
	tmp->first = (t_link*)malloc(sizeof(t_link));
	cpath->next = tmp;
	s->lpath = tmp;
	tmp->next = NULL;
	tmp->prev = cpath;
	cpath = tmp;
	cpath->first->room = s->room[0];
	cpath->first->next = NULL;
	cpath->path_len = 0;
	s->nb_path++;
	modif_matrix(s);
	return (cpath);
}

void			path_finding(t_struct *s)
{
	t_path		*cpath;
	t_link		*element;
	int			i;
	int			k;

	init_path_finding(s);
	cpath = s->fpath;
	while (num_in_path(s, 0) == 0)
	{
		element = cpath->first;
		while (element && element->room->name != s->room[s->nb_rooms - 1]->name)
		{
			i = 0;
			while (s->room[i] != element->room)
				i++;
			k = find_shorter_link(s, i);
			new_link(s, cpath, &k);
			s->room[i]->matrice[k] = 0;
			i > 0 ? del_col(s, i) : 0;
			element = element->next;
		}
		cpath = new_path(s, cpath);
	}
}
