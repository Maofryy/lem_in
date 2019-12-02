#include "lem_in.h"

int capacities[10][10];

int flowPassed[10][10];

int parentsList[10];       

int currentPathCapacity[10]; 

int bfs(int startNode, int endNode, t_matrix *mat)
{
    memset(parentsList, -1, sizeof(parentsList));
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
    t_list *q;

    q = ft_list_new(startNode);
    // PUSH ft_list_push(&q, int);

    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = 999;

    while(ft_list_size(q) != 0)
    {
        int i;
        int currentNode = ft_list_pop(&q);

        // for(int i=0; i < mat->adj[currentNode].size(); i++)
        i = -1;
        while (i < mat->size)
        {
            int to = mat->adj[currentNode][i];
            if(parentsList[to] == -1)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = ft_min(currentPathCapacity[currentNode], 
                    capacities[currentNode][to] - flowPassed[currentNode][to]);
                    if(to == endNode)
                    {
                        return currentPathCapacity[endNode];
                    }
                    ft_list_push(&q, to);
                }

            }
        }
    }
    return 0;
}


int edmondsKarp(int startNode, int endNode, t_matrix *mat)
{
    int maxFlow = 0;
      while(1)
    {
        int flow = bfs(startNode, endNode, mat);
        if (flow == 0) 
            break;
        maxFlow += flow;
        int currentNode = endNode;
        while(currentNode != startNode)
        {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }
    }
    return maxFlow;
}

int     ft_solve(t_matrix *mat)
{
    int flow;

    flow = edmondsKarp(0, mat->size - 1, mat);
    return (flow);
}