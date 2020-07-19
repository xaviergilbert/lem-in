/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_new_link.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:53:50 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 14:50:44 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				find_shorter_link(t_struct *s, int i)
{
	int				k;
	int				pos;
	int				value;

	k = 0;
	while (k < s->nb_rooms && s->room[i]->matrice[		k] == 0)
		k++;
	value = s->room[i]->matrice[k];
	pos = k;
	while (k < s->nb_rooms)
	{
		if (s->room[i]->matrice[k] != 0 && s->room[i]->matrice[k] < value)
		{
			value = s->room[i]->matrice[k];
			pos = k;
		}
		k++;
	}
	return (pos);
}

void			del_col(t_struct *s, int k)
{
	int				i;

	i = -1;
	while (++i < s->nb_rooms)
		s->room[i]->matrice[k] = 0;
}

/*
** We check if there is a link to the last room of the path and if the link
**is not a room already in the path
** We add the linked room to the path
*/

int				new_link2(t_struct *s, t_link *element, int m)
{
	if (element && ft_strcmp(s->room[m]->name, element->room->name) != 0)
	{
		if (!(element->next = (t_link*)malloc(sizeof(t_link))))
			exit(0);
		element->next->room = s->room[m];
		element = element->next;
		element->next = NULL;
		return (1);
	}
	return (0);
}

int				new_link(t_struct *s, t_path *cpath, int *m)
{
	t_link			*element;

	(*m)--;
	while (++(*m) < s->nb_rooms)
	{
		element = cpath->first;
		while (element->next
		&& ft_strcmp(s->room[*m]->name, element->room->name) != 0)
			element = element->next;
		if (new_link2(s, element, *m))
			return (1);
	}
	return (0);
}
