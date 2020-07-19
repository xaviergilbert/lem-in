/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:45:02 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/03 16:31:18 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char			*ft_strcpy_until_c(char *dest, const char *src, char c)
{
	int			i;

	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
