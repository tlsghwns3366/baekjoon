#include <iostream>
using namespace std;
int main()
{
    string ans = "";
    while (true)
    {
        string s;
        cin >> s;
        if (ans == "")
        {
            ans = s;
            continue;
        }
        else
        {
            cout << ans;
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == ',' || s[i] == ';')
                    continue;
                if (s[i] == ']')
                {
                    cout << "[]";
                    i--;
                    continue;
                }
                else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                {
                    cout << " ";
                    for (int j = 0; j <= i; j++)
                    {
                        cout << s[j];
                    }
                    break;
                }
                cout << s[i];
            }
            cout << ";" << endl;
        }

        if (s[s.length() - 1] == ';')
            break;
    }
}