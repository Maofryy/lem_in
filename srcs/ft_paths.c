#include "lem_in.h"

t_paths *ft_paths_new(t_stack *new)
{
	t_paths *new_st;

	new_st = (t_paths *)malloc(sizeof(t_paths));
	new_st->s = new;
	new_st->next = NULL;
	return (new_st);
}

t_stack	*ft_paths_pop(t_paths **s)
{
	t_stack	*ret;
	t_paths	*next;

	if (*s == NULL)
		return (NULL);
	next = (*s)->next;
	ret = (*s)->s;
	free(*s);
	*s = next;
	return (ret);
}

void    ft_paths_push_tail(t_paths **s, t_stack *new)
{
    t_paths *push;
	t_paths *t;

	t = *s;
	push = ft_paths_new(new);
	if (t == NULL)
		*s = push;
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = push;
	}
}


int	ft_paths_contains(t_paths *s, int n)
{
	t_paths *t;

	t = s;
	if (t == NULL)
		return (0);
	while (t->next != NULL)
	{
		if (t->s->data == n)
			return (1);
		t = t->next;
	}
	return (0);
}

void	ft_paths_push(t_paths **s, t_stack *new_s)
{
	t_paths *new;

	new = ft_paths_new(new_s);
    if (s != NULL && new != NULL)
	{
		new->next = *s;
		*s = new;
	}
}

int	ft_paths_size(t_paths *s)
{
	t_paths *t;
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

void	ft_paths_print(t_paths *s, char **labels)
{
	t_paths *t;

	t = s;
	while (t != NULL)
	{
		ft_stack_print_labels(t->s, labels);
		t = t->next;
	}
}

void ft_paths_reverse(t_paths **s)
{ 
    t_paths *prev;
    t_paths *current;
    t_paths *next;

	prev = NULL;
	current = *s;
	next = NULL;
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *s = prev;
} 