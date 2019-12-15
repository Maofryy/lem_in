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
    int ret;
    int flag;
    t_stack *path;

    l = 1;
    flag = 1;
    (void)e;
    ft_putchar('\n');
    while (flag)
    {
        i = -1;
        while (++i < res_size)
        {
            j = -1;
            // ft_printf("\nqueue %d = ", i);
            while (++j < l)
            {
                ret = stack_queue_look(queues[i], j);
                path = ft_paths_get(e->results, i);
                if (ret == e->nb_ants && (l - j == ft_stack_size(path) - 1))
                    flag = 0;
                if (ret == -1 || (l - j >= ft_stack_size(path)))
                    continue;
                ft_printf("L%d-%s ", ret, ft_get_room(e->rooms, ft_stack_getn(path, l - j))->label);
            }
        }
        l++;
        ft_putchar('\n');
        // ft_printf("\nNew line");
    }
}