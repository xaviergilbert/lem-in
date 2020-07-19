/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:22:53 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:53:27 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** We get here some information useful for further
*/

void			get_info(t_struct *s)
{
	int			c;

	c = 1;
	s->nb_ants = ft_atoi(s->tab[0]);
	while (s->tab[c])
	{
		if (char_in_str(s->tab[c], '-') == 1)
			s->nb_links++;
		else if (char_in_str(s->tab[c], '-') == 0 && s->tab[c][0] != '#'
		&& s->nb_links == 0)
			s->nb_rooms++;
		c++;
	}
}
