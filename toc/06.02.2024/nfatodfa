// nfa to dfa conversion

#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct NFAState
{
  set<int> transitions[2];
};
struct DFAState
{
  set<int> states;
  map<int, set<int>> transition;
};

void convertNFAtoDFA(NFAState nfa[], int nfa_states, int nfa_fs[], int nfa_fsc, DFAState dfa[], int &dfa_states)
{
  queue<set<int>> unmarked_states;
  set<set<int>> marked_states;
  set<int> start_state;
  start_state.insert(0);
  unmarked_states.push(start_state);
  dfa[0].states = start_state;
  marked_states.insert(start_state);

  while (!unmarked_states.empty())
  {
    set<int> current_dfa_state = unmarked_states.front();
    unmarked_states.pop();
    for (int i = 0; i <= 1; i++)
    {
      set<int> next_state;
      for (int state : current_dfa_state)
      {
        for (int next : nfa[state].transitions[i])
        {
          next_state.insert(next);
        }
      }
      if (!next_state.empty())
      {
        if (marked_states.find(next_state) == marked_states.end())
        {
          unmarked_states.push(next_state);
          marked_states.insert(next_state);
          dfa_states++;
          dfa[dfa_states].states = next_state;
        }
        dfa[distance(dfa, find_if(dfa, dfa + dfa_states + 1, [&current_dfa_state](const DFAState &s)
                                  { return s.states == current_dfa_state; }))]
            .transition[i] = next_state;
      }
    }
  }
}

int main()
{
  int nfa_states;
  cout << "Enter the number of states in the NFA: ";
  cin >> nfa_states;
  NFAState nfa[nfa_states];
  for (int i = 0; i < nfa_states; ++i)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << "Enter no. of transitions of state " << i << " for input " << j << " : ";
      int nt;
      cin >> nt;
      cout << "Enter transitions: ";
      while (nt > 0)
      {
        int transition;
        cin >> transition;
        nfa[i].transitions[j].insert(transition);
        nt--;
      }
    }
  }
  int nfa_fsc;
  cout << "Enter the number of final states: ";
  cin >> nfa_fsc;
  int nfa_fs[nfa_fsc];
  cout << "Enter the final states: ";
  for (int i = 0; i < nfa_fsc; ++i)
  {
    cin >> nfa_fs[i];
  }
  int dfa_states = 0;
  DFAState dfa[100];
  convertNFAtoDFA(nfa, nfa_states, nfa_fs, nfa_fsc, dfa, dfa_states);
  cout << "State\t0\t1\n";
  for (int i = 0; i <= dfa_states; ++i)
  {
    cout << "{";
    for (int state : dfa[i].states)
    {
      cout << state << ",";
    }
    cout << "}\t";
    for (int sym = 0; sym <= 1; ++sym)
    {
      auto it = dfa[i].transition.find(sym);
      if (it != dfa[i].transition.end())
      {
        cout << "{";
        for (int state : it->second)
        {
          cout << state << ",";
        }
        cout << "}\t";
      }
      else
      {
        cout << "-\t";
      }
    }
    cout << endl;
  }
  return 0;
}
