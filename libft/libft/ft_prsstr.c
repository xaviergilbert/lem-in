/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prsstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:34:06 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/18 18:25:20 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_prsstr(char *str, char *smth)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i] && smth[j])
	{
		j = 0;
		k = i;
		while (str[i] == smth[j] && smth[j])
		{
			i++;
			j++;
		}
		if (smth[j] == '\0')
			return (1);
		else
			i = k + 1;
	}
	return (0);
}
