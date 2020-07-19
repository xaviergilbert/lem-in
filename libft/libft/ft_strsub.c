/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:18:55 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/20 18:46:43 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	strsub = (char*)malloc(sizeof(*strsub) * (len + 1));
	if (strsub == NULL)
		return (0);
	while (i < len)
		strsub[i++] = s[start++];
	strsub[i] = '\0';
	return (strsub);
}
