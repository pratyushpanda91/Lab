// Write a program to implement DFA to accept strings which either starts with '01' or ends with '01' cst = current state
#include <iostream>
#include <cstring>
using namespace std;
int cst = 0;
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
  int tt[6][2] = {
      {1, 3},
      {4, 2},
      {2, 2},
      {4, 3},
      {4, 5},
      {4, 3}};
  for (int i = 0; i < l; i++)
  {
    cst = tt[cst][str[i] - '0'];
  }
  if ((cst == 2) || (cst == 5))
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