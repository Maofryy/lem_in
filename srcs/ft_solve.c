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
    t_list *closed;
    t_list *open;
    t_stack *u;
    int v;


    open = ft_lstnew(ft_stack_new(start), sizeof(t_stack *));
    closed = ft_lstnew(0, sizeof(t_stack *));
    ft_lst_pop(&closed);
    (void)size;
    while (ft_lst_size(open) != 0)
    {
        u = (t_stack *)(ft_lst_pop(&open)->content);
        if (u->data == end)
            return (u);
        //Tant que v est adjacent de u;
        v = -1;
        while (ft_next_adj(&v, u, mat) == 1)
        {
            // le 1er trouve sera forcement le plus court vu qu'on cherche par "paliers"
            printf("v : %d\n", v);

            // ft_printf("open size = %d\n", ft_list_size(open));
            // ft_printf("closed size = %d\n", ft_list_size(closed));
            if (v == end)
                return (u);
            if (ft_lst_contains(open, v) || ft_lst_contains(closed, v))
                continue ;
            ft_stack_print(u);
            ft_stack_push_tail(&u, v);
            ft_printf("debug\n");
            ft_lst_push_tail(&open, ft_lstnew(u, sizeof(t_stack *)));
            ft_stack_pop(&u);
        }
        ft_lst_push_tail(&closed, ft_lstnew(u, sizeof(t_stack *)));
    }
    return (u);
}




t_list *ft_solve(t_matrix *mat)
{
    t_list *path;
    t_stack *spath;

    // Linked list of pathS ?

    path = ft_lstnew(ft_ucs(0, mat->size - 1, mat->size, mat), sizeof(t_stack *));
    (void)spath;
    ft_stack_print(path->content);
    // while path isnt emtpy
    //      add to int **tab
    //      remove path from mat
    
    return (path);
}