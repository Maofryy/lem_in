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
		ft_printf("Head is indeed empty\n");
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
		if (tube->room_1)
			free(tube->room_1);
		if (tube->room_2)
			free(tube->room_2);
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
		ft_printf(" %s-%s ", tmp->room_1, tmp->room_2);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_tube	*ft_create_tube(char **split)
{
	t_tube *net_tube;

	net_tube = ft_memalloc(sizeof(t_tube));
	// net_tube->n = ++e->cnt;
	net_tube->room_1 = ft_strdup(split[0]);
	net_tube->room_2 = ft_strdup(split[1]);
	ft_split_del(split);
	return (net_tube);
}

t_tube	*ft_duplicate_tube(t_tube *tube)
{
	t_tube *net_tube;

	net_tube = (t_tube*)malloc(sizeof(t_tube));
	// net_tube->n t_tube->n;
	net_tube->n = tube->n;
	net_tube->room_1 = ft_strdup(tube->room_1);
    net_tube->room_2 = ft_strdup(tube->room_2);
	return (net_tube);
}
