/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:34:15 by xgilbert          #+#    #+#             */
/*   Updated: 2018/11/14 00:29:13 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_info_printf(const char *format, t_format *s)
{
	int		i;
	char	*temp;

	i = s->k;
	get_conv(&format[s->k], s);
	while (format[i] != s->conv && format[i])
		i++;
	if (format[i] == '\0')
	{
		ft_putendl("Veuillez preciser un format de conversion svp...");
		exit(0);
	}
	temp = ft_strndup(&format[s->k], i - s->k + 1);
	get_modifier(temp, s);
	get_precision(temp, s);
	get_attribut(temp, s);
	free(temp);
}

void		get_conv(const char *str, t_format *s)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_strdup("sSpdDioOuUxXcC%");
	i = 0;
	while (str[i])
	{
		j = 0;
		while (temp[j])
		{
			if (str[i] == temp[j])
			{
				s->conv = temp[j++];
				free(temp);
				return ;
			}
			else
				j++;
		}
		i++;
	}
	free(temp);
}

void		get_modifier(char *str, t_format *s)
{
	if (ft_prsstr(str, "ll"))
		s->modifier = MDF_LL;
	else if (ft_prsstr(str, "hh"))
		s->modifier = MDF_HH;
	else if (char_in_str(str, 'h'))
		s->modifier = MDF_H;
	else if (char_in_str(str, 'l'))
		s->modifier = MDF_L;
	else if (char_in_str(str, 'j'))
		s->modifier = MDF_J;
	else if (char_in_str(str, 'z'))
		s->modifier = MDF_Z;
	s->conv == 'o' || s->conv == 'O' ? s->base = 8 : 0;
	s->conv == 'x' || s->conv == 'X' ? s->base = 16 : 0;
	s->conv == 'u' || s->conv == 'U' ? s->base = 10 : 0;
}

void		get_attribut(char *str, t_format *s)
{
	int		i;

	i = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i])
		i++;
	if (char_in_str(str, '-'))
		s->att_moins = 1;
	if (char_in_str(str, '+'))
		s->att_plus = 1;
	if (char_in_str(str, '#'))
		s->att_diese = 1;
	if (str[i] == '0' && s->att_moins != 1 && s->precision == 0)
		s->att_zero = 1;
	if (char_in_str(str, ' ') && !(s->att_plus))
		s->att_esp = 1;
}

void		get_precision(char *str, t_format *s)
{
	int		i;

	i = 0;
	if (char_in_str(str, '.'))
		s->precision = 1;
	if (s->precision == 1)
		s->att_zero = 0;
	while (str[i] != '.' && str[i])
		i++;
	if (str[i] == '.' && (str[i + 1] < '1' || str[i + 1] > '9'))
		s->precision = 2;
	if (s->conv == '%')
		s->precision = 0;
}
