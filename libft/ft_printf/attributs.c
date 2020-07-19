/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:08:07 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/28 14:19:03 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		attribut_plus(t_format *s)
{
	if (ft_atoi(s->tmp) >= 0 && s->att_zero != 1)
		s->tmp = ft_strjoin3(ft_strdup("+"), s->tmp);
	else if (ft_atoi(s->tmp) >= 0 && s->att_zero == 1 && s->tmp[0] == '0')
		s->tmp[0] = '+';
}

void		attribut_esp(t_format *s)
{
	if (s->tmp[0] == '\0')
		s->tmp = ft_strjoin3(ft_strdup(" "), s->tmp);
	else if (s->tmp[0] >= '0' && s->tmp[0] <= '9')
		s->tmp = ft_strjoin3(ft_strdup(" "), s->tmp);
}

void		attribut_diese(t_format *s)
{
	if (char_in_str("Oo", s->conv) == 1 && s->tmp[0] != '0')
		s->tmp = ft_strjoin3(ft_strdup("0"), s->tmp);
	else if ((char_in_str("x", s->conv) == 1) && ft_worth_zero(s->tmp) != 1)
	{
		if (s->tmp[0] == '0' && s->tmp[1] == '0')
			s->tmp[1] = 'x';
		else
			s->tmp = ft_strjoin3(ft_strdup("0x"), s->tmp);
	}
	else if ((char_in_str("X", s->conv) == 1) && ft_worth_zero(s->tmp) != 1)
	{
		if (s->tmp[0] == '0' && s->tmp[1] == '1')
			s->tmp[1] = 'X';
		else
			s->tmp = ft_strjoin3(ft_strdup("0X"), s->tmp);
	}
}

void		attribut_zero(const char *format, t_format *s)
{
	int			i;
	int			len;
	char		*temp;

	i = s->k;
	while ((format[i] < '1' || format[i] > '9') && format[i] != s->conv)
		i++;
	len = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	temp = ft_strndup(&format[len], i - len);
	len = ft_atoi(temp) - ft_strlen(s->tmp);
	free(temp);
	if (len <= 0)
		return ;
	temp = ft_strnew(len);
	s->tmp[0] == '-' ? i = -1 : 0;
	temp[len--] = '\0';
	s->att_esp == 1 ? len = len - 1 : 0;
	while (len >= 0)
		temp[len--] = '0';
	i == -1 ? s->tmp[0] = '0' : 0;
	s->tmp = ft_strjoin3(temp, s->tmp);
	i == -1 ? s->tmp[0] = '-' : 0;
}

void		attribut_moins(const char *format, t_format *s)
{
	char		*temp;
	int			len;
	int			i;

	i = s->k;
	while (!(ft_isdigit(format[i]) == 1)
	&& format[i] != s->conv)
		i++;
	if ((format[i] < '0' || format[i] > '9') || format[i - 1] == '.')
		return ;
	len = i;
	while (format[i] >= '0' && format[i] <= '9' && format[i])
		i++;
	temp = ft_strndup(&format[len], i - len);
	len = ft_atoi(temp) - ft_strlen(s->tmp);
	free(temp);
	if (len < 0)
		return ;
	temp = ft_strnew(len);
	temp[len--] = '\0';
	while (len >= 0)
		temp[len--] = ' ';
	s->tmp = ft_strjoin3(s->tmp, temp);
}
