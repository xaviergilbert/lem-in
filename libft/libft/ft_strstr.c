/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:33:23 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/24 18:31:51 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
			k = i;
		while (str[k] == to_find[j])
		{
			k++;
			j++;
			if (to_find[j] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
