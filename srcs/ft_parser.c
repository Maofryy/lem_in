#include "lem_in.h"

t_parser    *ft_init_parser(void)
{
    t_parser *p;
    
    p = (t_parser *)malloc(sizeof(t_parser) * 1);
    p->nb_ants = -1;
    p->cnt_room = 0;
    p->cnt_tube = 0;
    p->start_flag = 0;
    p->end_flag = 0;
    // p->rooms = (t_room *)malloc(sizeof(t_room));
    
    // p->rooms->next = NULL;
    p->rooms = NULL;
    // p->tubes = (t_tube *)malloc(sizeof(t_tube));
    
    // p->tubes->next = NULL;
    p->tubes = NULL;
    // p->rooms->next = NULL;
    return (p);
}

void    ft_free_parser(t_parser *p)
{
    // if (p->start_flag)
    //     free(p->start_room);
    // if (p->end_flag)
    //     free(p->end_room);
    // while (p->rooms != NULL)
    // {
    //     free(p->rooms->label);
    //     p->rooms = p->rooms->next;
    // };
    // ft_del_room(p->rooms);
    // while (p->tubes != NULL)
    // {
    //     free(p->tubes->room_1);
    //     free(p->tubes->room_2);
    //     p->tubes = p->tubes->next;
    // }
    // ft_del_tube(p->tubes);
    free(p);
}

int    ft_parse_long(char *line, long *nb)
{
    if (!ft_isnum(line))
    {
        ft_printf("Error : non numeric number passed");
        return (-1);
    }
    *nb = ft_atol(line);
    if (*nb < 0)
    {    
        ft_printf("Error : negative number");
        return (-1);
    }
    return (1);
}

int    ft_parse_int(char *line, int *nb)
{
    if (!ft_isnum(line))
    {
        ft_printf("Error : non numeric number passed");
        return (-1);
    }
    *nb = ft_atoi(line);
    if (*nb < 0)
    {    
        ft_printf("Error : negative number");
        return (-1);
    }
    return (1);
}

int    ft_read_comment(char *line, t_parser *p)
{
    if (ft_strequ(line, "#start"))
    {
        if (p->start_flag == 1)
        {
            ft_printf("Error : Double start command");
            return (-1);
        }
        p->start_flag = -1;
    }
    else if (ft_strequ(line, "#end"))
    {
        if (p->end_flag == 1)
        {
            ft_printf("Error : Double end command");
            return (-1);
        }
        p->end_flag = -1;
    }
    return (1);
}

int     ft_parse_line(char *line, t_parser *p)
{
    int ret;

    ret = 0;
    if (line[0] == '#')
        return (ft_read_comment(line + 1, p));
    if (p->nb_ants == -1)
        return (ft_parse_long(line, &p->nb_ants));
    /*else if (p->nb_rooms == -1)
        return (ft_malloc_room(p, ft_parse_int(line, &p->nb_rooms)));
    else if (p->nb_tubes == -1)
        return (ft_malloc_tube(p, ft_parse_int(line, &p->nb_tubes)));*/
    else if (ft_strchr(line, ' '))
        return (ft_parse_room(line, p));
    else if (ft_strchr(line, '-'))
        return (ft_parse_tube(line, p));
    else
        ret = -1;
    return (ret);
}

void    ft_paste_parser(t_parser *p, t_env *e)
{
    e->nb_ants = p->nb_ants;
    if (p->start_flag != 1 || p->end_flag != 1)
        ft_error("Error : start or end not defined");
    if (p->rooms == NULL)
        ft_error("Error : no rooms given\n");
    e->rooms = p->rooms;
    e->cnt_room = p->cnt_room;
    e->start_room = p->start_room;
    e->end_room = p->end_room;
    if (p->tubes == NULL)
        ft_error("Error : no tubes given\n");
    e->tubes = p->tubes;
    // ft_printf("also print comments :/\n");
}

int     ft_parse_stdin(t_env *e)
{
    char  *line;
    t_parser *p;
    int   n;

    n = 0;
    p = ft_init_parser();
    while (get_next_line(e->o_fd, &line) > 0)
    {
        ft_printf("%s\n", line);
        if (ft_strlen(line) == 0 || line[0] == 'L' || ft_parse_line(line, p) == -1)
        {
            free(line);
            break ;
        }
        n++;
        free(line);
    }
    ft_paste_parser(p, e);
    free(p);
    return (n);
}