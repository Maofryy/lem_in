#include "libft.h"
# define INT_MIN -2147483648

t_stack *ft_stack_new(int const data)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_stack_push_tail(t_stack **s, int new_data)
{
	t_stack *new;
	t_stack *t;

	t = *s;
	new = ft_stack_new(new_data);
	if (t == NULL)
		*s = new;
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
}

// To change lata
long int	ft_stack_pop_tail(t_stack **s)
{
	int			ret;
	t_stack	*t;

	ret = 0;
	if (*s == NULL)
		return (INT_MIN - 1);
	if ((*s)->next == NULL) {
			ret = (*s)->data;
			free((*s));
			return ((int)ret);
	}
	t = (*s);
	while (t->next->next != NULL) {
			t = t->next;
	}
	ret = t->next->data;
	free(t->next);
	t->next = NULL;
	return ((int)ret);
}

void	ft_stack_push(t_stack **s, int new_data)
{
	t_stack *new;

	new = ft_stack_new(new_data);
	if (s != NULL && new != NULL)
	{
		new->next = *s;
		*s = new;
	}
}

long int	ft_stack_pop(t_stack **s)
{
	int			ret;
	t_stack	*next;

	if (*s == NULL)
		return (INT_MIN - 1);
	next = (*s)->next;
	ret = (*s)->data;
	free(*s);
	*s = next;
	return ((int)ret);
}

int	ft_stack_size(t_stack *s)
{
	t_stack *t;
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

void	ft_stack_del(t_stack **s)
{
	t_stack *t;

	if (*s == NULL)
		return ;
	while ((*s)->next != NULL)
	{
		t = (*s)->next;
		free(*s);
		*s = t;
	}
	free(*s);
}

void	ft_stack_print(t_stack *s)
{
	t_stack *t;

	t = s;
	ft_printf("stack | ");
	while (t != NULL && t->next != NULL)
	{
		ft_printf("%d ", t->data);
		t = t->next;
	}
	ft_printf(" |\n");
}

int	ft_stack_contains(t_stack *s, int n)
{
	t_stack *t;

	t = s;
	if (t == NULL)
		return (0);
	while (t->next != NULL)
	{
		if (t->data == n)
			return (1);
		t = t->next;
	}
	return (0);
}

t_stack *ft_stack_copy(t_stack *s)
{
        t_stack *d;

        if (s == NULL)
                return (NULL);
        else if (s->next == NULL)
                return (ft_stack_new(s->data));
        else
        {
                while (s->next != NULL)
                {
                        ft_stack_push(&d, s->data);
                        s = s->next;
                }
        }
        return (d);
}
