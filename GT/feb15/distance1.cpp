
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
const int INF = 1000;

vector<int> shortestDistances(int source, const vector<vector<int>> &graph)
{
  int n = graph.size();
  vector<int> distances(n, INF);
  distances[source] = 0;
  queue<int> q;
  q.push(source);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; ++v)
    {
      if (graph[u][v] && distances[v] == INF)
      {
        distances[v] = distances[u] + 1;
        q.push(v);
      }
    }
  }
  return distances;
}

int distanceBetweenVertices(int u, int v, const vector<vector<int>> &graph)
{
  vector<int> distances = shortestDistances(u, graph);
  return distances[v];
}

void find(vector<int> &ecentricity, int &radius, int &diameter)
{
  for (auto it : ecentricity)
  {
    radius = min(radius, it);
    diameter = max(diameter, it);
  }
}

int main()
{
  int n;
  cout << "Enter the number of vertices: ";
  cin >> n;

  vector<vector<int>> graph(n, vector<int>(n));
  cout << "Enter the adjacency matrix:\n";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> graph[i][j];
    }
  }

  vector<vector<int>> d(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int distUV = distanceBetweenVertices(i, j, graph);
      d[i][j] = distUV;
    }
  }
  cout << "Matrix representing distance between vertices:" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Eccentricity of each vertex:\n";
  vector<int> e;
  for (int i = 0; i < n; ++i)
  {
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
      ans = max(ans, d[i][j]);
    }
    e.push_back(ans);
  }
  for (int i = 0; i < n; i++)
  {
    cout << e[i] << " ";
  }
  int radius = INT_MAX;
  int diameter = INT_MIN;
  find(e, radius, diameter);
  cout << "\nRadius is :" << radius << endl;
  cout << "\nDiameter is :" << diameter << endl;
  return 0;
}