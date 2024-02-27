#include <bits/stdc++.h>
using namespace std;

// Mealy to Moore machine
int main()
{
  int states;
  cout << "Enter the number of states in the Mealy machine: ";
  cin >> states;
  vector<vector<pair<int, char>>> mealy(states, vector<pair<int, char>>(2));
  for (int i = 0; i < states; ++i)
  {
    cout << "Enter transition of state " << i << " for input 0 : ";
    cin >> mealy[i][0].first;
    cout << "Enter output of state " << i << " for input 0 : ";
    cin >> mealy[i][0].second;
    cout << "Enter transition of state " << i << " for input 1 : ";
    cin >> mealy[i][1].first;
    cout << "Enter output of state " << i << " for input 1 : ";
    cin >> mealy[i][1].second;
  }
  cout << "Mealy machine is:\n";
  cout << "State\t0\t1\n";
  for (int i = 0; i < states; ++i)
  {
    cout << i << "\t(" << mealy[i][0].first << "," << mealy[i][0].second << ")\t" << '(' << mealy[i][1].first << "," << mealy[i][1].second << ")\n";
  }
  cout << "\n";

  vector<pair<vector<int>, char>> moore(states * 2, pair<vector<int>, char>(vector<int>(2, -1), '2'));
  for (int i = 0; i < states; ++i)
  {
    if (mealy[i][0].second == '0')
    {
      moore[2 * mealy[i][0].first].second = mealy[i][0].second;
      moore[2 * i].first[0] = 2 * mealy[i][0].first;
      moore[2 * i + 1].first[0] = 2 * mealy[i][0].first;
    }
    else
    {
      moore[2 * mealy[i][0].first + 1].second = mealy[i][0].second;
      moore[2 * i + 1].first[0] = 2 * mealy[i][0].first + 1;
      moore[2 * i].first[0] = 2 * mealy[i][0].first + 1;
    }
    if (mealy[i][1].second == '0')
    {
      moore[2 * mealy[i][1].first].second = mealy[i][1].second;
      moore[2 * i + 1].first[1] = 2 * mealy[i][1].first;
      moore[2 * i].first[1] = 2 * mealy[i][1].first;
    }
    else
    {
      moore[2 * mealy[i][1].first + 1].second = mealy[i][1].second;
      moore[2 * i + 1].first[1] = 2 * mealy[i][1].first + 1;
      moore[2 * i].first[1] = 2 * mealy[i][1].first + 1;
    }
  }

  cout << "Moore machine is:\n";
  cout << "State\t0\t1\tOutput\n";
  for (int i = 0; i < states * 2; ++i)
  {
    cout << i << "\t" << moore[i].first[0] << "\t" << moore[i].first[1] << "\t" << moore[i].second << "\n";
  }
  return 0;
}