/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:05:39 by xgilbert          #+#    #+#             */
/*   Updated: 2018/06/20 14:22:32 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_stockwstr(wchar_t *wstr)
{
	char		*str;
	char		*str2;
	int			i;

	i = 0;
	if (wstr[i])
	{
		if ((str = ft_stockwchar(wstr[i++])) == 0)
			return (0);
	}
	while (wstr[i])
	{
		if ((str2 = ft_stockwchar(wstr[i++])) == NULL)
			return (NULL);
		str = ft_strjoin3(str, str2);
	}
	return (str);
}
