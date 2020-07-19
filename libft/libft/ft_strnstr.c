/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:00:47 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/20 19:58:37 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int			i;
	size_t		j;
	int			k;
	char		*str2;

	i = 0;
	k = 0;
	str2 = (char*)str;
	if (to_find[i] == '\0')
		return (str2);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
			k = i;
		while (str[k] == to_find[j] && i + j < n)
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return (&str2[i]);
		}
		i++;
	}
	return (0);
}
