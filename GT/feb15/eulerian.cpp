#include <iostream>
#include <vector>

using namespace std;

bool isEulerian(vector<vector<int>> &graph)
{
  int numVertices = graph.size();

  for (int i = 0; i < numVertices; ++i)
  {
    int degree = 0;
    for (int j = 0; j < numVertices; ++j)
    {
      if (graph[i][j] == 1)
        degree++;
    }
    if (degree % 2 != 0)
      return false;
  }
  return true;
}

int main()
{
  int numVertices;
  cout << "Enter the number of vertices in the graph: ";
  cin >> numVertices;

   vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

  cout << "Enter the adjacency matrix for the graph:\n";
  for (int i = 0; i < numVertices; ++i)
  {
    for (int j = 0; j < numVertices; ++j)
    {
      cin >> graph[i][j];
    }
  }

  if (isEulerian(graph))
  {
    cout << "The given graph is Eulerian as each vertex have even degree.\n";
  }
  else
  {
    cout << "The given graph is not Eulerian as each vertex have not even degree.\n";
  }

  return 0;
}