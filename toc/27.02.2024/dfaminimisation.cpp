#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

// DFA structure
struct DFA
{
  int numStates;
  set<char> alphabet;
  vector<set<int>> states;
  set<int> finalStates;
  map<pair<int, char>, int> transitions;
};

// Function to minimize DFA
void minimizeDFA(DFA &dfa)
{
  // Initialize equivalence classes
  vector<set<int>> equivalenceClasses(2);

  // Partition states into two groups: final states and non-final states
  for (int i = 0; i < dfa.numStates; ++i)
  {
    if (dfa.finalStates.find(i) != dfa.finalStates.end())
    {
      equivalenceClasses[0].insert(i); // Group 0: Final states
    }
    else
    {
      equivalenceClasses[1].insert(i); // Group 1: Non-final states
    }
  }

  bool changed = true;
  while (changed)
  {
    changed = false;

    // Iterate through each partition
    for (int group = 0; group < equivalenceClasses.size(); ++group)
    {
      set<int> newPartition;

      // Check if states in the current partition can be distinguished
      for (int state1 : equivalenceClasses[group])
      {
        for (int state2 : equivalenceClasses[group])
        {
          bool equivalent = true;

          // Check if states have different transitions for any input symbol
          for (char symbol : dfa.alphabet)
          {
            int nextState1 = dfa.transitions[{state1, symbol}];
            int nextState2 = dfa.transitions[{state2, symbol}];

            // States are distinguishable if transitions lead to different partitions
            if (equivalenceClasses[0].count(nextState1) != equivalenceClasses[0].count(nextState2))
            {
              equivalent = false;
              break;
            }
          }

          if (!equivalent)
          {
            // States are distinguishable, move state to a new partition
            newPartition.insert(state1);
            changed = true;
            break;
          }
        }
        if (changed)
        {
          break;
        }
      }

      // Update partition if changes were made
      if (changed)
      {
        equivalenceClasses.push_back(newPartition);
        equivalenceClasses[group].erase(newPartition.begin(), newPartition.end());
        break;
      }
    }
  }

  // Output minimized DFA
  cout << "Minimized DFA:" << endl;
  cout << "Number of States: " << equivalenceClasses.size() << endl;
  cout << "Final States: ";
  for (int state : equivalenceClasses[0])
  {
    cout << state << " ";
  }
  cout << endl;
  cout << "Transitions:" << endl;
  for (int group = 0; group < equivalenceClasses.size(); ++group)
  {
    for (char symbol : dfa.alphabet)
    {
      int nextState = dfa.transitions[{*(equivalenceClasses[group].begin()), symbol}];
      int nextGroup = 0;
      for (int i = 0; i < equivalenceClasses.size(); ++i)
      {
        if (equivalenceClasses[i].count(nextState) > 0)
        {
          nextGroup = i;
          break;
        }
      }
      cout << group << " -> " << nextGroup << " (symbol: " << symbol << ")" << endl;
    }
  }
}

int main()
{
  // DFA input
  DFA dfa;
  cout << "Enter the number of states: ";
  cin >> dfa.numStates;

  // Input alphabet
  cout << "Enter the alphabet (separated by spaces): ";
  char symbol;
  while (cin >> symbol)
  {
    if (symbol == '#')
      break; // Terminate input with #
    dfa.alphabet.insert(symbol);
  }

  // Define transitions
  cout << "Enter transitions in the format: state1 symbol state2" << endl;
  cout << "Use -1 to terminate." << endl;
  int state1, state2;
  while (cin >> state1 && state1 != -1)
  {
    cin >> symbol >> state2;
    dfa.transitions[{state1, symbol}] = state2;
  }

  // Final states
  cout << "Enter final states (separated by spaces): ";
  while (cin >> state1)
  {
    if (state1 == -1)
      break; // Terminate input with -1
    dfa.finalStates.insert(state1);
  }

  // Minimize DFA
  minimizeDFA(dfa);

  return 0;
}