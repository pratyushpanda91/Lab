#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Define a class representing a Moore machine state
class MooreState
{
public:
  char output; // Output associated with the state

  // Constructor
  MooreState(char output) : output(output) {}
};

// Define a class representing a Moore machine
class MooreMachine
{
public:
  unordered_map<char, MooreState *> transitions; // Map of input characters to next states
  MooreState *currentState;                      // Current state of the machine

  // Constructor
  MooreMachine() : currentState(nullptr) {}

  // Function to add transition for an input character
  void addTransition(char input, MooreState *nextState)
  {
    transitions[input] = nextState;
  }

  // Function to set the initial state of the machine
  void setInitialState(MooreState *initialState)
  {
    currentState = initialState;
  }

  // Function to simulate the machine for a given input string
  string simulate(const string &input)
  {
    string output;
    for (char c : input)
    {
      output += currentState->output; // Add current state's output to the output string
      currentState = transitions[c];  // Transition to the next state based on the input character
    }
    output += currentState->output; // Add output of the final state
    return output;
  }
};

int main()
{
  MooreMachine mooreMachine;
  vector<MooreState *> states;
  unordered_map<string, MooreState *> stateMap;

  // Take input for number of states and input symbols
  int numStates;
  cout << "Enter number of states: ";
  cin >> numStates;

  cout << "Enter input symbols separated by space: ";
  string inputSymbols;
  cin.ignore(); // Ignore newline character in input buffer
  getline(cin, inputSymbols);

  vector<char> inputs;
  for (char c : inputSymbols)
  {
    if (c != ' ')
    {
      inputs.push_back(c);
    }
  }

  // Create and initialize Moore machine states
  for (int i = 0; i < numStates; ++i)
  {
    cout << "Enter output for state q" << i << ": ";
    char output;
    cin >> output;
    MooreState *state = new MooreState(output);
    states.push_back(state);
    stateMap["q" + to_string(i)] = state;
  }

  // Take input for transitions and create the Moore machine
  cout << "Enter transitions in the format: currentState inputSymbol nextState" << endl;
  cout << "For example, q0 a q1" << endl;
  cout << "Enter 'done' when finished." << endl;

  string currentState, nextState;
  char inputSymbol;

  while (cin >> currentState && currentState != "done")
  {
    cin >> inputSymbol >> nextState;
    mooreMachine.addTransition(inputSymbol, stateMap[nextState]);
  }

  // Set initial state of the machine
  cout << "Enter initial state: ";
  cin >> currentState;
  mooreMachine.setInitialState(stateMap[currentState]);

  // Take input string to simulate the Moore machine
  cout << "Enter input string: ";
  string inputString;
  cin >> inputString;

  // Simulate the machine and output the result
  string output = mooreMachine.simulate(inputString);
  cout << "Output string: " << output << endl;

  // Clean up memory
  for (auto state : states)
  {
    delete state;
  }

  return 0;
}