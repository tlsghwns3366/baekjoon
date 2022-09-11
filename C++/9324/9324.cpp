#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        string s;
        cin >> s;
        int n[26];
        fill(n, n + 26, 0);
        bool ans = false;
        for (int i = 0; i < s.length(); i++)
        {
            n[s[i] - 'A']++;
            if (n[s[i] - 'A'] == 3)
            {
                n[s[i] - 'A'] = 0;
                if (s[i + 1] == s[i])
                    i++;
                else
                {
                    ans = true;
                    break;
                }
            }
        }
        if (ans)
            cout << "FAKE\n";
        else
            cout << "OK\n";
    }
}