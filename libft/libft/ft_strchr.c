/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:28:09 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/15 11:57:33 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;
	char	*str;

	i = 0;
	str = (char*)s;
	c2 = (char)c;
	if (c2 == '\0')
		return (&str[ft_strlen(s)]);
	while (str[i])
	{
		if (str[i] == c2)
			return (&str[i]);
		else
			i++;
	}
	return (0);
}
