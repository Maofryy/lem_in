#include "lem_in.h"

void init_dijkstra(t_env *e)
{
    int i;

    if (e->dist == NULL)
        e->dist = (long *)malloc(sizeof(long) * (e->cnt_room + 1));
    i = -1;
    while (++i < e->cnt_room + 1)
        e->dist[i] = LONG_MAX;
    if (e->res == NULL)
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

    rev = e->end_room;
    s = ft_stack_new(rev);
    while (rev != e->start_room)
    {
        rev = e->res[rev];
        ft_stack_push(&s, rev);
    }
    ft_paths_push(&e->results, s, e->dist[e->end_room]);
}

void ft_remove_path(t_env *e)
{
    //get the stack and remove for each one of them the path[room1] and path[room2]
    t_stack *s;

    s = e->results->s;
    // ft_print_paths(*e);
    while (s->next != NULL)
    {
        // ft_printf("s->n = %d | next n = %d\n", s->data, s->next->data);
        e->path[s->data] = ft_path_del_n(e->path[s->data], s->next->data);
        e->path[s->next->data] = ft_path_del_n(e->path[s->next->data], s->data);
        s = s->next;
    }
}

void ft_add_paths(t_env *e)
{
    if (e->res[e->end_room] == -1 && e->results == NULL)
        ft_error("Error : no path found\n");
    else if (e->res[e->end_room] == -1)
        return ;
    // get stack from res to results
    ft_parse_stack(e);
    // remove stack from e->path
    ft_remove_path(e);
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