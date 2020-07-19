/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:35:20 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:52:55 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Print a picture of all paths (still) present
*/

void			display_path(t_struct *s)
{
	t_path		*cpath;
	t_link		*element;
	int			i;

	i = 0;
	cpath = s->fpath;
	ft_printf("\nDisplay paths :\n\n");
	while (cpath)
	{
		ft_printf("path %i : ", i);
		element = cpath->first;
		while (element)
		{
			ft_printf("%s->", element->room->name);
			element = element->next;
		}
		ft_printf("%s\n", "NULL");
		cpath->next ? ft_printf("%5c\n", '^') : 0;
		cpath->next ? ft_printf("%5c\n", 'v') : 0;
		cpath = cpath->next;
		i++;
	}
	ft_printf("\n");
}

void			display_one_path(t_path *cpath)
{
	t_link		*element;

	ft_printf("path 1 : ");
	element = cpath->first;
	while (element)
	{
		ft_printf("%s->", element->room->name);
		element = element->next;
	}
	ft_printf("%s\n", "NULL");
}

/*
** Print the adjacent matrix
*/

void			display_matrice(t_struct *s)
{
	int			i;
	int			k;

	i = 0;
	ft_printf("\nDisplay matrice :\n\n");
	while (i < s->nb_rooms)
	{
		k = 0;
		ft_printf("%10s : ", s->room[i]->name);
		while (k < s->nb_rooms)
		{
			ft_printf("[%d]", s->room[i]->matrice[k]);
			k++;
		}
		ft_printf("\n");
		i++;
	}
}
