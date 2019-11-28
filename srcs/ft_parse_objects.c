#include "lem_in.h"

int     ft_malloc_room(t_parser *p, int ret)
{
    p->room = (t_room *)malloc(sizeof(t_room) * p->nb_rooms + 1);
    return (ret);
}

int    ft_parse_room(char *line, t_parser *p)
{
    char **tab;

    if (count_words(line, ' ') != 3)
        ft_error("Error : Not well formated room line\n");
    //ptet free aussi quoi
    tab = ft_strsplit(line, ' ');
    if (!ft_isnum(tab[1]) || !ft_isnum(tab[2]))
        ft_error("Error : Not well room line\n");
    //ptet free aussi quoi
    p->room[p->cursor_rooms].label = ft_strdup(tab[0]);
    p->room[p->cursor_rooms].x_pos = ft_atoi(tab[1]);
    p->room[p->cursor_rooms].y_pos = ft_atoi(tab[2]);
    p->cursor_rooms++;
    // ft_free_anything((void *)tab[0]);
    ft_printf("cursor rooms : %d\n", p->cursor_rooms);
    ft_printf("read %s : x=%d and y=%d\n", p->room[p->cursor_rooms].label, p->room[p->cursor_rooms].x_pos, p->room[p->cursor_rooms].y_pos);
    return (1);
}