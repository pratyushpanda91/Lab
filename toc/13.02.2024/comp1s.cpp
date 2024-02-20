// 1's complement
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
      state = 1;
      ans += "1";
    }
    else if (s[i] == '1')
    {
      state = 0;
      ans += "0";
    }
    else
    {
      cout << "Invalid input\n";
      return;
    }
  }
  cout << "moore:" << ans << endl;
}

void mealy(string s)
{
  string ans = "";
  int state = 0;
  for (auto it : s)
  {
    if (it == '1')
      ans += "0";
    else if (it == '0')
      ans += "1";
    else
    {
      cout << "Invalid input";
      return;
    }
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
