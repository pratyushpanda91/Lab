// DFA which does not accepts 110 as substring
#include <iostream>
using namespace std;

int main()
{
  string s;
  cout << "Enter a string : ";
  cin >> s;
  int state = 0;
  int temp = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '1')
    {
      if (state == 0)
        state = 1;
      else if (state == 1)
        state = 2;
      else if (state == 2)
        state = 2;
      else if (state == 3)
        state = 3;
    }
    else if (s[i] == '0')
    {
      if (state == 0)
        state = 0;
      else if (state == 1)
        state = 0;
      else if (state == 2)
        state = 2;
      else if (state == 3)
        state = 3;
    }
    else
      temp = 1;
  }
  if (temp)
    cout << "invalid string" << endl;
  else
  {
    if (state == 0 || state == 1 || state == 2)
      cout << "Accepted" << endl;
    else
      cout << "Not Accepted" << endl;
  }
}