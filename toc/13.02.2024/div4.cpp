// output when divisible by 4

#include <iostream>
using namespace std;
void moore(string s)
{
  int state = 0;
  string ans = "0";

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '0')
    {
      if (state == 0)
        state = 0;
      else if (state == 1)
        state = 2;
      else if (state == 2)
        state = 0;
      else
        state = 2;
    }
    else if (s[i] == '1')
    {
      if (state == 0)
        state = 1;
      else if (state == 1)
        state = 3;
      else if (state == 2)
        state = 1;
      else
        state = 3;
    }
    else
    {
      cout << "Invalid input\n";
      return;
    }
    ans += to_string(state);
  }
  cout << "moore:" << ans;
}

void mealy(string s)
{
  int state = 0;
  string ans = "";

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '0')
    {
      if (state == 0)
        state = 0;
      else if (state == 1)
        state = 2;
      else if (state == 2)
        state = 0;
      else
        state = 2;
    }
    else if (s[i] == '1')
    {
      if (state == 0)
        state = 1;
      else if (state == 1)
        state = 3;
      else if (state == 2)
        state = 1;
      else
        state = 3;
    }
    else
    {
      cout << "Invalid input\n";
      return;
    }
    ans += to_string(state);
  }
  cout << "mealy:" << ans << endl;
}

int main()
{
  string s;
  cout << "Enter the string:";
  cin >> s;
  moore(s);
  mealy(s);
}