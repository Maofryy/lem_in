#include "lem_in.h"

void    ft_move_ants(t_env *e)
{
    int res_size;
    t_stack **queues;
    int n;

    // get e->results size
    res_size = ft_paths_size(e->results);
    ft_printf("res size = %d\n", res_size);
    queues = (t_stack **)ft_memalloc(sizeof(t_stack *) * (res_size + 1));
    // pushing each ant to their queue
    n = 0;
    while (++n <= e->nb_ants)
        ft_place_ant(e->results, 0, queues, n);
    ft_printf("printing queues :\n");
    int i = -1;
    while (++i < res_size)
        ft_stack_print(queues[i]);

    // change ant struct to adapt to the new results
    // re code what is actually in the ft_printc file
    // re code the ft_place_ant function accordingly
}