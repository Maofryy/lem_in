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
}

int main(int ac, char **av)
{
    t_env e;
    t_paths *lst;

    //Read options
    (void)av;
    
    ft_init_env(&e);
    if (ac - e.ac_start >= 2)
        ft_print_usage(1);
    ft_init_env(&e);
    ft_parse_stdin(&e);
    ft_printf("Parsing finished\n\n");
    lst = ft_solve(e.mat);
    ft_print_ants(e.nb_ants, lst, e.mat);
    ft_free_env(&e, 0);
    return (0);
}