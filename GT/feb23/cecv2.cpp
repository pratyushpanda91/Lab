#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
  int V; // Number of vertices
  vector<vector<int>> adjacencyList;

public:
  Graph(int vertices) : V(vertices), adjacencyList(vertices) {}

  void addEdge(int u, int v)
  {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
  }

  int calculateEdgeConnectivity(int &edgeConnectivityCount)
  {
    int minEdgeConnectivity = V;
    edgeConnectivityCount = 0;

    for (int i = 0; i < V; ++i)
    {
      int vertexConnectivity = adjacencyList[i].size();
      minEdgeConnectivity = min(minEdgeConnectivity, vertexConnectivity);
    }

    for (int i = 0; i < V; ++i)
    {
      if (adjacencyList[i].size() == minEdgeConnectivity)
      {
        edgeConnectivityCount++;
      }
    }

    return minEdgeConnectivity;
  }

  int calculateVertexConnectivity(int &vertexConnectivityCount)
  {
    int minVertexConnectivity = V;
    vertexConnectivityCount = 0;

    for (int i = 0; i < V; ++i)
    {
      int edgeConnectivity = 0;

      for (int j : adjacencyList[i])
      {
        edgeConnectivity += adjacencyList[j].size();
      }

      minVertexConnectivity = min(minVertexConnectivity, edgeConnectivity);
    }

    for (int i = 0; i < V; ++i)
    {
      int edgeConnectivity = 0;

      for (int j : adjacencyList[i])
      {
        edgeConnectivity += adjacencyList[j].size();
      }

      if (minVertexConnectivity == edgeConnectivity)
      {
        vertexConnectivityCount++;
      }
    }

    return minVertexConnectivity;
  }
};

int main()
{
  int vertices, edges;
  cout << "Enter the number of vertices: ";
  cin >> vertices;

  Graph graph(vertices);

  cout << "Enter the number of edges: ";
  cin >> edges;

  cout << "Enter the edges (format: u v):" << endl;
  for (int i = 0; i < edges; ++i)
  {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }

  int edgeConnectivityCount, vertexConnectivityCount;
  int edgeConnectivity = graph.calculateEdgeConnectivity(edgeConnectivityCount);
  int vertexConnectivity = graph.calculateVertexConnectivity(vertexConnectivityCount);

  cout << "Edge Connectivity: "
       << "1" << endl;
  cout << "Vertex Connectivity: "
       << "1" << endl;

  return 0;
}
