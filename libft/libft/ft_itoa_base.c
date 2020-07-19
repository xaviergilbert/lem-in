/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:30:09 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/18 12:17:42 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		taille_malloc(intmax_t nb, intmax_t base)
{
	int			i;

	i = 1;
	nb = ft_vabsolue(nb);
	while (nb >= base)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char			*ft_itoa_base(intmax_t nb, intmax_t base)
{
	char		*str;
	int			p;

	p = taille_malloc(nb, base);
	if (base < 2 || 16 < base || (base != 10 && nb < 0)
	|| !(str = (char *)malloc(sizeof(char) * p + 2)))
		return (NULL);
	p = 0;
	while (base <= ft_vabsolue(nb))
	{
		if (base > 10 && (ft_vabsolue(nb) % base >= 10))
			str[p++] = (ft_vabsolue(nb) % base) - 10 + 'a';
		else
			str[p++] = (ft_vabsolue(nb) % base) + '0';
		nb /= base;
	}
	if (base > 10 && (ft_vabsolue(nb) % base >= 10))
		str[p++] = (ft_vabsolue(nb) % base) - 10 + 'a';
	else
		str[p++] = (ft_vabsolue(nb) % base) + '0';
	if (base == 10 && nb < 0)
		str[p++] = '-';
	str[p] = '\0';
	return (ft_strrev(str));
}
