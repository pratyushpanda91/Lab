#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if the graph is complete
bool isCompleteGraph(const vector<vector<int>> &adjacencyMatrix)
{
  int vertices = adjacencyMatrix.size();
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      if (i != j && adjacencyMatrix[i][j] != 1)
      {
        return false;
      }
    }
  }
  return true;
}

// Function to calculate the number of spanning trees using n^(n-2) formula
int countSpanningTreesCompleteGraph(int vertices)
{
  return pow(vertices, vertices - 2);
}

// Function to calculate the number of spanning trees using Kirchhoff's matrix tree theorem
int countSpanningTreesIncompleteGraph(const vector<vector<int>> &adjacencyMatrix)
{
  int vertices = adjacencyMatrix.size();

  // Create the Laplacian matrix
  vector<vector<int>> laplacianMatrix(vertices, vector<int>(vertices, 0));
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      laplacianMatrix[i][i] += adjacencyMatrix[i][j];
      laplacianMatrix[i][j] = -adjacencyMatrix[i][j];
    }
  }

  // Remove the last row and column
  laplacianMatrix.pop_back();
  for (int i = 0; i < vertices - 1; ++i)
  {
    laplacianMatrix[i].pop_back();
  }

  // Calculate the determinant of the reduced matrix
  int determinant = 1;
  for (int i = 0; i < vertices - 1; ++i)
  {
    determinant *= laplacianMatrix[i][i];
  }

  return abs(determinant);
}

int main()
{
  int vertices;
  cout << "Enter the number of vertices: ";
  cin >> vertices;

  vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

  cout << "Enter the adjacency matrix (0 or 1):" << endl;
  for (int i = 0; i < vertices; ++i)
  {
    for (int j = 0; j < vertices; ++j)
    {
      cin >> adjacencyMatrix[i][j];
    }
  }

  if (isCompleteGraph(adjacencyMatrix))
  {
    cout << "The graph is complete." << endl;
    cout << "Number of spanning trees: " << countSpanningTreesCompleteGraph(vertices) << endl;
  }
  else
  {
    cout << "The graph is incomplete." << endl;
    cout << "Number of spanning trees: " << countSpanningTreesIncompleteGraph(adjacencyMatrix) << endl;
  }

  return 0;
}
