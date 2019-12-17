#include "lem_in.h"

// int     ft_malloc_room(t_parser *p, int ret)
// {
//    p->rooms = (t_room *)malloc(sizeof(t_room) * p->nb_rooms + 1);
//     return (ret);
// }

// int     ft_malloc_tube(t_parser *p, int ret)
// {
//     p->tubes = (t_tube *)malloc(sizeof(t_tube) * p->nb_tubes + 1);
//     return (ret);
// }

// int    ft_is_room_label(char *str, t_parser p)
// {
    
//     while (p.rooms->label)
//     {
//         if (ft_strequ(str, p.rooms->label))
//             return (1);
//         p.rooms++;
//     }
//     return (0);
// }

int    ft_parse_tube(char *line, t_parser *p)
{
    char **tab;

    if (count_words(line, '-') != 2)
    {
        ft_printf("Error : Not well formated tube line\n");
        return (-1);
    }
    tab = ft_strsplit(line, '-');
    if ((ft_search_room(p->rooms, tab[0]) == NULL) || (ft_search_room(p->rooms, tab[1]) == NULL) || ft_strequ(tab[0], tab[1]))
    {
        ft_printf("Error : Wrong room label\n");
        return (-1);
    }
    ft_add_tube(&p->tubes, ft_create_tube(p, tab));
    // p->tubes[p->cnt_tube].room_1 = ft_strdup(tab[0]);
    // p->tubes[p->cnt_tube].room_2 = ft_strdup(tab[1]);
    // ft_printf("Tube from %s to %s\n",  p->tubes[p->cursor_tubes].room_1, p->tubes[p->cursor_tubes].room_2);
    p->cnt_tube++;
    return (1);
}

int    ft_parse_room(char *line, t_parser *p)
{
    char **tab;

    if (count_words(line, ' ') != 3)
    {
        ft_printf("Error : Not well formated room line\n");
        return (-1);
    }
    tab = ft_strsplit(line, ' ');
    if (!ft_isnum(tab[1]) || !ft_isnum(tab[2]))
    {
        ft_printf("Error : Not well room formated line\n");
        return (-1);
    }
    if (p->start_flag == -1)
    {
        p->start_room = p->cnt_room;
        p->start_flag = 1;
    }
    if (p->end_flag == -1)
    {
        if (p->start_flag == -1)
        {
            ft_printf("Error : start and end cannot be the same room\n");
            return (-1);
        }
        p->end_room = p->cnt_room;
        p->end_flag = 1;
    }
    ft_add_room(&p->rooms, ft_create_room(p, tab));
    p->cnt_room++;
    return (1);
}