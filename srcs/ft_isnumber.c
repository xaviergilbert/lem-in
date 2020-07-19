/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <xgilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 05:37:31 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/12 15:53:06 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				ft_isnumber(char *str)
{
	char			*tmp;
	int				i;

	i = 0;
	tmp = ft_itoa_base(ft_atoi(str), 10);
	if (ft_strcmp(str, tmp) != 0)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0' && i > 0)
		return (1);
	return (0);
}
