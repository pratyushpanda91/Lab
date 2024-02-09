// WAP to implement NFA to accept strings starting with 1 and ending with 0.
#include <iostream>
#include <cstring>
using namespace std;
int cst1 = 0;
int cst2 = 0;
int isValid(string str)
{
  int f = 0;
  int l = str.length();
  for (int i = 0; i < l; i++)
  {
    if ((str[i] == '0') || (str[i] == '1'))
    {
      f = 0;
    }
    else
    {
      f = 1;
      break;
    }
  }
  if (f == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int isAccepted(string str)
{

  int l = str.length();
  int tt1[4][2] = {
      {3, 1},
      {1, 1},
      {2, 1},
      {3, 3}};
  int tt2[4][2] = {// DFA
                   {3, 1},
                   {2, 1},
                   {2, 1},
                   {3, 3}};
  for (int i = 0; i < l; i++)
  {
    cst1 = tt1[cst1][str[i] - '0'];
    cst2 = tt2[cst2][str[i] - '0'];
  }
  if ((cst1 == 2) || (cst2 == 2))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int main()
{
  string str;
  cout << "Enter a string: ";
  cin >> str;
  if ((isAccepted(str)) && (isValid(str)))
  {
    cout << str << " is accepted.";
  }
  else
  {
    cout << str << " is not accepted.";
  }
  return 0;
}