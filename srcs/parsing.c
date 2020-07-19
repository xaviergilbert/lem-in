/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:31:57 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:54:14 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** We build the start and the end room
** If the end and the start room are the same, they will be considered
** as being duplicates and an error will be find later on
*/

void			if_start_or_end(t_struct *s, int c, int *flag, int f)
{
	if (ft_strcmp(s->tab[c], "##start") == 0)
	{
		while (s->tab[c] && s->tab[c][0] == '#')
			ft_strcmp(s->tab[c], "##end") == 0 ? f = 1 && c++ : c++;
		build_room(s, c, 0);
		f == 1 ? build_room(s, c, s->nb_rooms - 1) : 0;
		f == 0 ? s->tab[c][0] = '#' : 0;
		f == 1 ? *flag = 2 : (*flag)++;
	}
	else if (ft_strcmp(s->tab[c], "##end") == 0)
	{
		while (s->tab[c] && s->tab[c][0] == '#')
			ft_strcmp(s->tab[c], "##start") == 0 ? f = 1 && c++ : c++;
		build_room(s, c, s->nb_rooms - 1);
		f == 1 ? build_room(s, c, 0) : 0;
		f == 0 ? s->tab[c][0] = '#' : 0;
		f == 1 ? *flag = 2 : (*flag)++;
	}
}

/*
** While we do not have built both start and end room we go through the tab of
** input data
** While we do not have built all rooms
** -> while we are on a comment, we go next line
** -> If we are not on a comment or a link, we build the room
*/

void			parsing_room(t_struct *s, int c, int i)
{
	int			flag;

	flag = 0;
	if (!(s->room = (t_room**)malloc(sizeof(t_room) * s->nb_rooms)))
		exit(0);
	while (s->tab[c++] && flag != 2)
		if_start_or_end(s, c, &flag, 0);
	c = 1;
	while (i < s->nb_rooms - 1 && s->tab[c])
	{
		while (s->tab[c] && s->tab[c][0] == '#')
			c++;
		if (s->tab[c] && char_in_str(s->tab[c], '-') == 0)
		{
			build_room(s, c, i);
			i++;
		}
		c++;
	}
	s->room[s->nb_rooms] = NULL;
}

/*
** If we are on a link line, we try to build the link
** If it succeeds, we go next line and start over
** Else we make the line point on NULL and free rest of the tab
*/

void			parsing_links(t_struct *s, int c)
{
	while (s->tab[c])
	{
		if (char_in_str(s->tab[c], '-') && build_link(s, c, 0, -1) == 0)
		{
			while (s->tab[c])
			{
				free(s->tab[c]);
				s->tab[c++] = NULL;
			}
			break ;
		}
		c++;
	}
}

/*
** We initialize the adjency matrix
** Then return error signal if function check_errors2 find an error
*/

int				parsing(t_struct *s)
{
	int			i;
	int			k;

	i = 0;
	parsing_room(s, 0, 1);
	while (i < s->nb_rooms)
	{
		k = -1;
		if (!(s->room[i]->matrice = (int*)malloc(sizeof(int) * s->nb_rooms)))
			exit(0);
		while (++k < s->nb_rooms)
			s->room[i]->matrice[k] = 0;
		i++;
	}
	parsing_links(s, 0);
	if (!(check_errors2(s)))
		return (0);
	return (1);
}
