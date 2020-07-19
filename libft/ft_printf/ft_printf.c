/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:41:55 by xgilbert          #+#    #+#             */
/*   Updated: 2018/08/09 20:02:12 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_printf(t_format *s)
{
	s->modifier = 100;
	s->att_diese = 0;
	s->att_zero = 0;
	s->att_moins = 0;
	s->att_plus = 0;
	s->att_esp = 0;
	s->precision = 0;
	s->base = 0;
}

int			developpement2(va_list *args, const char *format,
		int i, t_format *s)
{
	char		*temp;

	if (format[s->k] == '%')
	{
		temp = ft_strndup(&format[s->k - i], i);
		s->k++;
		if (analyse(args, format, s))
		{
			free(temp);
			free(s->tmp);
			return (1);
		}
		s->str = ft_strjoin3(s->str, temp);
		s->str = ft_strjoin3(s->str, s->tmp);
	}
	else
		s->str = ft_strjoin1(s->str, &format[s->k - i]);
	return (0);
}

int			developpement(va_list *args, const char *format, t_format *s)
{
	int			i;

	while (format[s->k])
	{
		i = 0;
		init_printf(s);
		while (format[s->k] != '%' && format[s->k])
		{
			s->k++;
			i++;
		}
		if (developpement2(args, format, i, s))
			return (1);
	}
	return (0);
}

void		ft_printf2(t_format *s)
{
	size_t		i;

	s->len += ft_strlen(s->str);
	i = 0;
	while (i < s->len)
	{
		if (s->str[i] == BACK_SLASH)
			s->str[i] = '\0';
		ft_putchar(s->str[i]);
		i++;
	}
	free(s->str);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	t_format		s;

	s.k = 0;
	s.len = 0;
	s.str = ft_strdup("");
	if (format)
	{
		va_start(args, format);
		if (developpement(&args, format, &s))
		{
			ft_putstr(s.str);
			free(s.str);
			return (-1);
		}
		va_end(args);
	}
	ft_printf2(&s);
	return (s.len);
}
