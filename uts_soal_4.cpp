#include <iostream>
#include <string>

using namespace std;

enum State
{
    S0, S1, S2, S3, S4, S5, S6, S7,
    S8, S9, S10, S11, S12, S13, S14,
    S15, S16, S17, COUNT_0, COUNT_1, START
};

State nextState(State currentState, char input)
{
    if (currentState == S0)
    {
        if (input == '0')
            return S1;
        else
            return S6;
    }
    else if (currentState == S1)
    {
        if (input == '0')
            return S2;
        else
            return S7;
    }
    else if (currentState == S2)
    {
        if (input == '0')
            return S3;
        else
            return S8;
    }
    else if (currentState == S3)
    {
        if (input == '0')
            return S4;
        else
            return S9;
    }
    else if (currentState == S4)
    {
        if (input == '0')
            return S5;
        else
            return S10;
    }
    else if (currentState == S5)
    {
        if (input == '0')
            return S1;
        else
            return S11;
    }
    else if (currentState == S6)
    {
        if (input == '0')
            return S7;
        else
            return S12;
    }
    else if (currentState == S7)
    {
        if (input == '0')
            return S8;
        else
            return S13;
    }
    else if (currentState == S8)
    {
        if (input == '0')
            return S9;
        else
            return S14;
    }
    else if (currentState == S9)
    {
        if (input == '0')
            return S10;
        else
            return S15;
    }
    else if (currentState == S10)
    {
        if (input == '0')
            return S11;
        else
            return S16;
    }
    else if (currentState == S11)
    {
        if (input == '0')
            return S7;
        else
            return S17;
    }
    else if (currentState == S12)
    {
        if (input == '0')
            return S13;
        else
            return S6;
    }
    else if (currentState == S13)
    {
        if (input == '0')
            return S14;
        else
            return S7;
    }
    else if (currentState == S14)
    {
        if (input == '0')
            return S15;
        else
            return S8;
    }
    else if (currentState == S15)
    {
        if (input == '0')
            return S16;
        else
            return S9;
    }
    else if (currentState == S16)
    {
        if (input == '0')
            return S17;
        else
            return S10;
    }
    else if (currentState == S17)
    {
        if (input == '0')
            return S13;
        else
            return S11;
    }
    return S17;
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
        if (c != '0' && c != '1')
        {
            cout << "Input invalid: hanya simbol '0' dan '1' yang diperbolehkan." << endl;
            return false;
        }

        currentState = nextState(currentState, c);
    }

    return currentState == S17 || currentState == S5;
}

int main()
{
    string input;
    char pilihan;

    do {
        cout << "Masukkan string yang terdiri dari simbol '0' dan '1': ";
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
