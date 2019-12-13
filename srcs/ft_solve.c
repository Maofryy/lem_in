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

t_stack    *ft_ucs(int start, int end, t_matrix *mat)
{
    t_stack *closed;
    t_paths *open;
    t_stack *u;
    t_stack *tmp;
    int v;

    u = ft_stack_new(start);
    // open = ft_lstnew((void *)u, sizeof(t_stack *));
    open = ft_paths_new(u);
    closed = ft_stack_new(start);
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

            ft_printf("testing v = %d at u = %d\n", u->data, v);
            // ft_printf("closed size = %d\n", ft_stack_size(closed));
            if (v == end)
            {
                ft_stack_push(&u, v);
                ft_stack_reverse(&u);
                ft_paths_del(&open);
                ft_stack_del(&closed);
                //ft_stack_print_labels(u, mat->labels);
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
    ft_paths_del(&open);
    ft_stack_del(&closed);
    return (NULL);
}

t_paths *ft_solve(t_matrix *mat)
{
    t_paths *path;

    // End towards start
    // path = ft_paths_new(ft_ucs(mat->size - 1, 0, mat));
    // Start to end
    path = ft_paths_new(ft_ucs(0, mat->size - 1, mat));
    while (path->s != NULL)
    {
        ft_matrix_remove_path(path->s, mat);
        // ft_print_matrix(*mat);
        ft_paths_push(&path, ft_ucs(mat->size - 1, 0, mat));
    }
    ft_paths_pop(&path);
    ft_paths_reverse(&path);
    // ft_paths_print(path, mat->labels);
    // ft_printf("path->s->data = %d\n", path->s->data);
    // ft_printf("path->s->next = %p\n", path->s->next);
    // while path isnt emtpy
    //      add to int **tab
    //      remove path from mat
    
    return (path);
}
