//ЛР 8.1 рек

// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів трійка сусідніх букв "OGO" або "AGA".
// 2. Замінити кожну трійку сусідніх букв "OGO" або "AGA" парою зірочок "**".

#include <iostream>
using namespace std;

bool Exist(const char* str, int i)
{
    if (str[i] != '\0')
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A'))
            return true;
        else
            return Exist(str, i + 1);
    else
        return false;
}

char* Change(char* result, const char* str, char* t, int i)
{
    if (str[i] != '\0')
    {
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A'))
        {
            *t++ = '*';
            *t++ = '*';
            return Change(result, str, t, i + 3);
        }
        else
        {
            *t++ = str[i];
            return Change(result, str, t, i + 1);
        }
    }
    else
    {
        *t = '\0';
        return result;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    if (Exist(str, 0))
        cout << "String contains OGO or AGA" << endl;
    else
        cout << "String does not contain OGO or AGA" << endl;
    char* dest = new char[strlen(str) + 1];
    char* result = Change(dest, str, dest, 0);
    cout << "Modified string (param) : " << dest << endl;
    cout << "Modified string (result): " << result << endl;
    delete[] dest;

    return 0;
}