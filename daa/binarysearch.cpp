#include<iostream>
using namespace std;

int binarySearch(int arr[],int low,int high,int x){
  while (low<=high){
    int mid = low + (high - low)/2;
    if (arr [mid] == x)
    return mid;
    else if (arr [mid]<x)
    low = mid + 1;
    else
    high = mid - 1;
  }
  return -1;
}
int main (void){
  int arr[200],i,n;
  cout<<"enter the size of the array:";
  cin>>n;
  cout<<"enter the elements:"<<endl;
  for(i=0;i<n;i++){
    cin>>arr[i];
  }
  int x;
  cout<<"key:"<<endl;
  cin>>x;
  int result =binarySearch(arr,0,n-1,x);
  if(result==-1)
  {
    cout<<"Elements is not present in array";
  }
  else{
    cout<<"Element is present st index "<<result;
  }
  return 0;
}
