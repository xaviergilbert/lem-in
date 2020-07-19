/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:10:34 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:52:09 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Here we check if we do have two rooms with the same name
** If we do, we return error signal
*/

int				check_doublons_name(t_struct *s, int i)
{
	int			k;

	while (++i < s->nb_rooms)
	{
		k = i;
		while (++k < s->nb_rooms)
		{
			if (ft_strcmp(s->room[i]->name, s->room[k]->name) == 0)
				return (0);
		}
	}
	return (1);
}

/*
** Here we check if we do have two rooms with the same coordinates
** If we do, we return error signal
*/

int				check_doublons_coord(t_struct *s, int i)
{
	int			k;

	while (++i < s->nb_rooms)
	{
		k = i;
		while (++k < s->nb_rooms)
		{
			if (s->room[i]->x == s->room[k]->x
			&& s->room[i]->y == s->room[k]->y
			&& ft_strcmp(s->room[i]->name, s->room[k]->name) != 0)
				return (0);
		}
	}
	return (1);
}

/*
** We check if double coordinates or double name in rooms
** We set the index of each room in its int tab to 0 so we have no rooms linked
** to itself
** (if we do have a room linked to itself previously we just ignore it)
*/

int				check_errors2(t_struct *s)
{
	int			i;

	if (check_doublons_name(s, -1) == 0 || check_doublons_coord(s, -1) == 0)
		return (0);
	i = -1;
	while (++i < s->nb_rooms - 1)
		s->room[i]->matrice[i] = 0;
	return (1);
}
