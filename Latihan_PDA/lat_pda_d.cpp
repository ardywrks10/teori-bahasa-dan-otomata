#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum State {
    S0, S1,
    REJECT
};

State nextState(State currentState, char input, stack<char>& pdaStack, int& counter, int& counter_2) {
    switch (currentState) {
        case S0:
            if (input == 'a') {
                pdaStack.push('a');
                counter++;
                return S0;
            }

        case S1:
            if (input == 'a') {
                pdaStack.push('a');
                counter++;
                return S1;
            } else if (input == 'b' && !pdaStack.empty()
                       && pdaStack.top() == 'a') {
                pdaStack.pop();
                counter_2++;
                return S1;
            }
            break;

        default:
            return REJECT;
    }
    return REJECT;
}

bool stringDiterima(const string& input, int& counter, int& counter_2) {
    State currentState = S0;
    stack<char> pdaStack;

    for (char c : input) {
        if (c != 'a' && c != 'b') {
            cout << "Input invalid: simbol yang diterima hanya 'a' dan 'b'" << endl;
            return false;
        }

        currentState = nextState(currentState, c, pdaStack, counter, counter_2);
        if (currentState == REJECT) {
            return false;
        }
    }

    // Final condition based on counters
    return (counter_2 <= counter) && (2 * counter_2 >= counter);
}

int main() {
    string input;

    do {
        int counter = 0;   // Counter for 'a' (push operations)
        int counter_2 = 0; // Counter for 'b' (pop operations)

        cout << "Masukkan string (kombinasi 'a' dan 'b'): ";
        cin >> input;

        if (stringDiterima(input, counter, counter_2)) {
            cout << "String diterima oleh PDA." << endl;
        } else {
            cout << "String tidak diterima oleh PDA." << endl;
        }

        cout << "Apakah Anda ingin mencoba lagi? (y/n): ";
        cin >> input;

    } while (input == "y" || input == "Y");

    cout << "Program selesai." << endl;
    return 0;
}
