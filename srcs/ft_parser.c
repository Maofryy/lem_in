#include "lem_in.h"

void    ft_init_parser(t_parser *p)
{
    p->nb_ants = 0;
    p->nb_rooms = 0;
    p->cursor_rooms = 0;
    p->nb_tubes = 0;
    p->cursor_tubes = 0;
    p->start_flag = 0;
    p->end_flag = 0;
}

int    ft_parse_nb(char *line, long *nb)
{
    if (!ft_isnum(line))
        ft_error("Error : non numeric number passed");
    *nb = ft_atol(line);
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
    if (p->nb_ants == 0)
        return (ft_parse_nb(line, &p->nb_ants));
    else if (p->cursor_rooms <= p->nb_rooms)
        return (ft_parse_room(line, p));
    // else if (p->cursor_tubes <= p->nb_tubes)
    //     ft_parse_tube(line, p);
    return (ret);
}

void    ft_paste_parser(t_parser *p, t_env *e)
{
    e->nb_ants = p->nb_ants;
    e->nb_rooms = p->nb_rooms;
    e->nb_tubes = p->nb_tubes;
    e->start_room = p->start_room;
    e->end_room = p->end_room;
    e->start_room = ft_strdup("Start");
    e->end_room = ft_strdup("End");
}

int     ft_parse_stdin(t_env *e)
{
  char  *line;
  t_parser p;
  int   n;

  n = 0;
  ft_init_parser(&p);
  while (get_next_line(e->o_fd, &line) > 0)
  {
    if (ft_strlen(line) == 0 || line[0] == 'L')
    {
      free(line);
      break ;
    }
    if (ft_parse_line(line, &p) == -1)
    {
      free(line);
      ft_free_env(e, 1);
    }
    n++;
    free(line);
  }
  ft_printf("start_flag : %d | end_flag : %d\n", p.start_flag, p.end_flag);
  ft_paste_parser(&p, e);
  return (n);
}