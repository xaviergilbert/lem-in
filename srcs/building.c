/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:42:24 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:51:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** We set the name of the room of the line of the files we are in, plus its
**coordonates
*/

void			build_room(t_struct *s, int c, int i)
{
	char			*tmp;
	int				k;
	int				l;

	l = 0;
	if (!(s->room[i] = (t_room*)malloc(sizeof(t_room))))
		exit(0);
	if (s->tab[c][0] == '#')
		return ;
	while (s->tab[c][l] != ' ')
		l++;
	s->room[i]->name = ft_strndup(s->tab[c], l);
	l++;
	k = l;
	while (s->tab[c][l] != ' ')
		l++;
	tmp = ft_strndup(&s->tab[c][k], l);
	s->room[i]->x = ft_atoi(tmp);
	free(tmp);
	l++;
	tmp = ft_strdup(&s->tab[c][l]);
	s->room[i]->y = ft_atoi(tmp);
	free(tmp);
}

/*
** We are here seeking for the linked room
** We check if the string is matching a room name
** If it is not, we return an error signal, and we will not consider further
**information
** Else we return the matched room
*/

int				find_linked_room(t_struct *s, char *str)
{
	int				k;

	k = 0;
	while (k < s->nb_rooms && ft_strcmp(s->room[k]->name, str) != 0)
		k++;
	if (k == s->nb_rooms)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (k);
}

/*
** We check if the first part of the string match a room name
** If it is we check if the second part match a room name
** If it is we build the link by setting to 1 the index of each room linked  in
**the int table of each room
*/

int				build_link(t_struct *s, int c, int l, int i)
{
	int				k;
	char			*tmp;

	while (s->tab[c][l] != '-')
		l++;
	tmp = ft_strndup(s->tab[c], l);
	while (++i < s->nb_rooms)
	{
		if (ft_strcmp(tmp, s->room[i]->name) == 0)
		{
			l++;
			free(tmp);
			k = find_linked_room(s, ft_strndup(&s->tab[c][l],
						ft_strlen(s->tab[c]) - l));
			k != -1 ? s->room[i]->matrice[k] = 1 : 0;
			k != -1 ? s->room[k]->matrice[i] = 1 : 0;
			if (k == -1)
				return (0);
			return (1);
		}
	}
	free(tmp);
	return (0);
}
