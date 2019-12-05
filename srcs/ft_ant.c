#include "lem_in.h"

t_ant   ft_place_ant(t_paths *paths, int path_cursor, int *delays, int **rooms, char **labels)
{
    t_ant ant;

    // ft_printf("p_u = %d\n", path_cursor);
    // ft_printf("P_S = %d\n", ft_paths_size(paths));
    // ft_printf("room= %d\n", rooms[path_cursor][delays[path_cursor]]);
    if (rooms[path_cursor][delays[path_cursor]] == 0)
        {
            ant.path = ft_get_stack(paths, path_cursor);
            ant.room = ant.path->data;
            ant.delay = delays[path_cursor];
            ft_printf("Room empty : %s | delay = %d\n", labels[ant.path->next->data], ant.delay);
            rooms[path_cursor][delays[path_cursor]] = 1;
        }
        else if (path_cursor + 1 >= ft_paths_size(paths))
        {
            //ft_printf("No other path\n");
            // delays[path_cursor]++;
            while (path_cursor >= 0)
                delays[path_cursor--]++;
            return (ft_place_ant(paths, 0, delays, rooms, labels));
        }
        else if(((ft_stack_size(ft_get_stack(paths, path_cursor + 1)) - 1) >=
            (ft_stack_size(ft_get_stack(paths, path_cursor)) + delays[path_cursor])))
        {
            ant.path = ft_get_stack(paths, path_cursor);
            ant.room = ant.path->data;
            delays[path_cursor]++;
            ant.delay = delays[path_cursor];
            rooms[path_cursor][delays[path_cursor]] = 1;
            ft_printf("Faster to wait : %s | delay = %d\n", labels[ant.path->next->data], ant.delay);
        }
        // Need to check if path_size is exceed regarding path_cursor + 1
        else
        {
            //ft_printf("Looking for other path\n");
            return (ft_place_ant(paths, path_cursor + 1, delays, rooms, labels));
        }
    return (ant);
}