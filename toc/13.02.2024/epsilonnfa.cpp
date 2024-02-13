#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

class EpsilonNFA
{
  vector<set<int>> transitions;
  set<int> epsilonClosure(int state);

public:
  EpsilonNFA(int numStates);
  void addTransition(int from, int to, char symbol);
  void convertToNFA();
  void printTransitions();
};

EpsilonNFA::EpsilonNFA(int numStates)
{
  transitions.resize(numStates);
}

void EpsilonNFA::addTransition(int from, int to, char symbol)
{
  transitions[from].insert(to);
}

set<int> EpsilonNFA::epsilonClosure(int state)
{
  set<int> closure;
  vector<bool> visited(transitions.size(), false);
  vector<int> stack;

  stack.push_back(state);

  while (!stack.empty())
  {
    int current = stack.back();
    stack.pop_back();

    if (!visited[current])
    {
      visited[current] = true;
      closure.insert(current);

      for (int nextState : transitions[current])
      {
        if (nextState != current)
          stack.push_back(nextState);
      }
    }
  }

  return closure;
}

void EpsilonNFA::convertToNFA()
{
  vector<set<int>> newTransitions(transitions.size());

  for (int i = 0; i < transitions.size(); ++i)
  {
    set<int> reachableStates;

    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
      int current = q.front();
      q.pop();

      set<int> eclosure = epsilonClosure(current);

      for (int state : eclosure)
      {
        reachableStates.insert(state);

        for (int nextState : transitions[state])
        {
          if (nextState != state && eclosure.find(nextState) == eclosure.end())
          {
            q.push(nextState);
          }
        }
      }
    }

    for (int state : reachableStates)
    {
      newTransitions[i].insert(state);
    }
  }

  transitions = newTransitions;
}

void EpsilonNFA::printTransitions()
{
  for (int i = 0; i < transitions.size(); ++i)
  {
    cout << "State " << i << " transitions: ";
    for (int nextState : transitions[i])
    {
      cout << nextState << " ";
    }
    cout << endl;
  }
}

int main()
{
  int numStates;
  cout << "Enter the number of states: ";
  cin >> numStates;

  EpsilonNFA nfa(numStates);

  cout << "Enter transitions (from to symbol), enter -1 to end input:" << endl;
  int from, to;
  char symbol;
  while (true)
  {
    cin >> from;
    if (from == -1)
      break;
    cin >> to >> symbol;
    nfa.addTransition(from, to, symbol);
  }

  cout << "Epsilon-NFA transitions before conversion:" << endl;
  nfa.printTransitions();

  nfa.convertToNFA();

  cout << "NFA transitions after conversion:" << endl;
  nfa.printTransitions();

  return 0;
}