#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent each item
struct Item
{
  int weight;
  int value;
};

// Function to solve 0-1 knapsack problem
int knapsack(vector<Item> &items, int capacity)
{
  int n = items.size();
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  for (int i = 1; i <= n; ++i)
  {
    for (int w = 1; w <= capacity; ++w)
    {
      if (items[i - 1].weight <= w)
      {
        dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  return dp[n][capacity];
}

int main()
{
  int n; // Number of items
  cout << "Enter the number of items: ";
  cin >> n;

  vector<Item> items(n);
  cout << "Enter the weight and value of each item:" << endl;
  for (int i = 0; i < n; ++i)
  {
    cout << "Item " << i + 1 << ":" << endl;
    cout << "Weight: ";
    cin >> items[i].weight;
    cout << "profit: ";
    cin >> items[i].value;
  }

  int capacity;
  cout << "Enter the capacity of the knapsack: ";
  cin >> capacity;

  int max_value = knapsack(items, capacity);
  cout << "Maximum profit that can be obtained: " << max_value << endl;

  return 0;
}