/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:22:53 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/20 14:25:11 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	while ((*alst)->next != NULL)
	{
		list = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = list;
	}
	ft_lstdelone(alst, del);
}
