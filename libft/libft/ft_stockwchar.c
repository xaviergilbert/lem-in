/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:00:25 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/28 13:55:37 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*deux_bit(wchar_t wc, char *str)
{
	str[0] = ((wc >> 6) + 0xC0);
	str[1] = (wc & 0x3F) + 0x80;
	str[2] = '\0';
	return (str);
}

static char		*trois_bit(wchar_t wc, char *str)
{
	str[0] = (wc >> 12) + 0xE0;
	str[1] = ((wc >> 6) & 0x3F) + 0x80;
	str[2] = (wc & 0x3F) + 0x80;
	str[3] = '\0';
	return (str);
}

static char		*quatre_bit(wchar_t wc, char *str)
{
	str[0] = (wc >> 18) + 0xF0;
	str[1] = ((wc >> 12) & 0x3F) + 0x80;
	str[2] = ((wc >> 6) & 0x3F) + 0x80;
	str[3] = (wc & 0x3F) + 0x80;
	str[4] = '\0';
	return (str);
}

char			*ft_stockwchar(wchar_t wc)
{
	char	*str;

	str = ft_strnew(5);
	if (MB_CUR_MAX == 1)
	{
		if (wc > 255)
			return (NULL);
	}
	if (wc < 0 || wc > 0x10FFFF)
		return (NULL);
	if (wc >= 0xd800 && wc <= 0xdFFF)
		return (NULL);
	if (wc <= 127)
	{
		str[0] = wc;
		str[1] = '\0';
	}
	else if (wc <= 2047)
		str = deux_bit(wc, str);
	else if (wc <= 65535)
		str = trois_bit(wc, str);
	else if (wc <= 1114111)
		str = quatre_bit(wc, str);
	return (str);
}
