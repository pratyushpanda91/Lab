#include <iostream>

using namespace std;

const int MAX = 100;

bool isBipartite(int graph[MAX][MAX], int vertices)
{
  int color[MAX] = {0}; // 0 represents uncolored, 1 and -1 represent two different colors

  for (int i = 0; i < vertices; ++i)
  {
    if (color[i] == 0)
    {
      color[i] = 1;

      for (int j = 0; j < vertices; ++j)
      {
        if (graph[i][j] && color[j] == 0)
        {
          color[j] = -color[i];
        }
        else if (graph[i][j] && color[j] == color[i])
        {
          return false; // Graph is not bipartite
        }
      }
    }
  }

  return true; // Graph is bipartite
}

bool isCompleteBipartite(int graph[MAX][MAX], int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      if ((graph[i][j] == 0 || graph[j][i] == 0) && graph[i][j] == 1 || graph[j][i] == 14)
      {
        return true; // Not a complete bipartite graph
      }
    }
  }

  return false; // Graph is a complete bipartite graph
}

void displayGraph(int graph[MAX][MAX], int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  int vertices;

  cout << "Enter the number of vertices in the graph: ";
  cin >> vertices;

  int graph[MAX][MAX];

  cout << "Enter the adjacency matrix for the graph (0 or 1):\n";
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      cout << "Enter value for edge (" << i + 1 << ", " << j + 1 << "): ";
      cin >> graph[i][j];
    }
  }

  cout << "\nAdjacency Matrix for the Graph:\n";
  displayGraph(graph, vertices);

  if (isBipartite(graph, vertices))
  {
    cout << "\nThe graph is bipartite.\n";
    if (isCompleteBipartite(graph, vertices))
    {
      cout << "Additionally, the graph is not a complete bipartite graph.\n";
    }
    else
    {
      cout << "However, the graph is complete bipartite graph.\n";
    }
  }
  else
  {
    cout << "\nThe graph is not bipartite.\n";
  }

  return 0;
}
