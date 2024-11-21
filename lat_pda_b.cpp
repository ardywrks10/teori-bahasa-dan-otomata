#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum State {
    Q0,      // State awal
    Q1,      // State setelah membaca 'b'
    Q2,      // State sebelum menerima string
    REJECT   // State akhir yang menolak string
};

State nextState(State currentState, char input, stack<char>& pdaStack) {
    switch (currentState) {
        case Q0:
            if (input == 'a') {
                pdaStack.push('a');
                pdaStack.push('a');
                return Q1;
            } else {
                return REJECT;
            }

        case Q1:
            if (input == 'a') {
                pdaStack.push('a');
                pdaStack.push('a');
                return Q1;
            }
            if (input == 'b') {
                if (pdaStack.size() >= 3 && pdaStack.top() == 'a') {
                    pdaStack.pop();
                    pdaStack.pop();
                    pdaStack.pop();
                    return Q1;
                } else {
                    return REJECT;  // Stack tidak cukup untuk memproses 'b'
                }
            }
            // Jika input tidak valid, tetap di state Q1
            return REJECT;

        case Q2:  // State akhir sebelum menerima
            if (input == '\0' && pdaStack.size() == 1 && pdaStack.top() == 'a') {
                pdaStack.pop();  // Epsilon transisi, pop simbol terakhir
                return Q2;
            }
            return REJECT;

        default:
            return REJECT;
    }
}

bool isAcceptedByPDA(const string& input) {
    State currentState = Q0;
    stack<char> pdaStack;

    for (char ch : input) {
        currentState = nextState(currentState, ch, pdaStack);
        if (currentState == REJECT) {
            return false;
        }
    }

    currentState = nextState(Q2, '\0', pdaStack);
    return currentState == Q2;
}

int main() {
    string input;

    do {
        cout << "Masukkan string (kombinasi 'a' dan 'b'): ";
        cin >> input;

        if (isAcceptedByPDA(input)) {
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

