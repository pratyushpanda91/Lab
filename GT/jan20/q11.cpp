#include <iostream>
#include <vector>
using namespace std;

struct node
{
  int data;
  node *next;
};

void addedge(vector<node *> &graph, int src, int dest)
{
  node *newnode = new node;
  newnode->data = dest;
  newnode->next = graph[src];
  graph[src] = newnode;
}

bool has_self_loop(vector<node *> &graph, int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    node *current = graph[i];
    while (current)
    {
      if (current->data == i)
      {
        return true;
      }
      current = current->next;
    }
  }
  return false;
}

int parallel_edges(vector<node *> &graph, int vertices)
{
  int paralleledges = 0;
  for (int i = 0; i < vertices; ++i)
  {
    vector<int> visited(vertices, 0);
    node *current = graph[i];
    while (current)
    {
      if (visited[current->data] == 1)
      {
        paralleledges++;
      }
      visited[current->data] = 1;
      current = current->next;
    }
  }
  return paralleledges;
}

void vertex_degree(vector<node *> &graph, int vertices)
{
  for (int i = 0; i < vertices; ++i)
  {
    int degree = 0;
    node *current = graph[i];
    while (current)
    {
      degree++;
      current = current->next;
    }
    cout << "The degree of the vertex " << i << " is " << degree << endl;
  }
}

void displayAdjacencyList(vector<node *> &graph, int vertices)
{
  cout << "Adjacency List:" << endl;
  for (int i = 0; i < vertices; ++i)
  {
    cout << "Vertex " << i << " -> ";
    node *current = graph[i];
    while (current)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
}

int main()
{
  int vertices, edges;
  cout << "Enter number of vertices (by the user): ";
  cin >> vertices;
  cout << "Enter number of edges (by the user): ";
  cin >> edges;
  vector<node *> graph(vertices, nullptr);
  cout << "Enter the path formed by vertices and edges: " << endl;
  for (int i = 0; i < edges; ++i)
  {
    int src, dest;
    cin >> src >> dest;
    addedge(graph, src, dest);
  }

  // Display the adjacency list
  displayAdjacencyList(graph, vertices);

  if (has_self_loop(graph, vertices))
  {
    cout << "Graph contains a self loop" << endl;
  }
  else
  {
    cout << "Graph does not contain a self loop" << endl;
  }

  int paralleledges = parallel_edges(graph, vertices);
  cout << "The number of parallel edges is " << paralleledges << endl;

  vertex_degree(graph, vertices);

  return 0;
}
