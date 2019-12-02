#include "lem_in.h"

int     ft_malloc_room(t_parser *p, int ret)
{
    p->rooms = (t_room *)malloc(sizeof(t_room) * p->nb_rooms + 1);
    return (ret);
}

int     ft_malloc_tube(t_parser *p, int ret)
{
    p->tubes = (t_tube *)malloc(sizeof(t_tube) * p->nb_tubes + 1);
    return (ret);
}

int    ft_is_room_label(char *str, t_parser p)
{
    
    while (p.rooms->label)
    {
        if (ft_strequ(str, p.rooms->label))
            return (1);
        p.rooms++;
    }
    return (0);
}

int    ft_parse_tube(char *line, t_parser *p)
{
    char **tab;

    if (count_words(line, '-') != 2)
        ft_error("Error : Not well formated tube line\n");
    tab = ft_strsplit(line, '-');
    if (!ft_is_room_label(tab[0], *p) || !ft_is_room_label(tab[1], *p) || ft_strequ(tab[0], tab[1]))
        ft_error("Error : Wrong room label\n");
    p->tubes[p->cursor_tubes].room_1 = ft_strdup(tab[0]);
    p->tubes[p->cursor_tubes].room_2 = ft_strdup(tab[1]);
    // ft_printf("Tube from %s to %s\n",  p->tubes[p->cursor_tubes].room_1, p->tubes[p->cursor_tubes].room_2);
    p->cursor_tubes++;
    return (1);
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
    if (p->start_flag == -1)
    {
        p->start_room = ft_strdup(tab[0]);
        p->start_flag = 1;
    }
    else if (p->end_flag == -1)
    {
        p->end_room = ft_strdup(tab[0]);
        p->end_flag = 1;
    }    
    p->rooms[p->cursor_rooms].label = ft_strdup(tab[0]);
    p->rooms[p->cursor_rooms].x_pos = ft_atoi(tab[1]);
    p->rooms[p->cursor_rooms].y_pos = ft_atoi(tab[2]);
    // ft_free_anything((void *)tab[0]);
    // ft_printf("Room %s at (%d, %d)\n", p->rooms[p->cursor_rooms].label, p->rooms[p->cursor_rooms].x_pos, p->rooms[p->cursor_rooms].y_pos);
    p->cursor_rooms++;
    return (1);
}