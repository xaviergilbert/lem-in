/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:39:14 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/19 14:59:32 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** We free all paths not endind by the end room and point them to null
*/

void			del_no_ended_path(t_struct *s)
{
	t_path			*cpath;
	t_link			*element;

	cpath = s->fpath;
	while (cpath)
	{
		element = cpath->first;
		while (element->next)
		{
			element = element->next;
			cpath->path_len++;
		}
		cpath->path_len--;
		if (ft_strcmp(element->room->name, s->room[s->nb_rooms - 1]->name)
		!= 0)
			free_path(s, cpath);
		cpath = cpath->next;
	}
}

/*
** We sort path in our path tab by their length
*/

void			sort_by_len(t_struct *s)
{
	t_path			*cpath;
	t_path			*tmp;
	t_path			*tmp2;

	cpath = s->fpath;
	while (cpath)
	{
		if (cpath->prev && cpath->prev->path_len > cpath->path_len)
		{
			tmp = cpath->prev;
			tmp2 = cpath->next;
			cpath->next ? cpath->next->prev = cpath->prev : 0;
			cpath->next = cpath->prev;
			cpath->prev = cpath->prev->prev;
			tmp->next = tmp2;
			tmp->prev ? tmp->prev->next = cpath : 0;
			tmp->prev = cpath;
			cpath = s->fpath;
		}
		cpath = cpath->next;
	}
}

void			sort_path(t_struct *s)
{
	del_no_ended_path(s);
	sort_by_len(s);
}
