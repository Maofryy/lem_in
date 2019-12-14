#include "lem_in.h"

void path_queue_pop(t_path **head)
{
    t_path *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

void path_queue_push(t_path **head, int n, long d)
{
    t_path *path;
    t_path *tmp;

    path = ft_memalloc(sizeof(t_path));
    path->n = n;
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

void stack_queue_pop(t_stack **head)
{
    t_stack *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

void stack_queue_push(t_stack **head, int n)
{
    t_stack *stack;
    t_stack *tmp;

    stack = ft_memalloc(sizeof(t_stack));
    stack->data = n;
    tmp = *head;
    if (!tmp)
        *head = stack;
    else
        while (tmp)
        {
            if (!tmp->next)
            {
                tmp->next = stack;
                return;
            }
            tmp = tmp->next;
        }
}

int stack_queue_look(t_stack *head, int index)
{
    int     res;
    t_stack *tmp;

    tmp = head;
    res = 0;
    if (!tmp)
        return (-1);
    else
        while (tmp && res++ < index)
            tmp = tmp->next;
    if (!tmp)
        return (-1);
    return (tmp->data);
}