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
            if (s[i] == '0' && s[i + 1] == '1')
            {
                i++;
            }
            else if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '0')
            {
                int j, temp;
                for (j = i + 3; j < s.length(); j++)
                {
                    if (s[j] != '0')
                        break;
                }
                if (j == s.length())
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