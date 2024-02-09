#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void displayAdjacencyList(vector<vector<int>> &graph, int n)
{
  cout << "Adjacency List:" << endl;
  for (int i = 0; i < n; ++i)
  {
    int degree = 0;
    cout << "Vertex " << i << " -> ";
    for (int j = 0; j < n; ++j)
    {
      if (graph[i][j] == 1)
      {
        cout << j << " ";
        degree++;
      }
    }
    cout << "(Degree: " << degree << ")" << endl;
  }

  vector<int> degreeSequence(n, 0);
  for (int i = 0; i < n; ++i)
  {
    int degree = 0;
    for (int j = 0; j < n; ++j)
    {
      if (graph[i][j] == 1)
      {
        degree++;
      }
    }
    degreeSequence[i] = degree;
  }

  cout << "Degree Sequence: ";
  for (int i = 0; i < n; ++i)
  {
    cout << degreeSequence[i] << " ";
  }
  cout << endl;
}

bool areIsomorphic(vector<vector<int>> &graph1, vector<vector<int>> &graph2, int n)
{
  for (int i = 0; i < n; ++i)
  {
    sort(graph1[i].begin(), graph1[i].end());
    sort(graph2[i].begin(), graph2[i].end());
  }

  sort(graph1.begin(), graph1.end());
  sort(graph2.begin(), graph2.end());

  return graph1 == graph2;
}

int main()
{
  int n; // Number of vertices in the graph

  cout << "Enter the number of vertices: ";
  cin >> n;

  vector<vector<int>> graph1(n, vector<int>(n, 0));
  vector<vector<int>> graph2(n, vector<int>(n, 0));

  cout << "Enter the adjacency matrix for the first graph: " << endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      cin >> graph1[i][j];
  }

  displayAdjacencyList(graph1, n);

  cout << "Enter the adjacency matrix for the second graph: " << endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      cin >> graph2[i][j];
  }

  displayAdjacencyList(graph2, n);

  if (areIsomorphic(graph1, graph2, n))
    cout << "The graphs are isomorphic." << endl;
  else
    cout << "The graphs are not isomorphic." << endl;

  return 0;
}
