#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <limits.h>

typedef struct      s_paths
{
    t_stack         *s;
    long            dist;
    struct s_paths   *next;
}                   t_paths;

typedef struct s_path
{
    int             n;
    long            dist;
    struct s_path   *next;
} t_path;

typedef struct      s_matrix
{
    int     **adj;
    char    **labels;
    int     size;
}                   t_matrix;

typedef struct      s_room
{
    int     n;
    char    *label;
    int     x_pos;
    int     y_pos;
    struct  s_room *next;
}                   t_room;

typedef struct      s_tube
{
    int     n;
    int     room_1;
    int     room_2;
    struct  s_tube *next;
}                   t_tube;

typedef struct      s_ant
{
    int nb;
    int room;
    int delay;
}                   t_ant;

typedef struct      s_parser
{
    long     nb_ants;
    int     cnt_room;
    int     cnt_tube;
    int     start_flag;
    int     start_room;
    int     end_flag;
    int     end_room;
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
    //passing from parser
    // t_matrix    *mat;
    t_room  *rooms;
    int     cnt_room;
    int     start_room;
    int     end_room;
    t_tube  *tubes;

    //solve
    long    *dist;
    int     *res;
    t_path  *queue;
    t_path  **path;
    t_paths  *results;
}                   t_env;

/*
** Room
*/
t_room  *ft_get_room(t_room *head, int index);
void    ft_add_room(t_room **head, t_room *room);
void    ft_del_room(t_room *room);
t_room  *ft_search_room(t_room *head, char *tube);
t_room  *ft_duplicate_room(t_room *room);
t_room	*ft_create_room(t_parser *p, char **split);
void    ft_print_rooms(t_room *head);
void    ft_split_del(char **split);
void	ft_tab_del(int **tab, int size);

/*
** Tubes
*/
void ft_add_tube(t_tube **head, t_tube *tube);
void ft_del_tube(t_tube *tube);
void ft_print_tubes(t_tube *head);
t_tube *ft_get_tube(t_tube *head, int index);
t_tube *ft_duplicate_tube(t_tube *tube);
t_tube *ft_create_tube(t_parser *p, char **split);

/*
** Parser
*/
int     ft_parse_stdin(t_env *e);
int     ft_parse_room(char *line, t_parser *p);
int     ft_parse_tube(char *line, t_parser *p);


/*
** Solve
*/
t_paths *ft_solve(t_matrix *mat);
void    path_queue_push(t_path **head, int n, long d);
void    path_queue_pop(t_path **head);
void    stack_queue_pop(t_stack **head);
void    stack_queue_push(t_stack **head, int n);
int     stack_queue_look(t_stack *head, int index);

/*
** Matrix
*/
t_matrix *ft_matrix_create(t_parser *p);
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
t_paths *ft_paths_new(t_stack *new, long dist);
t_stack	*ft_paths_pop(t_paths **s);
void    ft_paths_push_tail(t_paths **s, t_stack *new, long dist);
int	    ft_paths_contains(t_paths *s, int n);
int     ft_paths_size(t_paths *s);
void	ft_paths_push(t_paths **s, t_stack *new, long dist);
t_stack *ft_get_stack(t_paths *paths, int n);
void	ft_paths_print(t_paths *s, char **labels);
void    ft_paths_reverse(t_paths **s);
void	ft_paths_del(t_paths **s);
t_stack *ft_paths_get(t_paths *s, int index);

/*
** For single Path
*/
void    ft_parse_path(t_env *e);
void    ft_print_paths(t_env e);
void    ft_del_path(t_path *path);
t_path  *ft_create_path(int n);
void    dijkstra(t_env *e);
t_path *ft_path_del_n(t_path *s, int n);

/*
** Print
*/
void    ft_print_ants(t_env *e, t_stack **queues, int res_size);
void   ft_place_ant(t_paths *paths, int path_cursor, t_stack **queues, int n);
void    ft_move_ants(t_env *e);

#endif