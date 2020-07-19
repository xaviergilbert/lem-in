/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:06:56 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 12:05:19 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		checkerrors(int fd, char **line)
{
	char			*buffer;
	int				vretour;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((vretour = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		*line = ft_strjoin1(*line, buffer);
		ft_bzero(buffer, BUFF_SIZE);
	}
	free(buffer);
	if (vretour == -1)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	if ((checkerrors(fd, line)) == -1)
		return (-1);
	return (1);
}
