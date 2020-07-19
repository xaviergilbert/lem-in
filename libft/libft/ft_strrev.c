/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:02:46 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/21 19:05:36 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char		*newstr;
	int			i;
	int			k;

	i = ft_strlen(str);
	newstr = ft_strnew(i);
	k = 0;
	while (--i >= 0)
		newstr[k++] = str[i];
	newstr[k] = '\0';
	free(str);
	return (newstr);
}
