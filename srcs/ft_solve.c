#include "lem_in.h"

int     ft_lst_contains(t_list *l, int n)
{
    t_list *t;

	t = l;
	if (t == NULL)
		return (0);
	while (t->next != NULL)
	{
		// Compare
        if (((t_stack *)t->content)->data == n)
            return (1);
        t = t->next;
	}
    return (0);
}

int     ft_next_adj(int *v, t_stack *u, t_matrix *mat)
{
    (*v)++;
    while (mat->adj[u->data][*v] != 1 && *v < mat->size)
            (*v)++;
    if (*v >= mat->size)
        return (0);
    return (1);
}



t_stack    *ft_ucs(int start, int end, int size, t_matrix *mat)
{
    t_stack *closed;
    t_paths *open;
    t_stack *u;
    t_stack *tmp;
    int v;

    ft_printf("Start = %s and End = %s\n", mat->labels[start], mat->labels[end]);
    u = ft_stack_new(start);
    // open = ft_lstnew((void *)u, sizeof(t_stack *));
    open = ft_paths_new(u);
    closed = ft_stack_new(start);
    (void)size;
    while (ft_paths_size(open) != 0)
    {
        u = ft_paths_pop(&open);
        if (u->data == end)
            return (u);
        //Tant que v est adjacent de u;
        
        v = -1;
        while (ft_next_adj(&v, u, mat) == 1)
        {
            // le 1er trouve sera forcement le plus court vu qu'on cherche par "paliers"

            // ft_printf("open size = %d\n", ft_list_size(open));
            // ft_printf("closed size = %d\n", ft_stack_size(closed));
            if (v == end)
            {
                ft_stack_push(&u, v);
                return (u);
            }
            // ft_printf("u = %s | v = %s\n", mat->labels[u->data], mat->labels[v]);
            if (ft_paths_contains(open, v) || ft_stack_contains(closed, v))
                continue ;
            tmp = ft_stack_copy(u);
            ft_stack_push(&tmp, v);
            ft_paths_push_tail(&open, tmp);
        }
        ft_stack_push(&closed, u->data);
    }
    return (u);
}

t_paths *ft_solve(t_matrix *mat)
{
    t_paths *path;

    // Linked list of pathS ?
    
    path = ft_paths_new(ft_ucs(0, mat->size - 1, mat->size, mat));

    ft_stack_print_labels(path->s, mat->labels);
    // ft_printf("path->s->data = %d\n", path->s->data);
    // ft_printf("path->s->next = %p\n", path->s->next);
    // while path isnt emtpy
    //      add to int **tab
    //      remove path from mat
    
    return (path);
}
