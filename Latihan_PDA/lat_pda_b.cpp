#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum state {
    Q0, REJECT
};

State nextState(State currentState, char input, stack<char>& pdaStack) {
    switch (currentState) {
    # code soon hehehe....
    }
}
bool stringDiterima(const string& input)
{
    State currentState == 0;
    stack<char> pdaStack;

    for (char c: input)
    {
        if (c != 'a' && c != 'b')
        {
            cout << "Input invalid: hanya simbol 'a' dan 'b' yang diperbolehkan" << endl;
        }
        currentState = nextState(currentState, c, pdaStack);

        if (currentState == REJECT)
        {
            return false;
        }
    }
    return currentState == 0 && pdaStack.empty();
}

int main() {
    string input;
    char choice;

    do {
        cout << "Masukan string yang terdiri dari simbol 'a' dan 'b': " << endl;
        cin  >> input

        if (stringDiterima(input))
        {
            cout << "String " << input << " dapat diterima oleh PDA" << endl;
        }
        else {
            cout << "String " << input << " ditolak oleh PDA" << endl;
        }

        cout << "Apakah Anda ingin mencoba lagi? (y/n): ";
        cin  >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout << "Program selesai ......" << endl;
    return 0;
}
