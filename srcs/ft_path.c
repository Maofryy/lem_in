#include "lem_in.h"

t_path *ft_create_path(int n)
{
    t_path *new_path;

    new_path = ft_memalloc(sizeof(t_path));
    new_path->n = n;
    new_path->dist = 1;
    return (new_path);
}

t_path *ft_create_path_1(t_tube *tube)
{
    t_path *new_path;

    new_path = ft_memalloc(sizeof(t_path));
    new_path->n = tube->room_1;
    new_path->dist = 1;
    return (new_path);
}

t_path *ft_create_path_2(t_tube *tube)
{
    t_path *new_path;

    new_path = ft_memalloc(sizeof(t_path));
    new_path->n = tube->room_2;
    new_path->dist = 1;
    return (new_path);
}

void ft_add_path(t_path **head, t_path *path)
{
    t_path *tmp;

    tmp = *head;
    if (!tmp)
        *head = path;
    else
    {
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
}

void ft_parse_path(t_env *e)
{
    t_path *path;
    t_tube *tube;

    e->path = ft_memalloc(sizeof(t_path *) * (e->cnt_room + 2));
    tube = e->tubes;
    while (tube != NULL)
    {
        path = ft_create_path_1(tube);
        ft_add_path(&e->path[tube->room_2], path);
        path = ft_create_path_2(tube);
        ft_add_path(&e->path[tube->room_1], path);
        tube = tube->next;
    }
}

void ft_del_path(t_path *path)
{
    if (path)
    {
        ft_del_path(path->next);
        free(path);
    }
}

// #include <stdio.h>
void ft_print_paths(t_env e)
{
    int i;
    t_path *path;

    i = -1;
    ft_printf("Printing paths :\n");
    while (++i < e.cnt_room)
    {
        path = e.path[i];
        // ft_printf("path[%s] : ", ft_get_room(e.rooms, i)->label);
        ft_printf("path[%d] : ", i);
        while (path != NULL)
        {
            ft_printf(" %s_%ld", ft_get_room(e.rooms, path->n)->label, path->dist);
            path = path->next;
        }
        ft_printf("|\n");
    }
}

t_path *ft_path_del_n(t_path *s, int n)
{
    t_path *tmp;

    if (s == NULL)
        ft_error("Error : trying to remove tube that didnt existed\n");
    if (s->n == n)
    {
        tmp = s->next;
        free(s);
        return tmp;
    }
    s->next = ft_path_del_n(s->next, n);
    return (s);
}