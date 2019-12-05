#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>

typedef struct      s_paths
{
    t_stack         *s;
    struct s_paths   *next;
}                   t_paths;

typedef struct      s_matrix
{
    int     **adj;
    char    **labels;
    int     size;
}                   t_matrix;

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

typedef struct      s_ant
{
    int nb;
    t_stack *path;
    int room;
    int delay;
}                   t_ant;

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
    t_room  *rooms;
    t_tube  *tubes;
}                   t_parser;

typedef struct      s_env
{
    //options shit
    int     ac_start;
    int     o_flag;
    char    *o_filename;
    int     o_fd;
    int     i_flag;
    char    *i_filename;
    int     i_fd;
    int     v_flag;
    int     h_flag;
    //end options

    long        nb_ants;
    t_matrix    *mat;
}                   t_env;

/*
** Parser
*/
int     ft_parse_stdin(t_env *e);
int     ft_parse_room(char *line, t_parser *p);
int     ft_parse_tube(char *line, t_parser *p);
int     ft_malloc_room(t_parser *p, int ret);
int     ft_malloc_tube(t_parser *p, int ret);

/*
** Solve
*/
t_paths  *ft_solve(t_matrix *mat);

/*
** Matrix
*/
t_matrix    *ft_matrix_create(t_parser *p);
void        ft_free_matrix(t_matrix *mat);
void        ft_print_matrix(t_matrix mat);
void        ft_matrix_remove_path(t_stack *s, t_matrix *mat);

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

/*
** Paths linked list 
*/
t_paths *ft_paths_new(t_stack *new);
t_stack	*ft_paths_pop(t_paths **s);
void    ft_paths_push_tail(t_paths **s, t_stack *new);
int	    ft_paths_contains(t_paths *s, int n);
int     ft_paths_size(t_paths *s);
void	ft_paths_push(t_paths **s, t_stack *new);
t_stack *ft_get_stack(t_paths *paths, int n);
void	ft_paths_print(t_paths *s, char **labels);
void    ft_paths_reverse(t_paths **s);

/*
** Print
*/
void    ft_print_rooms(t_parser *p);
void    ft_print_tubes(t_parser *p);
void    ft_print_ants(int nb_ants, t_paths *path, t_matrix *mat);
t_ant   ft_place_ant(t_paths *paths, int path_cursor, int *delays, int **rooms, char **labels);

#endif