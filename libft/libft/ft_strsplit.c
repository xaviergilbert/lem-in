/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:14:57 by xgilbert          #+#    #+#             */
/*   Updated: 2018/09/17 11:21:21 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while (s[i])
	{
		if (s[i++] == c)
			k++;
		while (s[i] == c)
		{
			i++;
			if (!(s[i] == c))
				k++;
		}
		i++;
	}
	return (k);
}

static int		ft_count_letters(char const *s, char c, int i)
{
	int		k;

	k = 1;
	while (s[i] != c && s[i])
	{
		k++;
		i++;
	}
	return (k);
}

static char		**splitsplit(char const *s, int c, char **split)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] == c)
			k++;
		if (s[k])
		{
			if (!(split[j] = (char*)malloc(sizeof(*split) *
			(ft_count_letters(s, c, k)))))
				return (0);
			i = 0;
			while (s[k] && s[k] != c)
				split[j][i++] = s[k++];
			split[j++][i] = '\0';
		}
	}
	split[j] = 0;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (0);
	if (!(split = (char**)malloc(sizeof(*split) * (ft_count_words(s, c) + 1))))
		return (0);
	split = splitsplit(s, c, split);
	return (split);
}
