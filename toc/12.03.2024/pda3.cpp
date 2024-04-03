// 0 power n 1 power 2n

#include <iostream>
#include <stack>
using namespace std;
int main()
{
  string s;
  cout << "Enter the string :";
  cin >> s;
  s += '&';
  int state = 0;
  stack<char> st;
  st.push('z');
  for (auto it : s)
  {
    if (state == 0)
    {
      if (it == '0' && st.top() == 'z')
      {
        st.push('x');
        st.push('x');
      }
      else if (it == '1' && st.top() == 'x')
      {
        st.pop();
        state = 1;
      }
      else if (it == '0' && st.top() == 'x')
      {
        st.push('x');
        st.push('x');
      }
      else
        state = 3;
    }
    else if (state == 1)
    {
      if (it == '1' && st.top() == 'x')
        st.pop();
      else if (it == '&' && st.top() == 'z')
      {
        state = 2;
        st.pop();
      }
      else
        state = 3;
    }
    else
      state = 3;
  }
  if (state == 2)
    cout << "string accepted\n";
  else
    cout << "string not accepted\n";
  return 0;
}