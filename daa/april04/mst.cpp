#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
  int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset
{
  int parent, rank;
};

class Graph
{
  int V;              // Number of vertices
  vector<Edge> edges; // Vector to store all edges

public:
  Graph(int v) : V(v) {}

  // Function to add an edge to the graph
  void addEdge(int src, int dest, int weight)
  {
    edges.push_back({src, dest, weight});
  }

  // Utility function to find set of an element
  int find(vector<Subset> &subsets, int i)
  {
    if (subsets[i].parent != i)
      subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
  }

  // Utility function to perform union of two sets
  void Union(vector<Subset> &subsets, int x, int y)
  {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
      subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
      subsets[yroot].parent = xroot;
    else
    {
      subsets[yroot].parent = xroot;
      subsets[xroot].rank++;
    }
  }

  // Function to find Minimum Spanning Tree using Kruskal's algorithm
  void KruskalMST()
  {
    vector<Edge> result;
    int e = 0, i = 0;

    // Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    vector<Subset> subsets(V);

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
      subsets[v].parent = v;
      subsets[v].rank = 0;
    }

    // Keep adding edges until there are V-1 edges in the MST
    while (e < V - 1 && i < edges.size())
    {
      Edge next_edge = edges[i++];

      int x = find(subsets, next_edge.src);
      int y = find(subsets, next_edge.dest);

      // If including this edge does not cause cycle, include it
      if (x != y)
      {
        result.push_back(next_edge);
        Union(subsets, x, y);
        ++e;
      }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:" << endl;
    for (const auto &edge : result)
    {
      cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
  }
};

int main()
{
  int V, E;
  cout << "Enter the number of vertices: ";
  cin >> V;
  cout << "Enter the number of edges: ";
  cin >> E;

  Graph graph(V);

  cout << "Enter the source, destination, and weight of each edge:" << endl;
  for (int i = 0; i < E; ++i)
  {
    int src, dest, weight;
    cin >> src >> dest >> weight;
    graph.addEdge(src, dest, weight);
  }

  graph.KruskalMST();

  return 0;
}
