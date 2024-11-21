#include <iostream>
#include <string>

using namespace std;

enum State
{
    S0, S1, S2
};

State nextState(State currentState, char input)
{
    if (currentState == S0)
    {
        if (input == 'b')
            return S1;
        else
            return S2;
    }
    else if (currentState == S1)
    {
        if (input == 'b')
            return S1;
        else
            return S2;
    }
    else if (currentState == S2)
    {
        if (input == 'b')
            return S1;
    }
    return S1;
}

bool string_Diterima(const string &input)
{
    if (input.empty() || input == "null")
    {
        return true;
    }

    State currentState = S0;

    for (char c : input)
    {
        if (c != 'a' && c != 'b')
        {
            cout << "Input invalid: hanya simbol '0' dan '1' yang diperbolehkan." << endl;
            return false;
        }

        currentState = nextState(currentState, c);
    }

    return currentState == S1;
}

int main()
{
    string input;
    char pilihan;

    do {
        cout << "Masukkan string yang terdiri dari simbol 'a' dan 'b': ";
        getline(cin, input);

        if (string_Diterima(input))
        {
            cout << "String " << input << " dapat diterima." << endl;
        } else {
            cout << "String " << input << " ditolak." << endl;
        }

        cout << "Apakah anda ingin menginputkan string kembali? (y/n): ";
        cin >> pilihan;
        cin.ignore();

    } while (pilihan == 'y' || pilihan == 'Y');
    cout << "Program selesai....";

    return 0;
}

