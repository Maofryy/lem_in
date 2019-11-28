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
    e->nb_rooms = 0;
    e->nb_tubes = 0;
}

int main(int ac, char **av)
{
    t_env e;

    //Read options
    (void)av;
    ft_init_env(&e);
    if (ac - e.ac_start >= 2)
        ft_print_usage(1);
    ft_init_env(&e);
    ft_parse_stdin(&e);
    ft_printf("---------------Parsing finished----------------\n");
    //check if cursors really correspond to the numbers provided, maybe other types of user error ?
    ft_printf("nb ants = %d\n", e.nb_ants);
    ft_printf("nb rooms = %d\n", e.nb_rooms);
    ft_printf("nb tubes = %d\n", e.nb_tubes);
    ft_printf("start = %s | end = %s\n", e.start_room, e.end_room);
    ft_free_env(&e, 0);
    ft_printf("%d\n", ft_isnum("1 12 15\n"));
    ft_printf("Ending main\n");
    return (0);
}