#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int arr[], int low, int high)
{

  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, i + 1, high);
  return i + 1;
}
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {

    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{

  // int arr[]={10,7,8,9,1,5};
  // int n=sizeof(arr)/sizeof(arr[0]);
  // quickSort(arr,0,n-1);
  int arr[200], i, n;
  cout << "enter the size of array";
  cin >> n;
  cout << "enter the elements" << endl;
  for (i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);
  cout << "Sorted Array\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}