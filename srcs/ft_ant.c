#include "lem_in.h"

void   ft_place_ant(t_paths *paths, int path_cursor, t_stack **queues, int n)
{
    if (path_cursor == ft_paths_size(paths) - 1)
    {
        stack_queue_push(&queues[path_cursor], n);
        path_cursor = 0;
    }
    else if (ft_stack_size(queues[path_cursor]) + ft_stack_size(ft_paths_get(paths, path_cursor)) 
                < ft_stack_size(queues[path_cursor + 1]) + ft_stack_size(ft_paths_get(paths, path_cursor + 1)))
    {
        stack_queue_push(&queues[path_cursor], n);
        path_cursor = 0;
    }
    else
        ft_place_ant(paths, path_cursor + 1, queues, n);
    // If room is empty
        // then place the ant in the path pointed by path_cursor (Maybe should do that at the end)

    // else if the there is no more free path
        // reset the path cursor to zero and retry with a (delay +1)
        
    // else if the curr path is still shorter than the next (even with a delay of one)
        // the add the ant in the room with a (delay + 1)

    // else re run with the next path
        // call place ant agin with a (path_cursor +1)
}

// // If room is empty
// if (rooms[path_cursor][delays[path_cursor]] == 0)
// {
//     ant.rooms = ft_stack_list(ft_get_stack(paths, path_cursor));
//     ant.length = ft_stack_size(ft_get_stack(paths, path_cursor));
//     ant.delay = delays[path_cursor];
//     rooms[path_cursor][delays[path_cursor]] = 1;
// }
// // else if the there is no more free path
// else if (path_cursor + 1 >= ft_paths_size(paths))
// {
//     while (path_cursor >= 0)
//         delays[path_cursor--]++;
//     return (ft_place_ant(paths, 0, delays, rooms, labels));
// }
// // else if the curr path is still shorter than the next (even with a delay of one)
// else if (((ft_stack_size(ft_get_stack(paths, path_cursor + 1)) - 1) >
//           (ft_stack_size(ft_get_stack(paths, path_cursor)) + delays[path_cursor])))
// {
//     ant.rooms = ft_stack_list(ft_get_stack(paths, path_cursor));
//     ant.length = ft_stack_size(ft_get_stack(paths, path_cursor));
//     delays[path_cursor]++;
//     ant.delay = delays[path_cursor];
//     rooms[path_cursor][delays[path_cursor]] = 1;
// }
// // else re run with the next path
// else
//     return (ft_place_ant(paths, path_cursor + 1, queues, n));