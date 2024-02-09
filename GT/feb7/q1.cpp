#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>> &graph, int vertices, int source, int destination)
{
  vector<int> distance(vertices, INF);
  vector<int> parent(vertices, -1);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  distance[source] = 0;
  pq.push({0, source});

  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    for (const auto &neighbor : graph[u])
    {
      int v = neighbor.first;
      int weight = neighbor.second;

      if (distance[u] + weight < distance[v])
      {
        distance[v] = distance[u] + weight;
        parent[v] = u;
        pq.push({distance[v], v});
      }
    }
  }

  // Print the shortest path and its cost
  cout << "Shortest Path from " << source << " to " << destination << ": ";
  if (distance[destination] == INF)
  {
    cout << "No path exists" << endl;
  }
  else
  {
    vector<int> path;
    int current = destination;
    while (current != -1)
    {
      path.push_back(current);
      current = parent[current];
    }

    for (int i = path.size() - 1; i >= 0; --i)
    {
      cout << path[i];
      if (i > 0)
        cout << " -> ";
    }

    cout << "\nCost of the Shortest Path: " << distance[destination] << endl;
  }
}

int main()
{
  int vertices, edges;
  cout << "Enter the number of vertices and edges: ";
  cin >> vertices >> edges;

  vector<vector<pair<int, int>>> graph(vertices);

  cout << "Enter the edges and weights (source destination weight):" << endl;
  for (int i = 0; i < edges; ++i)
  {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w}); // Assuming undirected graph
  }

  int source, destination;
  cout << "Enter the source and destination vertices: ";
  cin >> source >> destination;

  dijkstra(graph, vertices, source, destination);

  return 0;
}
