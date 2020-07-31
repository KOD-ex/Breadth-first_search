#include <stdio.h>
#include "breadth_first_search.h"

int check_vertex(int vertex)
{
	//нужная вершина под номером 2
	if (vertex == 2)
		return 1;
	return 0;
}

int copy_check(int edges[], int vertex)
{
	for (int i = 0; i < 100; ++i)
	{
		if (vertex == edges[i])
			return 0;
	}
	return 1;
}

int breadth_first_search(int graph[][9], int vertex)
{
	int edges[100] = {-1};
	int d = 0;

	for (int i = 0; i < 100; ++i)
		edges[i] = -1;

	for (int i = 0; i < 1000; ++i)
	{
		if (graph[vertex][i] == -1)
			break;

		edges[i] = graph[vertex][i];
	}
	for (int i = 0; i < 100; ++i)
	{
		if (check_vertex(edges[i]))
		{
			printf("%d - заданная вершина \n", edges[i]);
			break;
		}
		else
		{
			//определяем конец массива edges
			for (int g = 0; g<100; ++g)
				if (edges[g] == -1)
				{
					d = g;
					//определяем конец массива graph[edges[i]]
					for (int j = 0; graph[edges[i]][j] != -1; ++j)
					{
						//если похожих узлов graph[edges[i]][j] нет в edges
						//то мы добавляем эти узлы
						if (copy_check(edges, graph[edges[i]][j]))
							edges[d] = graph[edges[i]][j];
						d += 1;
					}
					break;
				}
					
		}

	}

	return 0;
}

void print_graph(int graph[][9])
{
	printf("\n");
	for (int j = 0; j < 9; ++j)
	{
		for (int i = 0; i < 9; ++i)
			printf("%d ", graph[j][i]);

		printf("\n");
	}
}
