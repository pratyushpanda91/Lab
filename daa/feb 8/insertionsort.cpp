// C++ program for insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n)
{
  int i;
  cout << "The sorted array is: ";
  for (i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int arr[200], i, N;
  cout << "Enter the size of array";
  cin >> N;
  cout << "Enter the elements" << endl;
  for (i = 0; i < N; i++)
  {
    cin >> arr[i];
  }
  cout << "The unsorted array is: ";
  for (i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  insertionSort(arr, N);
  printArray(arr, N);

  return 0;
}