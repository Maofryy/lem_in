#include "lem_in.h"

t_room	*search_room(t_room *head, char *link)
{
	t_room *tmp;

	if (!link)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->label, link))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	add_room(t_room **head, t_room *room)
{
	t_room *tmp;

	tmp = *head;
	if (!tmp)
		*head = room;
	else
	{
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = room;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

t_room	*duplicate_room(t_room *room)
{
	t_room *new_room;

	new_room = (t_room*)malloc(sizeof(t_room));
	// new_room->n = room->n;
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
	free(tab);
}

t_room	*create_room(char **split)
{
	t_room *new_room;

	new_room = ft_memalloc(sizeof(t_room));
	// new_room->n = ++e->cnt;
	new_room->label = ft_strdup(split[0]);
	new_room->x_pos = ft_atoi(split[1]);
	new_room->y_pos = ft_atoi(split[2]);
	ft_split_del(split);
	return (new_room);
}