#include "lem_in.h"

void	ft_read_options(int ac, char **av, t_env *e)
{
    int i;
    int flag;

    i = e->ac_start;
    flag = 1;
    if (ac < 2)
            return ;
    while (flag)
    {
        if (ft_strequ(av[i], "-o") && i < ac - 1 && av[i + 1])
        {
            e->o_flag = 1;
            e->o_filename = ft_strdup(av[i + 1]);
            e->ac_start += 2;
            i += 2;
        }
        else if (ft_strequ(av[i], "-f") && i < ac - 1 && av[i + 1])
        {
            e->i_flag = 1;
            e->i_filename = ft_strdup(av[i + 1]);
            e->ac_start += 2;
            i += 2;
        }
        
        else if (ft_strequ(av[i], "-v"))
        {
            e->v_flag = 1;
            e->ac_start += 1;
            i += 1;
        }
        else if (ft_strequ(av[i], "-h") || (av[i] && av[i][0] == '-' && !IS_NUM(av[i][1])))
        {
            e->h_flag = 1;
            e->ac_start += 1;
            i += 1;
            flag = 0;
        }
        else
            flag = 0;
    }
}

int    ft_open_input(int flag, char *filename, t_env *e)
{
    int fd;

    if (flag)
    {
        fd = open(filename, O_RDONLY);
        if (fd == -1)
        {
            ft_dprintf(2, "Error opening intput file\n");
            ft_free_env(e, 1);
        }
        return (fd);
    }
    return (0);
}

void    ft_close_input(t_env *e)
{
    if (e->i_flag)
    {
        if (close(e->i_fd) == -1)
        {
            ft_dprintf(2, "Error closing intput file\n");
            ft_free_env(e, 1);
        }
    }
}

void    ft_open_o(t_env *e)
{
    if (e->o_flag)
    {
        int fd;

        fd = open(e->o_filename,  O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
        if (fd == -1)
        {
            ft_dprintf(2, "Error opening output file\n");
            ft_free_env(e, 1);
        }
        e->o_fd = fd;
    }
}

void    ft_close_o(t_env *e)
{
    if (e->o_flag)
    {
        if (close(e->o_fd) == -1)
        {
            ft_dprintf(2, "Error closing output file\n");
            ft_free_env(e, 1);
        }
    }
}