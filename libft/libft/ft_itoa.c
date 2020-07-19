/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:05:29 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/13 19:48:22 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_end(int sign, int len, intmax_t stock, intmax_t n)
{
	char			*str;

	while (stock >= 10)
	{
		stock /= 10;
		len++;
	}
	if (!((str = (char*)malloc(sizeof(char) * len))))
		return (NULL);
	str[len] = '\0';
	while (len-- >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(intmax_t n)
{
	intmax_t		stock;
	int				len;
	char			*str;
	int				sign;

	len = 1;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
		len++;
	}
	stock = n;
	str = ft_end(sign, len, stock, n);
	return (str);
}
