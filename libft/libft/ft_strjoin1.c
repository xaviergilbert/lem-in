/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:40:03 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/04 16:49:43 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin1(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!(concat = (char*)malloc(sizeof(*concat) * (a + i + 1))))
		exit(0);
	concat = ft_strcpy(concat, s1);
	concat = ft_strcat(concat, s2);
	free((char*)s1);
	return (concat);
}
