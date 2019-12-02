#include "libft.h"
# define INT_MIN -2147483648

t_list *ft_list_new(int const data)
{
	t_list *new;

	new = ft_lstnew(&data, sizeof(data));
	return (new);
}

void	ft_list_push_tail(t_list **s, int new_data)
{
	t_list *new;
	t_list *t;

	t = *s;
	new = ft_list_new(new_data);
	if (t == NULL)
		*s = new;
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
}

long int	ft_stack_pop_tail(t_list **s)
{
	int			ret;
	t_list	*t;

	ret = 0;
	if (*s == NULL)
		return (INT_MIN - 1);
	if ((*s)->next == NULL) {
			ret = (int)(*s)->content;
			free((*s));
			return ((int)ret);
	}
	t = (*s);
	while (t->next->next != NULL) {
			t = t->next;
	}
	ret = (int)t->next->content;
	free(t->next);
	t->next = NULL;
	return ((int)ret);
}

void	ft_lst_push(t_list **s, int new_data)
{
	t_list *new;

	new = ft_list_new(new_data);
	if (s != NULL && new != NULL)
	{
		new->next = *s;
		*s = new;
	}
}

long int	ft_lst_pop(t_list **s)
{
	int			ret;
	t_list	*next;

	if (*s == NULL)
		return (INT_MIN - 1);
	next = (*s)->next;
	ret = (int)(*s)->content;
	free(*s);
	*s = next;
	return ((int)ret);
}

int	ft_list_size(t_list *s)
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

void	ft_list_del(t_list **s)
{
	t_list *t;

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