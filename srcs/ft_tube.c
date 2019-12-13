#include "lem_in.h"

t_tube *ft_get_tube(t_tube *head, int index)
{
	t_tube *tmp;
	int i;

	i = 0;
	if (!head)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		if (i == index)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

void	ft_add_tube(t_tube **head, t_tube *tube)
{
	t_tube *tmp;

	tmp = *head;
	if (!tmp)
	{
		*head  = tube;
	}
	else
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = tube;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void ft_del_tube(t_tube *tube)
{
	if (tube)
	{
		ft_del_tube(tube->next);
		free(tube);
	}
}

void ft_print_tubes(t_tube *head)
{
	t_tube *tmp;

	if (!head)
		return;
	tmp = head;
	ft_printf("tubes :");
	while (tmp)
	{
		ft_printf(" %d-%d ", tmp->room_1, tmp->room_2);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_tube	*ft_create_tube(t_parser *p, char **split)
{
	t_tube *new_tube;
	t_room *room_1;
	t_room *room_2;

	room_1 = ft_search_room(p->rooms, split[0]);
	room_2 = ft_search_room(p->rooms, split[1]);
	new_tube = ft_memalloc(sizeof(t_tube));
	new_tube->n = p->cnt_tube;
	new_tube->room_1 = room_1->n;
	new_tube->room_2 = room_2->n;
	new_tube->next = NULL;
	ft_split_del(split);
	return (new_tube);
}

t_tube	*ft_duplicate_tube(t_tube *tube)
{
	t_tube *net_tube;

	net_tube = (t_tube*)malloc(sizeof(t_tube));
	net_tube->n = tube->n;
	net_tube->room_1 = tube->room_1;
    net_tube->room_2 = tube->room_2;
	return (net_tube);
}
