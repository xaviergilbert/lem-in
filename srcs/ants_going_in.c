/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_going_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:28:34 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 14:48:33 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Initialize structure ants and the path selected
** None rooms have ants in
** None ants are in a room and every ant is still in the path
*/

void			init_path(t_struct *s)
{
	t_path			*cpath;
	t_link			*element;
	int				a;

	cpath = s->fpath;
	s->ant = (t_ant**)malloc(sizeof(t_ant) * s->nb_ants);
	while (cpath)
	{
		element = cpath->first;
		while (element->next->next)
		{
			element = element->next;
			element->ant_in = 0;
		}
		cpath = cpath->next;
	}
	a = 0;
	while (++a <= s->nb_ants)
	{
		s->ant[a] = (t_ant*)malloc(sizeof(t_ant));
		s->ant[a]->place = NULL;
		s->ant[a]->still_in_path = 1;
	}
}

/*
** If we got an ant which is not yet in the path
** While there is no ant in the second link of last path
** -> If we are not on the first path and number of remaining ants is less than
**	 the difference between current path length and previous path length,
**	 -> We go previous path
** -> Else we say the ant place is on the second link of the current path and
**	 in this place there is this ant
** -> Next ant, next path -> while
*/

void			if_new_ant(t_struct *s, int *a)
{
	t_path			*cpath;
	int				p;

	p = 0;
	if (s->ant[*a]->place == NULL)
	{
		cpath = s->fpath;
		while (s->lpath->first->next->ant_in == 0
		&& *a <= s->nb_ants)
		{
			if (cpath != s->fpath && cpath->path_len > cpath->prev->path_len
			+ ((s->nb_ants - *a) / p - 1))
				break ;
			else
			{
				s->ant[*a]->place = cpath->first->next;
				s->ant[*a]->place->ant_in = *a;
				ft_printf("L%d-%s ", *a, s->ant[*a]->place->room->name);
			}
			(*a)++;
			cpath->next ? cpath = cpath->next : 0;
			p++;
		}
		*a = 1;
	}
}

/*
** While the ant is not a new one
** -> if the ant is not arrived yet, we move it in the next link and we clean
**	 the previous place from its presence
**	 -> If we are at the end of the path, the ant is not in the path anymore
**	 -> Else there is still one ant at least in path
*/

void			while_not_new(t_struct *s, t_link *fin, int *a)
{
	ft_printf("\n");
	s->nb_coups++;
	while (*a <= s->nb_ants && s->ant[*a]->place != NULL)
	{
		if (s->ant[*a]->still_in_path)
		{
			s->ant[*a]->place->next->ant_in = *a;
			s->ant[*a]->place->ant_in = 0;
			s->ant[*a]->place = s->ant[*a]->place->next;
			ft_printf("L%d-%s ", *a, s->ant[*a]->place->room->name);
			if (ft_strcmp(fin->room->name, s->ant[*a]->place->room->name) == 0)
				s->ant[*a]->still_in_path = 0;
			else
				s->path_found = 0;
		}
		(*a)++;
	}
}

/*
** If the path doesn't have rooms but the start one and the end one, we just
**move all ants in one hit
*/

void			all_in(t_struct *s, t_link *fin, int *a)
{
	while (*a <= s->nb_ants)
	{
		ft_printf("L%d-%s ", *a, fin->room->name);
		(*a)++;
	}
	s->ant[s->nb_ants]->still_in_path = 0;
	s->path_found = 1;
}

/*
** fin is a pointer to the end rooms
** While last ant in still in a path or one ant is still in path
** -> While we haven't moved all ants -> see functions above
*/

void			ants_going_in(t_struct *s)
{
	t_link			*fin;
	int				a;

	if (s->nb_path < 1)
		return ;
	init_path(s);
	fin = s->fpath->first;
	while (fin->next)
		fin = fin->next;
	a = 1;
	s->fpath->path_len == 0 ? all_in(s, fin, &a) : 0;
	while (s->ant[s->nb_ants]->still_in_path || s->path_found == 0)
	{
		a = 1;
		s->path_found = 1;
		while (a <= s->nb_ants)
		{
			if_new_ant(s, &a);
			while_not_new(s, fin, &a);
		}
		a++;
	}
	ft_printf("\n");
}
