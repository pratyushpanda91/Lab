// output is equal to no of 1 mod 2

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
    }
    else if (s[i] == '1')
    {
      if (state == 0)
        state = 1;
      else
        state = 0;
    }
    else
    {
      cout << "Invalid input\n";
      return;
    }
    if (state == 1)
      ans += "0";
    else
      ans += "1";
  }

  cout << "moore:" << ans << endl;
}

void mealy(string s)
{
  int state = 0;
  string ans = "";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '0')
    {
    }
    else if (s[i] == '1')
    {
      if (state == 0)
        state = 1;
      else
        state = 0;
    }
    else
    {
      cout << "Invalid input\n";
      return;
    }
    if (state == 1)
      ans += "0";
    else
      ans += "1";
  }

  cout
      << "mealy:" << ans << endl;
}

int main()
{
  string s;
  cout << "Enter the string:";
  cin >> s;
  // s+="#";
  moore(s);
  mealy(s);
}