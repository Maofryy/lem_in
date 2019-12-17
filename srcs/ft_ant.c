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
    int *popped;
    int ssize;
    int size;
    t_stack *path;

    l = 1;
    (void)e;
    popped = (int *)ft_memalloc(sizeof(int) * (res_size + 1));
    ft_putchar('\n');
    while (flag != res_size)
    {
        i = -1;
        flag = 0;
        while (++i < res_size)
        {
            j = -1;

            
            path = ft_paths_get(e->results, i);
            size = ft_stack_size(path);
            if (queues[i] != NULL && l - popped[i] > ft_stack_size(path) - 1)
            {
                stack_queue_pop(&queues[i]);
                popped[i]++;
                // ft_printf("popped[%d] = %d | l = %d | ssize = %d\n", i, popped[i], l, ssize);
            }
            if (queues[i] == NULL)
            {
                flag++;
                continue;
            }
            ssize = ft_stack_size(queues[i]);

            // //print queue
            // ft_printf("queue[%d] ssize = %d | ", i, ssize);
            // while (++j + popped[i] < l && j < ssize)
            //     ft_printf("%d ", stack_queue_look(queues[i], j));
            // ft_putchar('\n');

            j = -1;
            // ft_printf("ants : ");
            while (++j + popped[i] < l && j < ssize)
            {
                ret = stack_queue_look(queues[i], j);
                // ft_printf("\nret = %d | [1] = %d | [2] = %d : ", ret, l - j - popped[i], ft_stack_size(path) - 1);
                if (ret == -1 || (l - j - popped[i] > size - 1))
                    continue ;
                ft_printf("L%d-%s ", ret, ft_get_room(e->rooms, ft_stack_getn(path, l - j - popped[i]))->label);
                // ft_printf("L%d- ", ret);
            }
        }
        l++;
        ft_putchar('\n');
        // ft_printf("\nNew line");
    }
    free (popped);
}