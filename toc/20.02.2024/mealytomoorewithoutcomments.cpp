#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class MooreState
{
public:
  char output;

  MooreState(char output) : output(output) {}
};

class MooreMachine
{
public:
  unordered_map<char, MooreState *> transitions;
  MooreState *currentState;

  MooreMachine() : currentState(nullptr) {}

  void addTransition(char input, MooreState *nextState)
  {
    transitions[input] = nextState;
  }

  void setInitialState(MooreState *initialState)
  {
    currentState = initialState;
  }

  string simulate(const string &input)
  {
    string output;
    for (char c : input)
    {
      output += currentState->output;
      currentState = transitions[c];
    }
    output += currentState->output;
    return output;
  }
};

int main()
{
  MooreMachine mooreMachine;
  vector<MooreState *> states;
  unordered_map<string, MooreState *> stateMap;
  int numStates;
  cout << "Enter number of states: ";
  cin >> numStates;

  cout << "Enter input symbols separated by space: ";
  string inputSymbols;
  cin.ignore();
  getline(cin, inputSymbols);

  vector<char> inputs;
  for (char c : inputSymbols)
  {
    if (c != ' ')
    {
      inputs.push_back(c);
    }
  }
  for (int i = 0; i < numStates; ++i)
  {
    cout << "Enter output for state q" << i << ": ";
    char output;
    cin >> output;
    MooreState *state = new MooreState(output);
    states.push_back(state);
    stateMap["q" + to_string(i)] = state;
  }

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

  cout << "Enter initial state: ";
  cin >> currentState;
  mooreMachine.setInitialState(stateMap[currentState]);

  cout << "Enter input string: ";
  string inputString;
  cin >> inputString;

  string output = mooreMachine.simulate(inputString);
  cout << "Output string: " << output << endl;
  for (auto state : states)
  {
    delete state;
  }
  return 0;
}