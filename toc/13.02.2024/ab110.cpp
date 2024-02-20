#include <iostream>
#include <string>

using namespace std;

// Function to determine the output based on the state and input
char getOutput(char state)
{
  if (state == 'q1')
    return 'b';
  else if (state == 'q2')
    return 'a';
  else
    return 'c';
}

// Function to determine the next state based on the current state and input
char nextState(char currentState, char input)
{
  if (currentState == 'q0' && input == '1')
    return 'q3'; // Possible start of '101'
  else if (currentState == 'q0' && input == '0')
    return 'q0'; // Continue searching
  else if (currentState == 'q3' && input == '0')
    return 'q4'; // Possible '101'
  else if (currentState == 'q3' && input == '1')
    return 'q3'; // Continue searching
  else if (currentState == 'q4' && input == '1')
    return 'q1'; // Found '101'
  else if (currentState == 'q4' && input == '0')
    return 'q0'; // Continue searching
  else if (currentState == 'q1' || currentState == 'q2')
    return 'q2'; // Output already determined, continue to final state
  else
    return 'q0'; // Default transition
}

int main()
{
  string inputString;
  cout << "Enter a binary string: ";
  cin >> inputString;

  char currentState = 'q0'; // Initial state

  // Mealy Machine Simulation
  for (char c : inputString)
  {
    currentState = nextState(currentState, c);
  }

  // Output determined by the final state
  char output = getOutput(currentState);

  cout << "Output: " << output << endl;

  return 0;
}