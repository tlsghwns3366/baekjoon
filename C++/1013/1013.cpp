#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        string s;
        cin >> s;
        bool ans = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                if (s[i + 1] == '1')
                    i++;
                else
                {
                    ans = false;
                    break;
                }
            }
            else if (s[i] == '1')
            {
                bool fone = false;
                int j, temp;
                for (j = i + 1; j < s.length(); j++)
                {
                    if (s[j] != '0')
                        break;
                }
                if (j - i <= 2 || j == s.length())
                {
                    ans = false;
                    break;
                }
                for (temp = j; temp < s.length(); temp++)
                {
                    if (s[temp] != '1')
                        break;
                }
                if (temp == s.length())
                    break;
                if (temp - j == 1)
                    i = temp - 1;
                else
                {
                    if (s[temp + 1] == '0')
                        i = temp - 2;
                    else
                        i = temp - 1;
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}