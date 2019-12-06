#include "lem_in.h"

t_parser    *ft_init_parser(void)
{
    t_parser *p;
    
    p = (t_parser *)malloc(sizeof(t_parser) * 1);
    p->nb_ants = -1;
    p->nb_rooms = -1;
    p->cursor_rooms = 0;
    p->nb_tubes = -1;
    p->cursor_tubes = 0;
    p->start_flag = 0;
    p->end_flag = 0;
    return (p);
}

void    ft_free_parser(t_parser *p)
{
    int i;

    if (p->start_flag)
        free(p->start_room);
    if (p->end_flag)
        free(p->end_room);
    i = -1;
    while (++i < p->cursor_rooms)
    {
        free(p->rooms[i].label);
    };
    free(p->rooms);
    i = -1;
    while (++i < p->cursor_tubes)
    {
        free(p->tubes[i].room_1); 
        free(p->tubes[i].room_2);
    }
    
    free(p->tubes);
    free(p);
}

int    ft_parse_long(char *line, long *nb)
{
    if (!ft_isnum(line))
        ft_error("Error : non numeric number passed");
    *nb = ft_atol(line);
    if (*nb < 0)
        ft_error("Error : negative number");
    return (1);
}

int    ft_parse_int(char *line, int *nb)
{
    if (!ft_isnum(line))
        ft_error("Error : non numeric number passed");
    *nb = ft_atoi(line);
    if (*nb < 0)
        ft_error("Error : negative number");
    return (1);
}

int    ft_read_comment(char *line, t_parser *p)
{
    if (ft_strequ(line, "#start"))
    {
        if (p->start_flag == 1)
            ft_error("Error : Double start command");
        p->start_flag = -1;
    }
    else if (ft_strequ(line, "#end"))
    {
        if (p->end_flag == 1)
            ft_error("Error : Double end command");
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
    else if (p->nb_rooms == -1)
        return (ft_malloc_room(p, ft_parse_int(line, &p->nb_rooms)));
    else if (p->nb_tubes == -1)
        return (ft_malloc_tube(p, ft_parse_int(line, &p->nb_tubes)));
    else if (p->cursor_rooms < p->nb_rooms)
        return (ft_parse_room(line, p));
    else if (p->cursor_tubes < p->nb_tubes)
        return (ft_parse_tube(line, p));
    return (ret);
}

void    ft_paste_parser(t_parser *p, t_env *e)
{
    e->nb_ants = p->nb_ants;
    ft_printf("%d\n",e->nb_ants);
    if (p->cursor_rooms != p->nb_rooms)
        ft_error("Error : wrong number of rooms\n");
    if (p->cursor_tubes != p->nb_tubes)
        ft_error("Error : wrong number of tubes\n");
    if (p->start_flag != 1 || p->end_flag != 1)
        ft_error("Error : start or end not defined\n");
    ft_print_rooms(p);
    ft_print_tubes(p);
    e->mat = ft_matrix_create(p);
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
    // ft_printf("%s\n", line);
    if (ft_strlen(line) == 0 || line[0] == 'L')
    {
      free(line);
      break ;
    }
    if (ft_parse_line(line, p) == -1)
    {
      free(line);
      ft_free_env(e, 1);
    }
    n++;
    free(line);
  }
  ft_paste_parser(p, e);
  ft_free_parser(p);
  return (n);
}