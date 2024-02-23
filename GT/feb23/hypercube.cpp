#include <iostream>

using namespace std;

void findAdjacentVertices(int vertex, int dimension, int *adjacentVertices)
{
  for (int i = 0; i < dimension; ++i)
  {
    int adjacentVertex = vertex ^ (1 << i);
    adjacentVertices[i] = adjacentVertex;
  }
}

int main()
{
  int dimension;
  cout << "Enter the dimension of the hypercube: ";
  cin >> dimension;

  int totalVertices = 1 << dimension;
  int totalEdges = dimension * totalVertices / 2;

  cout << "Total number of vertices: " << totalVertices << endl;
  cout << "Total number of edges: " << totalEdges << endl;

  int vertex;
  do
  {
    cout << "Enter a vertex (0 to " << totalVertices - 1 << "): ";
    cin >> vertex;

    if (vertex < 0 || vertex >= totalVertices)
    {
      cout << "Invalid vertex. Please enter a valid vertex within the range." << endl;
    }
  } while (vertex < 0 || vertex >= totalVertices);

  int *adjacentVertices = new int[dimension];
  findAdjacentVertices(vertex, dimension, adjacentVertices);

  cout << "Adjacent vertices of vertex " << vertex << ": ";
  for (int i = 0; i < dimension; ++i)
  {
    cout << adjacentVertices[i] << " ";
  }
  cout << endl;

  delete[] adjacentVertices;

  return 0;
}
