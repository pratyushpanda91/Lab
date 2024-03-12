#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
  unordered_set<char> states;
  unordered_map<char, vector<char>> tt = {
      {'0', {'1', '2'}},
      {'1', {'0', '3'}},
      {'2', {'4', '5'}},
      {'3', {'4', '5'}},
      {'4', {'4', '5'}},
      {'5', {'5', '5'}}};
  int n = tt.size();
  cout << "Transition Table: " << endl;
  for (auto i : tt)
  {
    cout << i.first << ": ";
    cout << "{" << i.second[0] << "," << i.second[1] << "}" << endl;
    states.insert(i.first);
  }
  unordered_set<char> final = {'2', '3', '4'}, non_final = {'0', '1', '5'};
  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      char state1 = '0' + i, state2 = '0' + j;
      for (int k = 0; k < 2; ++k)
      {
        if ((final.count(tt[state1][k]) && !final.count(tt[state2][k])) ||
            (!final.count(tt[state1][k]) && final.count(tt[state2][k])))
        {
          mat[i][j] = 1;
          mat[j][i] = 1;
        }
      }
    }
  }
  cout << "\nStates which can be combined are: " << endl;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (mat[i][j] == 0)
      {
        cout << i << " " << j << endl;
      }
    }
  }
  cout << "\nMatrix: \n";
  for (int i = 1; i < n; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}