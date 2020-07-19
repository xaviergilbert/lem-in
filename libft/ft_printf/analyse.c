/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:50:55 by xgilbert          #+#    #+#             */
/*   Updated: 2018/11/14 00:27:18 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			analyse(va_list *args, const char *format, t_format *s)
{
	if (format[s->k] == '%')
	{
		s->tmp = ft_strdup("%");
		s->k++;
		return (0);
	}
	get_info_printf(format, s);
	if (conversion(args, s))
		return (1);
	caractere_attribut1(format, s);
	precision(format, s);
	caractere_attribut2(format, s);
	largeur_champs(format, s);
	while (format[s->k] != s->conv && format[s->k])
		s->k++;
	s->k++;
	return (0);
}

void		caractere_attribut1(const char *format, t_format *s)
{
	if (s->att_zero == 1 && (char_in_str("dDioOuUxX%", s->conv)))
		attribut_zero(format, s);
}

void		caractere_attribut2(const char *format, t_format *s)
{
	if (s->att_esp == 1 && s->att_plus == 0)
		attribut_esp(s);
	if (s->att_plus == 1 && (char_in_str("uUdDioOxX", s->conv)))
		attribut_plus(s);
	if (s->att_diese == 1 && (char_in_str("oOxX", s->conv)))
		attribut_diese(s);
	if (s->att_moins == 1)
		attribut_moins(format, s);
}
