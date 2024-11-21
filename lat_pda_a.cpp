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

                if ((input == ')' && pdaStack.top() == '(') ||
                    (input == ']' && pdaStack.top() == '[') ||
                    (input == '}' && pdaStack.top() == '{')) {
                    pdaStack.pop();
                    return Q0;
                } else {
                    return REJECT;
                }
            }
            return REJECT;

        default:
            return REJECT;
    }
}

bool stringDiterima(const string& input) {
    State currentState = Q0;
    stack<char> pdaStack;

    for (char c : input) {
        if (c != '{'&& c != '[' && c != '(' && c != ')'&& c != ']' && c != '}')
        {
            cout <<  "Input invalid: hanya simbol '(, {, [, ], }, )' yang diperbolehkan." << endl;
            return false;
        }
        currentState = nextState(currentState, c, pdaStack);
        if (currentState == REJECT)
            return false;
    }

    return currentState == Q0 && pdaStack.empty();
}

int main() {
    string input;
    char choice;

    do {
        cout << "Masukkan string yang terdiri dari (, [, {, ], ), }: ";
        cin >> input;

        if (stringDiterima(input)) {
            cout << "String dapat diterima oleh PDA." << endl;
        } else {
            cout << "String ditolak oleh PDA." << endl;
        }

        cout << "Apakah Anda ingin mencoba lagi? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program selesai." << endl;
    return 0;
}
