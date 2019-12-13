#include "lem_in.h"

void init_dijkstra(t_env *e)
{
    int i;

    e->dist = (long *)malloc(sizeof(long) * (e->cnt_room + 1));
    i = -1;
    while (++i < e->cnt_room + 1)
        e->dist[i] = LONG_MAX;
    e->res = (int *)malloc(sizeof(int) * (e->cnt_room + 1));
    i = -1;
    while (++i < e->cnt_room + 1)
        e->res[i] = -1;
    e->res[e->start_room] = 0;
    e->dist[e->start_room] = 0;
    queue_push(&e->queue, e->start_room, 0);
}

void ft_parse_stack(t_env *e)
{
    int     rev;
    t_stack *s;

    rev = e->res[e->end_room];
    s = ft_stack_new(rev);
    while (rev != e->start_room)
    {
        rev = e->res[rev];
        ft_stack_push(&s, rev);
    }
    ft_paths_push_tail(&e->results, s, e->dist[e->res[e->end_room]]);
}

void ft_add_paths(t_env *e)
{
    if (e->res[e->end_room] == -1 && e->results == NULL)
        ft_error("Error : no path found\n");
    else if (e->res[e->end_room] == -1)
        return ;
    
    // get stack from res to results
    ft_parse_stack(e);
    // free res or change init dij to malloc only if null
    // free(e->res);
    // free(e->dist);
    // remove stack from e->path
}

void dijkstra(t_env *e)
{
    t_path  *ptmp;
    int     itmp;
    long    dtmp;

    init_dijkstra(e);
    while (e->queue)
    {
        itmp = e->queue->n;
        dtmp = e->queue->dist;
        ptmp = e->path[itmp];
        queue_pop(&e->queue);
        if (dtmp <= e->dist[itmp])
        {
            while (ptmp)
            {
                if (e->dist[ptmp->n] > e->dist[itmp] + ptmp->dist)
                {
                    e->dist[ptmp->n] = e->dist[itmp] + ptmp->dist;
                    queue_push(&e->queue, ptmp->n, e->dist[ptmp->n]);
                    e->res[ptmp->n] = itmp;
                }
                ptmp = ptmp->next;
            }
        }
    }
    ft_add_paths(e);
}