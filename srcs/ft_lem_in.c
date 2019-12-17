#include "lem_in.h"

void    ft_init_env(t_env *e)
{
    e->ac_start = 0;
    e->o_flag = 0;
    e->o_fd = 0;
    e->i_flag = 0;
    e->i_fd = 0;
    e->h_flag = 0;
    e->v_flag = 0;
    e->nb_ants = 0;
    e->queue = NULL;
    e->results = NULL;
    e->res = NULL;
    e->dist = NULL;
}

int main(int ac, char **av)
{
    t_env e;
    // t_paths *lst;

    //Read options
    (void)av;
    
    ft_init_env(&e);
    if (ac - e.ac_start >= 2)
        ft_print_usage(1);
    ft_init_env(&e);
    ft_parse_stdin(&e);
    // ft_printf("tube : %p\n", e.tubes);
    // ft_print_rooms(e.rooms);
    // ft_print_tubes(e.tubes);
    // ft_printf("Parsing finished\n\n");
    // lst = ft_solve(e.mat);
    ft_parse_path(&e);
    // ft_printf("paths parsed\n");
    // ft_print_paths(e);
    // ft_printf("Prbm at dijk ?\n");
    while (e.res == NULL || e.res[e.end_room] != -1)
    {
        dijkstra(&e);
        if (e.res[e.end_room] == -1)
            break;
        // Printing res and dist
        // int i = -1;

        // while (++i < e.cnt_room)
        // {
        //     // ft_printf("res[%s] = %s , dist = %ld\n", ft_get_room(e->rooms, i)->label,
        //     //     ft_get_room(e->rooms, e->res[i])->label, e->dist[i]);
        //     ft_printf("res[%d] = %d , dist = %ld\n", i, e.res[i], e.dist[i]);
        // }

        // Printing found path

    }
    // t_paths *tmp;
    // t_stack *s;
    if (ft_paths_size(e.results) == 0)
        ft_printf("Error : no path found\n");
    else
    {
        ft_paths_reverse(&e.results);
        ft_move_ants(&e);
    }
    ft_free_env(&e, 0);
    return (0);
}