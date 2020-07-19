/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:40:03 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/12 13:06:42 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!(concat = (char*)malloc(sizeof(*concat) * (a + i + 1))))
		return (0);
	concat = ft_strcpy(concat, s1);
	concat = ft_strcat(concat, s2);
	free((char*)s2);
	return (concat);
}
