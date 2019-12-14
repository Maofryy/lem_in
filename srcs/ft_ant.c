#include "lem_in.h"

void   ft_place_ant(t_paths *paths, int path_cursor, t_stack **queues, int n)
{
    if (path_cursor == ft_paths_size(paths) - 1)
    {
        stack_queue_push(&queues[path_cursor], n);
        path_cursor = 0;
    }
    else if (ft_stack_size(queues[path_cursor]) + ft_stack_size(ft_paths_get(paths, path_cursor)) 
                < ft_stack_size(queues[path_cursor + 1]) + ft_stack_size(ft_paths_get(paths, path_cursor + 1)))
    {
        stack_queue_push(&queues[path_cursor], n);
        path_cursor = 0;
    }
    else
        ft_place_ant(paths, path_cursor + 1, queues, n);
}

void ft_print_ants(t_env *e, t_stack **queues, int res_size)
{
    int l;
    int i;
    int j;
    int flag;

    l = 1;
    flag = 4;
    (void)e;
    while (flag)
    {
        i = -1;
        while (++i < res_size)
        {
            j = -1;
            ft_printf("\nqueue %d = ", i);
            while (++j < l)
                ft_printf(" %d ", stack_queue_look(queues[i], j));
        }
        l++;
        ft_printf("\nNew line");
        flag--;
    }
}