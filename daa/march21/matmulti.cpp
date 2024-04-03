#include <iostream>
#include <vector>

using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> matrixMultiplication(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2)
{
  int rows1 = mat1.size();
  int cols1 = mat1[0].size();
  int cols2 = mat2[0].size();

  vector<vector<int>> result(rows1, vector<int>(cols2, 0));

  for (int i = 0; i < rows1; ++i)
  {
    for (int j = 0; j < cols2; ++j)
    {
      for (int k = 0; k < cols1; ++k)
      {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  return result;
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>> &matrix)
{
  for (const auto &row : matrix)
  {
    for (int element : row)
    {
      cout << element << " ";
    }
    cout << endl;
  }
}

int main()
{
  int rows1, cols1, rows2, cols2;

  // Input for first matrix
  cout << "Enter the number of rows and columns of the first matrix: ";
  cin >> rows1 >> cols1;

  vector<vector<int>> matrix1(rows1, vector<int>(cols1));

  cout << "Enter the elements of the first matrix:" << endl;
  for (int i = 0; i < rows1; ++i)
  {
    for (int j = 0; j < cols1; ++j)
    {
      cin >> matrix1[i][j];
    }
  }

  // Input for second matrix
  cout << "Enter the number of rows and columns of the second matrix: ";
  cin >> rows2 >> cols2;

  vector<vector<int>> matrix2(rows2, vector<int>(cols2));

  cout << "Enter the elements of the second matrix:" << endl;
  for (int i = 0; i < rows2; ++i)
  {
    for (int j = 0; j < cols2; ++j)
    {
      cin >> matrix2[i][j];
    }
  }

  // Check if matrices can be multiplied
  if (cols1 != rows2)
  {
    cout << "Matrices cannot be multiplied." << endl;
    return 0;
  }

  // Perform multiplication
  vector<vector<int>> result = matrixMultiplication(matrix1, matrix2);

  // Display the result
  cout << "Resultant matrix:" << endl;
  displayMatrix(result);

  return 0;
}