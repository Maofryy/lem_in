#include "lem_in.h"

// void    ft_print_rooms(t_parser *p)
// {
//     int i;
    
//     i = -1;
//     while (++i < p->nb_rooms)
//     {
//         if (ft_strequ(p->start_room, p->rooms[i].label))
//             ft_printf("##start\n");
//         if (ft_strequ(p->end_room, p->rooms[i].label))
//             ft_printf("##end\n");
//         ft_printf("%s %d %d\n", p->rooms[i].label,
//             p->rooms[i].x_pos, p->rooms[i].y_pos);
//     }
// }

// void    ft_print_tubes(t_parser *p)
// {
//     int i;
    
//     i = -1;
//     while (++i < p->nb_tubes)
//     {
//         ft_printf("%s-%s\n", p->tubes[i].room_1,
//              p->tubes[i].room_2);
//     }
// }

t_stack *ft_get_stack(t_paths *paths, int n)
{
    int i;

    i = 0;
    while (paths != NULL && i < n)
    {
        paths = paths->next;
        i++;
    }
    return (paths->s);
}

int       **ft_init_rooms(int nb_ants, int **rooms)
{
    int i;

    i = -1;
    while (++i < nb_ants)
        rooms[i] = (int *)ft_memalloc(sizeof(int) * (nb_ants + 1));
    return (rooms);
}

int     ft_print_single_ant(t_ant ant, int line)
{
    if (line >= ant.delay && line < ant.delay + ant.length - 1)
        ft_printf("L%d-%s ", ant.nb, labels[ant.rooms[line - ant.delay + 1]]);
    if (line >= ant.delay + ant.length -1)
        return (1);
    return (0);
}

void    ft_print_ants(int nb_ants, t_paths *paths)
{
    t_ant   *ants;
    int     i;
    int     paths_size;
    int     *delays;
    int     **rooms;
    int     path_cursor;
    int     line;
    int     ended;

    i = -1;
    line = 0;
    path_cursor = 0;
    paths_size = ft_paths_size(paths);
    ants = (t_ant *)malloc(sizeof(t_ant) * (nb_ants));
    delays = (int *)ft_memalloc(sizeof(int) * paths_size);
    rooms = (int **)malloc(sizeof(int *) * (paths_size));
    ft_init_rooms(nb_ants, rooms);
    while (++i < nb_ants)
    {
        ants[i] = ft_place_ant(paths, path_cursor, delays, rooms);
        ants[i].nb = i + 1;
    }
    while (1)
    {
        ended = 0;
        i = -1;
        while (++i < nb_ants)
            ended += ft_print_single_ant(ants[i], line);
        if (ended == nb_ants)
            break;
        ft_putchar('\n');
        line++;
    }

    // ft free everyGodDamnedThing
    free(delays);
    i = -1;
    while (++i < nb_ants)
        free(ants[i].rooms);
    free(ants);
    ft_tab_del(rooms, nb_ants);
}