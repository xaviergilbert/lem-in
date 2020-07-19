/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:56:27 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 12:33:51 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Free the str tab created with the input map
*/

void			free_tab(t_struct *s)
{
	int				i;

	i = 0;
	while (s->tab[i])
	{
		free(s->tab[i]);
		i++;
	}
	free(s->tab[i]);
	free(s->tab);
}

/*
** Free the structure in which we created the adjencent matrix
*/

void			free_rooms(t_struct *s)
{
	int				i;

	i = 0;
	while (i < s->nb_rooms)
	{
		free(s->room[i]->name);
		free(s->room[i]->matrice);
		free(s->room[i]);
		i++;
	}
	free(s->room);
}

/*
** Free the selected path p and put a pointer to null to it
*/

void			free_path(t_struct *s, t_path *cpath)
{
	t_link			*element;
	t_link			*tmp;

	cpath->prev ? cpath->prev->next = cpath->next : 0;
	cpath->next ? cpath->next->prev = cpath->prev : 0;
	cpath == s->fpath ? s->fpath = s->fpath->next : 0;
	cpath == s->lpath ? s->lpath = s->lpath->prev : 0;
	element = cpath->first;
	while (element)
	{
		tmp = element;
		element = element->next;
		free(tmp);
	}
	free(cpath);
	cpath = NULL;
	s->nb_path--;
}

/*
** Free the structure with ants info
*/

void			free_ants(t_struct *s)
{
	int				i;

	i = 0;
	while (++i <= s->nb_ants)
		free(s->ant[i]);
	free(s->ant);
}

/*
** Free all before succeeded solve quit
*/

void			free_all(t_struct *s)
{
	t_path			*cpath;
	int				c;

	cpath = s->fpath;
	while (cpath)
	{
		free_path(s, cpath);
		cpath = cpath->next;
	}
	free_ants(s);
	free(s->str);
	c = 0;
	while (s->tab[c])
		free(s->tab[c++]);
	free(s->tab);
	free_rooms(s);
}
