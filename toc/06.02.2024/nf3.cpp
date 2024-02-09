// design a nfa starting with 1 ending with 0 or start with 0 end with 1

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string s;
  cout << "Enter the string :";
  cin >> s;
  vector<int> state;
  state.push_back(0);
  for (int i = 0; i < s.size(); i++)
  {

    int x = state.size();

    for (int j = 0; j < x; j++)
    {
      if (state[0] == 4)
      {
        state.push_back(4);
        state.erase(state.begin());
        continue;
      }
      if (s[i] == '1')
      {
        if (state[0] == 0)
        {
          state.push_back(3);
        }
        else if (state[0] == 1)
        {
          state.push_back(4);
        }
        else if (state[0] == 2)
        {
          state.push_back(1);
          state.push_back(2);
        }
        else if (state[0] == 3)
        {
          state.push_back(3);
        }
      }
      else if (s[i] == '0')
      {
        if (state[0] == 0)
        {
          state.push_back(2);
        }
        else if (state[0] == 1)
        {
          state.push_back(4);
        }
        else if (state[0] == 2)
        {
          state.push_back(2);
        }
        else if (state[0] == 3)
        {
          state.push_back(1);
          state.push_back(3);
        }
      }
      else
      {
        cout << "Invalid input\n";
        return 0;
      }
      state.erase(state.begin());
    }
  }

  for (auto it : state)
  {
    if (it == 1)
    {
      cout << "string accepted\n";
      return 0;
    }
  }
  cout << "String rejected\n";
  return 0;
}