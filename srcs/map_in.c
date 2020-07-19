/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:00:11 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:53:58 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				map_in(t_struct *s)
{
	t_map			*element;
	char			*line;

	s->map_head = NULL;
	if ((get_next_line(0, &line)) > 0)
	{
		element = (t_map*)malloc(sizeof(t_map));
		s->map_head = element;
		element->str = ft_strdup(line);
		free(line);
		element->suivant = NULL;
		s->map_tail = element;
	}
	while ((get_next_line(0, &line)) > 0)
	{
		element->suivant = (t_map*)malloc(sizeof(t_map));
		element->suivant->precedent = s->map_tail;
		s->map_tail = element->suivant;
		element = s->map_tail;
		element->str = ft_strdup(line);
		free(line);
		element->suivant = NULL;
	}
	return (0);
}
