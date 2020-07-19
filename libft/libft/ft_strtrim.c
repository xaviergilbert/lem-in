/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:54:50 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/20 19:08:09 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*trim;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	k = i;
	while (s[k])
		k++;
	if (k != i)
		k--;
	while (ft_isspace(s[k]))
		k--;
	j = k;
	if (!(trim = (char*)malloc(sizeof(*trim) * (j - i + 2))))
		return (0);
	k = 0;
	while (i <= j)
		trim[k++] = s[i++];
	trim[k] = '\0';
	return (trim);
}
