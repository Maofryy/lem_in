#include "lem_in.h"

// char *ft_get_room_label(t_room *head, int index)
// {
// 	return (ft_get_room(head, index)->label);
// }

t_room *ft_get_room(t_room *head, int index)
{
	t_room *tmp;

	if (!head || index < 0)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		if (tmp->n == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*ft_search_room(t_room *head, char *tube)
{
	t_room *tmp;

	if (!tube)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		// ft_printf("%s == %s\n", tmp->label, tube);
		if (!ft_strcmp(tmp->label, tube))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_print_rooms(t_room *head)
{
	t_room *tmp;

	if (!head)
		return ;
	tmp = head;
	ft_printf("rooms :");
	while (tmp)
	{
		ft_printf(" %s ", tmp->label);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_add_room(t_room **head, t_room *room)
{
	t_room *tmp;

	tmp = *head;
	if (!tmp)
		*head = room;
	else
	{
		while (tmp)
		{			
			if (tmp->next == NULL)
			{
				tmp->next = room;
				return ;
			}
			tmp = tmp->next;
		}
		
	}
}

void 	ft_del_room(t_room *room)
{
	if (room)
	{
		if (room->label)
			free(room->label);
		ft_del_room(room->next);
		free(room);
	}
}

t_room	*ft_duplicate_room(t_room *room)
{
	t_room *new_room;

	new_room = (t_room*)malloc(sizeof(t_room));
	new_room->n = room->n;
	new_room->label = ft_strdup(room->label);
	new_room->x_pos = room->x_pos;
	new_room->y_pos = room->y_pos;
	return (new_room);
}

void	ft_split_del(char **split)
{
	int i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	ft_tab_del(int **tab, int size)
{
	int i;

	i = -1;
	while (++i < size)
        free(tab[i]);
}

t_room	*ft_create_room(t_parser *p, char **split)
{
	t_room *new_room;

	new_room = ft_memalloc(sizeof(t_room));
	new_room->n = p->cnt_room;
	new_room->label = ft_strdup(split[0]);
	new_room->x_pos = ft_atoi(split[1]);
	new_room->y_pos = ft_atoi(split[2]);
	new_room->next = NULL;
	ft_split_del(split);
	return (new_room);
}