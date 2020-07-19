/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:27:28 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/21 13:41:14 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precision(const char *format, t_format *s)
{
	if (s->precision == 0)
		return ;
	if (char_in_str("oOuUxXdidD", s->conv))
		precision_nbr(format, s);
	else if (char_in_str("sS", s->conv))
		precision_str(format, s);
	if (s->precision == 2 && ft_worth_zero(s->tmp) == 1)
	{
		free(s->tmp);
		s->tmp = ft_strdup("");
		return ;
	}
}

void		precision_nbr(const char *format, t_format *s)
{
	int		i;
	char	*temp;
	int		len;

	i = s->k;
	while (format[i - 1] != '.')
		i++;
	len = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	temp = ft_strndup(&format[len], i - len);
	len = ft_atoi(temp) - ft_strlen(s->tmp);
	free(temp);
	if (len < 0)
		return ;
	temp = ft_strnew(len);
	ft_atoi(s->tmp) < 0 ? i = -1 : 0;
	i == -1 ? len = len + 1 : 0;
	temp[len--] = '\0';
	while (len >= 0)
		temp[len--] = '0';
	i == -1 ? s->tmp[0] = '0' : 0;
	s->tmp = ft_strjoin3(temp, s->tmp);
	i == -1 ? s->tmp[0] = '-' : 0;
}

void		precision_str(const char *format, t_format *s)
{
	int		i;
	int		nb;
	char	*temp;
	int		len;

	i = s->k;
	while (format[i - 1] != '.' && format[i])
		i++;
	if (format[i] == '\0')
		return ;
	nb = i;
	while (format[i] >= '0' && format[i] <= '9' && format[i])
		i++;
	temp = ft_strndup(&format[nb], i - nb);
	len = ft_atoi(temp);
	free(temp);
	if (len >= (int)ft_strlen(s->tmp))
		return ;
	else
	{
		temp = ft_strdup(s->tmp);
		free(s->tmp);
		s->tmp = ft_strndup(temp, len);
		free(temp);
	}
}
