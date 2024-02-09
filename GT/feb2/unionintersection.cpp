#include <iostream>

const int MAX = 100;

void inputGraph(int graph[MAX][MAX], int vertices)
{
  std::cout << "Enter the adjacency matrix for the graph (0 or 1):\n";
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      std::cout << "Enter value for edge (" << i + 1 << ", " << j + 1 << "): ";
      std::cin >> graph[i][j];
    }
  }
}

void displayGraph(int graph[MAX][MAX], int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      std::cout << graph[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void findUnion(int graph1[MAX][MAX], int graph2[MAX][MAX], int result[MAX][MAX], int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      result[i][j] = graph1[i][j] || graph2[i][j];
    }
  }
}

void findIntersection(int graph1[MAX][MAX], int graph2[MAX][MAX], int result[MAX][MAX], int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      result[i][j] = graph1[i][j] && graph2[i][j];
    }
  }
}

int main()
{
  int vertices;

  std::cout << "Enter the number of vertices in the graphs: ";
  std::cin >> vertices;

  int graph1[MAX][MAX], graph2[MAX][MAX], unionResult[MAX][MAX], intersectionResult[MAX][MAX];

  inputGraph(graph1, vertices);
  inputGraph(graph2, vertices);

  findUnion(graph1, graph2, unionResult, vertices);
  findIntersection(graph1, graph2, intersectionResult, vertices);

  std::cout << "\nAdjacency Matrix for Graph 1:\n";
  displayGraph(graph1, vertices);

  std::cout << "\nAdjacency Matrix for Graph 2:\n";
  displayGraph(graph2, vertices);

  std::cout << "\nUnion of Graph 1 and Graph 2:\n";
  displayGraph(unionResult, vertices);

  std::cout << "\nIntersection of Graph 1 and Graph 2:\n";
  displayGraph(intersectionResult, vertices);

  return 0;
}
