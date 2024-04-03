// w c wreverse
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
      if (it == 'a' && st.top() == 'z')
        st.push('a');
      else if (it == 'b' && st.top() == 'z')
        st.push('b');
      else if (it == 'b' && st.top() == 'a')
        st.push('b');
      else if (it == 'b' && st.top() == 'b')
        st.push('b');
      else if (it == 'a' && st.top() == 'a')
        st.push('a');
      else if (it == 'a' && st.top() == 'b')
        st.push('a');
      else if (it == 'c' && st.top() == 'z')
        state = 1;
      else if (it == 'c' && st.top() == 'a')
        state = 1;
      else if (it == 'c' && st.top() == 'b')
        state = 1;
      else
        state = 3;
    }
    else if (state == 1)
    {
      if (it == 'a' && st.top() == 'a')
        st.pop();
      else if (it == 'b' && st.top() == 'b')
        st.pop();
      else if (it == '&' && st.top() == 'z')
        state = 2;
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