/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:00:42 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 14:50:00 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			del_matrix_list(t_struct *s)
{
	t_liste			*element;
	t_liste			*tmp;

	element = s->liste;
	while (element)
	{
		tmp = element;
		element = element->next;
		free(tmp);
	}
	s->liste = NULL;
}

void			create_matrix_list2(t_struct *s, t_liste **element,
				t_liste **tmp, int i)
{
	int				k;

	k = -1;
	while (++k < s->nb_rooms)
	{
		if (s->room[i]->matrice[k] != 0 && i < s->nb_rooms && k < s->nb_rooms)
		{
			(*element) = (t_liste*)malloc(sizeof(t_liste));
			if (!*tmp)
				(*element)->prev = NULL;
			else
			{
				(*element)->prev = *tmp;
				(*tmp)->next = (*element);
			}
			(*element)->next = NULL;
			(*element)->value = s->room[i]->matrice[k];
			(*element)->i = i;
			(*element)->k = k;
			*tmp = *element;
			*element = (*element)->next;
		}
	}
}

void			create_matrix_list(t_struct *s)
{
	t_liste			*element;
	t_liste			*tmp;
	int				i;

	i = -1;
	tmp = NULL;
	while (++i < s->nb_rooms)
	{
		element ? element = NULL : 0;
		create_matrix_list2(s, &element, &tmp, i);
	}
	element = tmp;
	while (element && element->prev)
	{
		element = element->prev;
	}
	s->liste = element;
}
