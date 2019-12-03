#include "lem_in.h"

int     ft_intlst_size(int *src)
{
    int i;

    i = -1;
    while (src[++i] != -1)
        ;
    return (i);
}

int     ft_next_adj(int *v, int u, t_matrix *mat)
{
    (*v)++;
    while (mat->adj[u][*v] != 1 && *v < mat->size)
            (*v)++;
    if (*v >= mat->size)
        return (0);
    return (1);
}

int     ft_ucs(int start, int end, int size, t_matrix *mat)
{
    t_list *closed;
    t_list *open;
    int u;
    int v;

    open = ft_list_new(start);
    closed = ft_list_new(0);
    ft_list_pop(&closed);
    (void)size;
    while (ft_list_size(open) != 0)
    {
        u = (int)ft_list_pop(&open);
        if (u == end)
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
            if (ft_list_contains(open, v) || ft_list_contains(closed, v))
                continue ;
            ft_list_push_tail(&open, v);
        }
        ft_list_push_tail(&closed, u);
    }
    return (u);
}




int     **ft_solve(t_matrix *mat)
{
    int **path;

    // Linked list of pathS ?
    path = (int **)malloc(sizeof(int *) * 10);
    *path = (int *)malloc(sizeof(int) * 10);
    **path = ft_ucs(0, mat->size - 1, mat->size, mat);
    
    // while path isnt emtpy
    //      add to int **tab
    //      remove path from mat
    
    return (path);
}