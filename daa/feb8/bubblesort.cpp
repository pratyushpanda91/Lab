#include <bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}
void printArray(int arr[], int size)
{
  int i;
  cout << "The sorted array is: ";
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int arr[20000], i, N;
  cout << "enter the size of array";
  cin >> N;
  cout << "enter the elements" << endl;
  for (i = 0; i < N; i++)
  {
    cin >> arr[i];
  }
  cout << "The unsorted array is: ";
  for (i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  bubbleSort(arr, N);
  printArray(arr, N);
  return 0;
}