/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elimination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 12:00:14 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 14:49:08 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** We delete all path longer to reach the end from a given room compared to
**first path
*/

void			go_through_p2(t_struct *s, t_link *element,
				t_path *cpath, int i)
{
	t_path			*cpath2;
	t_link			*element2;
	int				j;

	cpath2 = cpath->next;
	while (cpath2)
	{
		element2 = cpath2->first;
		j = 0;
		while (element2->next
		&& ft_strcmp(element->room->name, element2->room->name) != 0)
		{
			element2 = element2->next;
			j++;
		}
		if (j <= cpath2->path_len &&
		(cpath2->path_len - j >= cpath->path_len - i || i == j))
			free_path(s, cpath2);
		cpath2 = cpath2->next;
	}
}

void			elimination(t_struct *s)
{
	t_path			*cpath;
	t_link			*element;
	int				i;

	cpath = s->fpath;
	while (cpath)
	{
		i = 0;
		element = cpath->first;
		while (element->next->next)
		{
			element = element->next;
			i++;
			go_through_p2(s, element, cpath, i);
		}
		cpath = cpath->next;
	}
}
