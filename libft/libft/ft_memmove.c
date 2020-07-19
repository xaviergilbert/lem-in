/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:10:41 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/24 19:00:42 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char*)dst;
	source = (char*)src;
	if (source < dest)
	{
		while (len > 0)
		{
			len--;
			dest[len] = source[len];
		}
	}
	else
		ft_memcpy(dest, source, len);
	return (dest);
}
