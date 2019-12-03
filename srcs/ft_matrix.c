#include "lem_in.h"

int         ft_is_adj(t_parser *p, int i, int j)
{
    int k;

    k = -1;
    while (++k < p->nb_tubes)
    {
        if ((ft_strequ(p->tubes[k].room_1, p->rooms[i].label) 
            && ft_strequ(p->tubes[k].room_2, p->rooms[j].label))
            || (ft_strequ(p->tubes[k].room_2, p->rooms[i].label)
            && ft_strequ(p->tubes[k].room_1, p->rooms[j].label)))
            return (1);
    }
    return (0);
}

t_matrix    *ft_init_matrix(t_parser *p)
{
    t_matrix *m;
    int i;
    int j;

    i = -1;
    m = (t_matrix *)malloc(sizeof(t_matrix) * 1);
    m->adj = (int **)malloc(sizeof(int *) * (p->nb_rooms));
    m->labels = (char **)malloc(sizeof(char *) * (p->nb_rooms + 1));
    m->size = p->nb_rooms;
    while (++i < p->nb_rooms)
    {
        j = -1;
        m->adj[i] = (int *)malloc(sizeof(int) * (p->nb_rooms));
        while (++j < p->nb_rooms)
            m->adj[i][j] = ft_is_adj(p, i ,j);
        m->labels[i] = ft_strdup(p->rooms[i].label);
    }
    m->labels[i] = 0;
    return (m);
}

void    ft_swap_labels(t_matrix *mat, int to, int from)
{
    char *str;

    str = mat->labels[to];
    mat->labels[to] = mat->labels[from];
    mat->labels[from] = str;
}

void        ft_swap(t_matrix *mat, int to, char *label, int n)
{
    int from;
    int *tmp;
    int i;

    from = -1;
    while (!ft_strequ(mat->labels[++from], label))
        ;
    if (from == to)
        return ;
    tmp = (int *)malloc(sizeof(int) * n);
    i = -1;
    while (++i < n)
    {
        tmp[i] = mat->adj[i][to];
        mat->adj[i][to] = mat->adj[i][from];
        mat->adj[i][from] = tmp[i];
    }
    i = -1;
    while (++i < n)
    {
        tmp[i] = mat->adj[to][i];
        mat->adj[to][i] = mat->adj[from][i];
        mat->adj[from][i] = tmp[i];
    }
    ft_swap_labels(mat, to, from);
}

void        ft_print_matrix(t_matrix mat)
{
    int i;
    int j;
    int n;

    n = -1;
    ft_printf("___");
    while (mat.labels[++n])
        ft_printf("| %s ", mat.labels[n]);
    ft_printf("|\n");
    i = -1;
    while (++i < n)
    {
        j = -1;
        ft_printf(" %s |", mat.labels[i]);
        while (++j < n)
            ft_printf(" %d |", mat.adj[i][j]);
        ft_printf("\n");
    }
}

void        ft_free_matrix(t_matrix *mat)
{
    int i;
    int n;

    n = -1;
    while (mat->labels[++n])
        free(mat->labels[n]);
    free(mat->labels);
    i = -1;
    while (++i < n)
        free(mat->adj[i]);
    free(mat->adj);
    free(mat);
}

t_matrix    *ft_matrix_create(t_parser *p)
{
    t_matrix    *mat;

    mat = ft_init_matrix(p);
    ft_swap(mat, 0, p->start_room, p->nb_rooms);
    ft_swap(mat, p->nb_rooms - 1, p->end_room, p->nb_rooms);
    return (mat);
}