#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string L = "";
    string R = "";
    bool ch = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            ch = false;
            continue;
        }
        if (ch)
            L += s[i];
        else
            R += s[i];
    }
    for (int q = 0; q < n; q++)
    {
        string temp;
        cin >> temp;
        bool ans = false;
        if (s.length() - 1 > temp.length())
        {
            cout << "NE\n";
        }
        else
        {
            for (int i = 0; i < L.length(); i++)
            {
                if (L[i] != temp[i])
                {
                    ans = true;
                    break;
                }
            }
            if (!ans)
            {
                for (int i = 0; i < R.length(); i++)
                {
                    if (R[i] != temp[temp.length() - R.length() + i])
                    {
                        ans = true;
                        break;
                    }
                }
            }
            if (ans)
                cout << "NE\n";
            else
                cout << "DA\n";
        }
    }
}