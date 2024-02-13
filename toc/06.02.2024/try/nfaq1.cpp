//

#include <iostream>
#include <string>

using namespace std;

// Function to simulate the NFA
bool simulateNFA(const string &str)
{
  int currentState = 0; // Start state
  int len = str.length();

  // Iterate through the string
  for (int i = 0; i < len; ++i)
  {
    switch (currentState)
    {
    case 0: // Start state
      if (str[i] == '1')
      {
        currentState = 1; // Move to state 1 on input '1'
      }
      else
      {
        return false; // Reject if input is not '1'
      }
      break;
    case 1: // State 1
      if (i == len - 1 && str[i] == '0')
      {
        return true; // Accept if input is '0' and at the end of the string
      }
      else if (str[i] != '0' && str[i] != '1')
      {
        return false; // Reject if input is neither '0' nor '1'
      }
      break;
    }
  }
  return false; // Reject if the string does not end with '0'
}

int main()
{
  string input;
  cout << "Enter a string: ";
  cin >> input;

  if (simulateNFA(input))
  {
    cout << "Accepted\n";
  }
  else
  {
    cout << "Rejected\n";
  }

  return 0;
}