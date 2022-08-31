#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int k = 1; k <= s[0].length(); k++)
    {
        bool temp = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i].substr(s[i].length() - k) == s[j].substr(s[j].length() - k))
                {
                    temp = true;
                    break;
                }
            }
            if (temp)
                break;
        }
        if (!temp)
        {
            cout << k;
            break;
        }
    }
}