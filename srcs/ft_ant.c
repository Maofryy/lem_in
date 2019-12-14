#include "lem_in.h"

t_ant   ft_place_ant(t_paths *paths, int path_cursor, int *delays, int **rooms, char **labels)
{
    t_ant ant;

    // If room is empty
    if (rooms[path_cursor][delays[path_cursor]] == 0)
        {
            ant.rooms = ft_stack_list(ft_get_stack(paths, path_cursor));
            ant.length = ft_stack_size(ft_get_stack(paths, path_cursor));
            ant.delay = delays[path_cursor];
            rooms[path_cursor][delays[path_cursor]] = 1;
        }
        // else if the there is no more free path
        else if (path_cursor + 1 >= ft_paths_size(paths))
        {
            while (path_cursor >= 0)
                delays[path_cursor--]++;
            return (ft_place_ant(paths, 0, delays, rooms, labels));
        }
        // else if the curr path is still shorter than the next (even with a delay of one)
        else if(((ft_stack_size(ft_get_stack(paths, path_cursor + 1)) - 1) >
            (ft_stack_size(ft_get_stack(paths, path_cursor)) + delays[path_cursor])))
        {
            ant.rooms = ft_stack_list(ft_get_stack(paths, path_cursor));
            ant.length = ft_stack_size(ft_get_stack(paths, path_cursor));
            delays[path_cursor]++;
            ant.delay = delays[path_cursor];
            rooms[path_cursor][delays[path_cursor]] = 1;
        }
        // else re run with the next path
        else
            return (ft_place_ant(paths, path_cursor + 1, delays, rooms, labels));
    return (ant);
}