#include "lem_in.h"

int capacities[10][10];

int flowPassed[10][10];

int parentsList[10];       

int currentPathCapacity[10]; 

int bfs(int startNode, int endNode, )
{
    memset(parentsList, -1, sizeof(parentsList));
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
    t_list *q;

    q = ft_lstnew(startNode, sizeof(int));
    // PUSH ft_lstadd(&q, ft_lstnew(INT));
    q.push(startNode);

    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = 999;

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for(int i=0; i<graph[currentNode].size(); i++)
        {
            int to = graph[currentNode][i];
            if(parentsList[to] == -1)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode], 
                    capacities[currentNode][to] - flowPassed[currentNode][to]);
                    if(to == endNode)
                    {
                        return currentPathCapacity[endNode];
                    }
                    q.push(to);
                }

            }
        }
    }
    return 0;
}


int edmondsKarp(int startNode, int endNode)
{
    int maxFlow = 0;
      while(1)
    {
        int flow = bfs(startNode, endNode);
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

int     **ft_solve(t_matrix *mat)
{
    int **path;

    path = ft_solve(mat);
    return (path);
}