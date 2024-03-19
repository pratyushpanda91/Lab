#include <iostream>
#include <stack>

using namespace std;

class PDA
{
public:
  PDA()
  {
    state = 0;
    stack.push('$');
  }

  void push(char c)
  {
    stack.push(c);
  }

  char pop()
  {
    char c = stack.top();
    stack.pop();
    return c;
  }

  bool accept()
  {
    return state == 2 && stack.top() == '$';
  }

  void transition(char c)
  {
    switch (state)
    {
    case 0:
      if (c == 'a')
      {
        state = 1;
        push('a');
      }
      else
      {
        state = 3;
      }
      break;
    case 1:
      if (c == 'a')
      {
        push('a');
      }
      else if (c == 'b')
      {
        state = 2;
        pop();
      }
      else
      {
        state = 3;
      }
      break;
    case 2:
      if (c == 'b')
      {
        pop();
      }
      else
      {
        state = 3;
      }
      break;
    case 3:
      // Reject
      break;
    }
  }

private:
  int state;
  stack<char> stack;
};

int main()
{
  PDA pda;

  string input;
  cout << "Enter a string: ";
  cin >> input;

  for (char c : input)
  {
    pda.transition(c);
  }

  if (pda.accept())
  {
    cout << "The string is accepted." << endl;
  }
  else
  {
    cout << "The string is rejected." << endl;
  }

  return 0;
}