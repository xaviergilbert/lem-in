/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:00:25 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/07 15:36:53 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 127)
		ft_putchar(wc);
	else if (wc <= 2047)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 65535)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 1114111)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
}
