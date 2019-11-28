#include "lem_in.h"

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
    p->room = malloc(sizeof(t_room) * 2);
    p->room->label = ft_strdup(tab[0]);
    p->room->x_pos = ft_atoi(tab[1]);
    p->room->y_pos = ft_atoi(tab[2]);
    // ft_free_anything((void *)tab[0]);
    ft_printf("read %s : x=%d and y=%d\n", p->room->label, p->room->x_pos, p->room->y_pos);
    return (1);
}