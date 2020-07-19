/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:14:30 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 14:46:20 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** We check here if the line has the format of a room
*/

int				is_room(t_struct *s, int c)
{
	int			l;

	l = 0;
	if (s->tab[c][0] == 'L')
		return (0);
	if (char_in_str(s->tab[c], '-'))
		return (0);
	while (s->tab[c][l] && s->tab[c][l] != ' ')
		l++;
	l++;
	while (s->tab[c][l] && (s->tab[c][l] >= '0' && s->tab[c][l] <= '9'))
		l++;
	l++;
	while (s->tab[c][l] && (s->tab[c][l] >= '0' && s->tab[c][l] <= '9'))
		l++;
	if (s->tab[c][l])
		return (0);
	return (1);
}

/*
** We check here if the line has the format of a link
*/

int				is_link(t_struct *s, int c)
{
	int			l;

	l = 0;
	while (s->tab[c][l])
	{
		while (s->tab[c][l] && s->tab[c][l] != '-')
			l++;
		if (s->tab[c][l] == '-')
			l++;
		else
			return (0);
		while (s->tab[c][l] && s->tab[c][l] != ' ' && s->tab[c][l] != '-')
			l++;
		if (s->tab[c][l])
			return (0);
	}
	return (1);
}

/*
** We check if first line (ants) is positive number
** While we got a line
** -> if we have a comment we go next line
** -> else if we have a room and no link before we go next line
** -> else if we have a link we go next line
** -> else the line is not valid and we return error signal
*/

int				line_is_valid(t_struct *s, int *c)
{
	int			flag;

	if (!ft_isnumber(s->tab[0]) || ft_atoi(s->tab[0]) < 1)
		return (0);
	flag = 0;
	while (s->tab[(*c)])
	{
		if (s->tab[*c][0] == '#')
			(*c)++;
		else if (flag == 0 && (is_room(s, *c)))
			(*c)++;
		else if ((is_link(s, *c)))
		{
			(*c)++;
			flag = 1;
		}
		else
			return (0);
	}
	return (1);
}

/*
** Function check if the line is the start or end room
*/

int				is_extrem(t_struct *s, int c)
{
	c++;
	while (s->tab[c] && s->tab[c][0] == '#')
		c++;
	if (s->tab[c] && is_room(s, c))
		return (1);
	else
		return (0);
}

/*
** If a line is not valid, we free it in the tab and make it point to null,
** then we free the rest of the tab
** Then we check if we do have an end and a start room, if we don't, we return
** an error signal
*/

int				check_errors(t_struct *s, int c, int s_flag, int e_flag)
{
	while (s->tab[c] && s->tab[c][0] == '#')
		c++;
	if (!(s->tab[c]))
		return (0);
	if (!(line_is_valid(s, &c)))
	{
		free(s->tab[c]);
		s->tab[c++] = 0;
		while (s->tab[c])
			free(s->tab[c++]);
	}
	c = 0;
	while (s->tab[c])
	{
		ft_strcmp(s->tab[c], "##start") == 0
		&& is_extrem(s, c) == 1 ? s_flag++ : 0;
		ft_strcmp(s->tab[c], "##end") == 0
		&& is_extrem(s, c) == 1 ? e_flag++ : 0;
		c++;
	}
	if (e_flag == 1 && s_flag == 1)
		return (1);
	return (0);
}
