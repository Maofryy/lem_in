#include "lem_in.h"

void queue_pop(t_path **head)
{
    t_path *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

void queue_push(t_path **head, int n, int d)
{
    t_path *path;
    t_path *tmp;

    path = ft_memalloc(sizeof(t_path));
    path->u = n;
    path->dist = d;
    tmp = *head;
    if (!tmp)
        *head = path;
    else
        while (tmp)
        {
            if (!tmp->next)
            {
                tmp->next = path;
                return;
            }
            tmp = tmp->next;
        }
}