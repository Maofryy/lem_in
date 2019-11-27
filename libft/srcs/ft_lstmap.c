/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:21:16 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/20 15:16:56 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*list;

	if (lst == NULL)
		return (NULL);
	ret = (*f)(lst);
	list = ret;
	while (lst->next)
	{
		lst = lst->next;
		if ((list->next = (*f)(lst)) == NULL)
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (ret);
}
