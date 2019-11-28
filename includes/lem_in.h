#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef struct      s_room
{
    char    *label;
    int     x_pos;
    int     y_pos;
}                   t_room;

typedef struct      s_tube
{
    char    *label;
    char    *room_1;
    char    *room_2;
}                   t_tube;

typedef struct      s_parser
{
    long     nb_ants;
    int     nb_rooms;
    int     cursor_rooms;
    int     nb_tubes;
    int     cursor_tubes;
    int     start_flag;
    char    *start_room;
    int     end_flag;
    char    *end_room;
    t_room  *room;
    t_tube  *tube;
}                   t_parser;

typedef struct      s_env
{
    int     ac_start;
    int     o_flag;
    char    *o_filename;
    int     o_fd;
    int     i_flag;
    char    *i_filename;
    int     i_fd;
    int     v_flag;
    int     h_flag;

    long     nb_ants;
    int     nb_rooms;
    int     nb_tubes;
    char    *start_room;
    char    *end_room;
}                   t_env;

/*
** Parser
*/
int     ft_parse_stdin(t_env *e);
int     ft_parse_room(char *line, t_parser *p);

/*
** Exit
*/
void	ft_print_usage(int exit);
void	ft_free_anything(void *arg1, ...);
void    ft_free_env(t_env *e, int flag);
void	ft_error(char *str);

/*
** Options
*/
void	ft_read_options(int ac, char **av, t_env *e);

#endif