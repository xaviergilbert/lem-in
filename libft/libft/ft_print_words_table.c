/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:56:50 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/14 12:00:02 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_table(char **split)
{
	int		j;

	j = 0;
	while (split[j] != 0)
	{
		ft_putstr(split[j++]);
		ft_putchar('\n');
	}
}
