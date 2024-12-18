#include <iostream>
#include <string>
#include <stack>

using namespace std;

// contoh soal latihan
// #a(w)  = 2#b(w)
// jumlah simbol a dan simbol dari sebuah string adalah sama

enum State {
    S0, REJECT
};

State nextState(State currentState, char input, stack<char>& pdaStack) {
    switch (currentState) {
        case S0:
            if (input == 'a') {
                if (pdaStack.empty() || pdaStack.top() == 'a') {
                    pdaStack.push('a');
                } else if (pdaStack.top() == 'b') {
                    pdaStack.pop();
                }
            } else if (input == 'b') {
                if (pdaStack.empty() || pdaStack.top() == 'b') {
                    pdaStack.push('b');
                    pdaStack.push('b');
                } else if (pdaStack.size() >= 2) {
                    pdaStack.pop();
                    pdaStack.pop();
                } else if (pdaStack.top() == 'a') {
                    pdaStack.pop();
                }
            } else {
                return REJECT;
            }
            return S0;
        default:
            return REJECT;
    }
    return REJECT;
}

bool stringDiterima(const string& input) {
    State currentState = S0;
    stack<char> pdaStack;

    for (char c : input) {
        if (c != 'a' && c != 'b') {
            cout << "Input invalid: hanya simbol 'a' dan 'b' yang diperbolehkan" << endl;
            return false;
        }
        currentState = nextState(currentState, c, pdaStack);

        if (currentState == REJECT) {
            return false;
        }
    }
    return currentState == S0 && pdaStack.empty();
}

int main() {
    string input;
    char choice;

    do {
        cout << "Masukkan string yang terdiri dari simbol 'a' dan 'b': ";
        cin >> input;

        if (stringDiterima(input)) {
            cout << "String " << input << " diterima oleh PDA" << endl;
        } else {
            cout << "String " << input << " ditolak oleh PDA" << endl;
        }

        cout << "Apakah Anda ingin mencoba lagi? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout << "Program selesai ......" << endl;
    return 0;
}
