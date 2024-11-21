#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum State {
    Q0,
    REJECT
};

State nextState(State currentState, char input, stack<char>& pdaStack) {
    switch (currentState) {
        case Q0:
            if (input == '(' || input == '[' || input == '{') {
                pdaStack.push(input);
                return Q0;
            } else if (input == ')' || input == ']' || input == '}') {
                if (pdaStack.empty())
                    return REJECT;

                if ((input == ')' && pdaStack.top == '(') ||
                    (input == ']' && pdaStack.top == '[') ||
                    (input == '}' && pdaStack.top == '{')) {
                    pdaStack.pop();
                    return Q0;
                }
                return REJECT;
            }
            return REJECT;

        default:
            return REJECT;
    }
}

bool stringDiterima(const string& input) {
    State currentState = Q0;
    stack<char> pdaStack;

    for (char ch : input) {
        currentState = nextState(currentState, ch, pdaStack);
        if (currentState == REJECT) return false;
    }
    return currentState == Q0 && pdaStack.empty();
}

int main() {
    string input;

    do {
        cout << "Masukkan string yang terdiri dari "(, [, {}, ], )" ";
        cin >> input;

        if (stringDiterima(input)) {
            cout << "String dapat diterima oleh PDA." << endl;
        } else {
            cout << "String ditolak oleh PDA." << endl;
        }

        cout << "Apakah anda ingin menginputkan string kembali? (y/n): ";
        cin >> input;

    } while (input == "y" || input == "Y");

    cout << "Program selesai." << endl;
    return 0;
}
