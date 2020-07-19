/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:11:07 by xgilbert          #+#    #+#             */
/*   Updated: 2018/03/07 15:12:16 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t				*wstr;
	unsigned int		i;

	if (!(wstr = (wchar_t*)malloc(sizeof(*wstr) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		wstr[i] = 0;
		i++;
	}
	wstr[i] = 0;
	return (wstr);
}
