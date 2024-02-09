#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item
{
  int weight;
  int value;
  double ratio;
};
bool compare(Item a, Item b)
{
  return a.ratio > b.ratio;
}
double fractionalKnapsack(int W, vector<Item> &items)
{
  sort(items.begin(), items.end(), compare);
  double totalvalue = 0;
  int currentweight = 0;
  for (int i = 0; i < items.size(); i++)
  {
    if (currentweight + items[i].weight <= W)
    {
      currentweight += items[i].weight;
      totalvalue += items[i].value;
    }
    else
    {
      int remainingweight = W - currentweight;
      totalvalue += items[i].ratio * remainingweight;
      break;
    }
  }
  return totalvalue;
}
int main()
{
  int n, W;
  cout << "Enter the number of items:";
  cin >> n;
  cout << "Enter the capacity of the knapsack:";
  cin >> W;
  vector<Item> items(n);
  cout << "Enter the weight and value of each item:" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> items[i].weight >> items[i].value;
    items[i].ratio = (double)items[i].value / items[i].weight;
  }
  double maxvalue = fractionalKnapsack(W, items);
  cout << "Maximum value obtained from the knapsack:" << maxvalue << endl;
  return 0;
}
