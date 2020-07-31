#include "breadth_first_search.h"
#include <stdio.h>

int main()
{
	int graph[9][9];
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			graph[i][j] = -1;
	

	int connect;

	for (int i = 0; i < 9; ++i)
	{
	 	printf("%d: \n", i);

	 	for (int j = 0; j < 9; ++j)
	 	{
	 		scanf("%d", &connect);
	 		if (connect == -1)
	 			break;

	 		graph[i][j] = connect;
	 	}
	}

	breadth_first_search(graph, 0);

	//print graph
	print_graph(graph);
	

	return 0;
}
