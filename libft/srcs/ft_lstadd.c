/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:23:29 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/20 09:23:31 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_lst_push_tail(t_list **s, t_list *new)
{
	t_list *t;

	t = *s;
	if (t == NULL)
		*s = new;
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
}

t_list	*ft_lst_pop(t_list **alst)
{
	t_list	*elem;

	if (alst == NULL || *alst == NULL)
		return (NULL);
	elem = *alst;
	*alst = elem->next;
	return (elem);
}

t_list	*ft_lst_pop_tail(t_list **alst)
{
	t_list	*elem;

	if (alst == NULL || *alst == NULL)
		return (NULL);
	else
	{
		elem = *alst;
		while (elem->next != NULL)
			elem = elem->next;
		*alst = elem->next;
	}
	return (elem);
}

int	ft_lst_size(t_list *s)
{
	t_list *t;
	int			i;

	t = s;
	if (t == NULL)
		return (0);
	i = 1;
	while (t->next != NULL)
	{
		t = t->next;
		i++;
	}
	return (i);
}