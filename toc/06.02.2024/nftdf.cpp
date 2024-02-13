#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// Function to convert NFA to DFA
set<int> eClosure(const vector<vector<set<int>>> &nfa, const set<int> &states)
{
  set<int> closure = states;
  vector<int> stack(states.begin(), states.end());

  while (!stack.empty())
  {
    int current = stack.back();
    stack.pop_back();

    for (int next : nfa[current][0])
    {
      if (closure.find(next) == closure.end())
      {
        closure.insert(next);
        stack.push_back(next);
      }
    }
  }

  return closure;
}

set<int> move(const vector<vector<set<int>>> &nfa, const set<int> &states, int symbol)
{
  set<int> result;

  for (int state : states)
  {
    for (int next : nfa[state][symbol])
    {
      result.insert(next);
    }
  }

  return result;
}

int main()
{
  int numStates, numSymbols;

  // Input the number of states and symbols
  cout << "Enter the number of states: ";
  cin >> numStates;
  cout << "Enter the number of input symbols: ";
  cin >> numSymbols;

  // Input the NFA transition table
  vector<vector<set<int>>> nfa(numStates, vector<set<int>>(numSymbols + 1));

  cout << "Enter the NFA transition table (use -1 for no transition):\n";
  for (int i = 0; i < numStates; ++i)
  {
    for (int j = 0; j <= numSymbols; ++j)
    {
      int transition;
      cout << "Q" << i << " on symbol " << (j == numSymbols ? "ε" : to_string(j)) << ": ";
      cin >> transition;

      if (transition != -1)
      {
        nfa[i][j].insert(transition);
      }
    }
  }

  // DFA data structures
  vector<set<int>> dfaStates;
  vector<vector<int>> dfaTransition;
  map<set<int>, int> stateIndexMap;

  // Initial state of DFA
  set<int> initialState = eClosure(nfa, {0});
  dfaStates.push_back(initialState);
  stateIndexMap[initialState] = 0;

  vector<int> initialTransition(numSymbols + 1, -1);
  dfaTransition.push_back(initialTransition);

  // Process each DFA state
  for (int i = 0; i < dfaStates.size(); ++i)
  {
    for (int j = 0; j < numSymbols; ++j)
    {
      set<int> nextDFAState = eClosure(nfa, move(nfa, dfaStates[i], j));
      if (stateIndexMap.find(nextDFAState) == stateIndexMap.end())
      {
        stateIndexMap[nextDFAState] = dfaStates.size();
        dfaStates.push_back(nextDFAState);
        dfaTransition.push_back(vector<int>(numSymbols + 1, -1));
      }
      dfaTransition[i][j] = stateIndexMap[nextDFAState];
    }
  }

  // Display the DFA transition table
  cout << "\nDFA Transition Table:\n";
  for (int i = 0; i < dfaStates.size(); ++i)
  {
    cout << "State Q" << i << ": ";
    for (int j = 0; j <= numSymbols; ++j)
    {
      cout << (j == numSymbols ? "ε" : to_string(j)) << " -> Q" << dfaTransition[i][j] << " | ";
    }
    cout << "\n";
  }

  return 0;
}
