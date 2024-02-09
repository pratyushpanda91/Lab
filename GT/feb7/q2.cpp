#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HamiltonianCycle
{
private:
  int vertices;
  vector<vector<int>> adjMatrix;
  vector<int> path;

public:
  HamiltonianCycle(int V) : vertices(V)
  {
    adjMatrix.resize(V, vector<int>(V, 0));
    path.resize(V, -1);
  }

  void addEdge(int src, int dest)
  {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; // Assuming undirected graph
  }

  bool isSafe(int v, int pos)
  {
    if (adjMatrix[path[pos - 1]][v] == 0)
      return false;

    for (int i = 0; i < pos; ++i)
      if (path[i] == v)
        return false;

    return true;
  }

  bool hamiltonianCycleUtil(int pos)
  {
    if (pos == vertices)
    {
      // Check if there is an edge from the last vertex to the first vertex
      if (adjMatrix[path[pos - 1]][path[0]] == 1)
        return true;
      else
        return false;
    }

    for (int v = 1; v < vertices; ++v)
    {
      if (isSafe(v, pos))
      {
        path[pos] = v;

        if (hamiltonianCycleUtil(pos + 1))
          return true;

        path[pos] = -1; // Backtrack
      }
    }

    return false;
  }

  bool hasHamiltonianCycle()
  {
    path[0] = 0; // Start from the first vertex

    if (!hamiltonianCycleUtil(1))
    {
      cout << "No Hamiltonian Cycle exists in the graph." << endl;
      return false;
    }

    cout << "Hamiltonian Cycle exists in the graph. Path: ";
    for (int i = 0; i < vertices; ++i)
      cout << path[i] << " ";

    cout << path[0] << endl;
    return true;
  }
};

int main()
{
  int vertices, edges;
  cout << "Enter the number of vertices: ";
  cin >> vertices;

  HamiltonianCycle graph(vertices);

  cout << "Enter the number of edges: ";
  cin >> edges;

  for (int i = 0; i < edges; ++i)
  {
    int src, dest;
    cout << "Enter edge " << i + 1 << " (source destination): ";
    cin >> src >> dest;
    graph.addEdge(src, dest);
  }

  graph.hasHamiltonianCycle();

  return 0;
}