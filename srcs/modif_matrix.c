/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:33:23 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 14:52:00 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			lem_algo2(t_struct *s, int link, int vmatrice, int *flag)
{
	t_liste		*element;
	int			i;

	i = -1;
	while (++i < s->nb_rooms)
	{
		if (s->room[i]->matrice[link] > vmatrice
		|| (s->room[i]->matrice[link] == 1 && link != s->nb_rooms - 1))
		{
			s->room[i]->matrice[link] = vmatrice + 1;
			*flag = 1;
			element = s->liste;
			while (element)
			{
				element->k == link ? element->value = vmatrice + 1 : 0;
				element = element->next;
			}
		}
	}
}

void			init_matrix(t_struct *s, int i, int k)
{
	s->liste = NULL;
	while (++i < s->nb_rooms)
	{
		k = -1;
		while (++k < s->nb_rooms)
			s->room[i]->matrice[k] != 0 ? s->room[i]->matrice[k] = 1 : 0;
	}
}

void			del_one(t_struct *s)
{
	int			i;
	int			k;

	i = -1;
	while (++i < s->nb_rooms)
	{
		k = -1;
		while (++k < s->nb_rooms - 1)
		{
			if (s->room[i]->matrice[k] == 1)
				s->room[i]->matrice[k] = 0;
		}
	}
}

void			lem_algo(t_struct *s, int vmatrice, int flag)
{
	int			i;
	t_liste		*element;

	while (flag == 1)
	{
		flag = 0;
		i = -1;
		vmatrice++;
		element = s->liste;
		while (element)
		{
			if (element->value == vmatrice)
				lem_algo2(s, element->i, vmatrice, &flag);
			if (element->value < vmatrice && element->value != 1)
			{
				element->prev ? element->prev->next = element->next : 0;
				!element->prev ? s->liste = element->next : 0;
				element->next ? element->next->prev = element->prev : 0;
				free(element);
			}
			element = element->next;
		}
	}
	s->liste ? del_matrix_list(s) : 0;
}

void			modif_matrix(t_struct *s)
{
	int			i;
	int			k;
	int			flag;

	init_matrix(s, -1, -1);
	i = 0;
	while (++i < s->nb_rooms)
		s->room[i]->matrice[0] = 0;
	s->liste ? del_matrix_list(s) : 0;
	create_matrix_list(s);
	i = -1;
	flag = 1;
	while (++i < s->nb_rooms)
	{
		k = -1;
		if (s->room[i]->matrice[s->nb_rooms - 1] == 1)
		{
			while (++k < s->nb_rooms - 1)
				s->room[i]->matrice[k] = 0;
			lem_algo2(s, i, 1, &flag);
		}
	}
	lem_algo(s, 1, flag);
	del_one(s);
}
