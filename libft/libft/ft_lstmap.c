/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:06:26 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/17 18:49:33 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;
	t_list		*first;

	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	lst = lst->next;
	first = new;
	while (lst != NULL)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (first);
}
