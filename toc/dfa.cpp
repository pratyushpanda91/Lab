#include <iostream>
#include <string>

using namespace std;

class DFA {
private:
    enum State { INITIAL, STATE_1, STATE_2, ACCEPT, REJECT };
    State currentState;

public:
    DFA() {
        currentState = INITIAL;
    }

    void processInput(const string& input) {
        for (char c : input) {
            processCharacter(c);
        }
    }

    void processCharacter(char c) {
        switch (currentState) {
            case INITIAL:
                if (c == '1') {
                    currentState = STATE_1;
                } else {
                    currentState = REJECT;
                }
                break;

            case STATE_1:
                if (c == '0') {
                    currentState = ACCEPT;
                } else if (c == '1') {
                    // Stay in STATE_1 for consecutive '1's
                } else {
                    currentState = REJECT;
                }
                break;

            case STATE_2:
            if (c == '1') {
                    currentState = STATE_1;
            }else{currentState = ACCEPT;} // Any character in STATE_2 leads to rejection
                break;

            case ACCEPT:
            case REJECT:
                // Stay in ACCEPT or REJECT state
                break;
        }
    }

    bool isAccepted() const {
        return currentState == ACCEPT;
    }
};

int main() {
    DFA dfa;

    string input;
    cout << "Enter a string: ";
    cin >> input;

    dfa.processInput(input);

    if (dfa.isAccepted()) {
        cout << "Accepted\n";
    } else {
        cout << "Rejected\n";
    }

    return 0;
}