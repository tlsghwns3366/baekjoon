#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<char, int> m;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        bool b = false;
        bool ans = false;
        for (int j = 0; j < s.length(); j++)
        {
            char temp = s[j];
            if (temp >= 'A' && temp <= 'Z')
                temp += 32;
            if (!b && m[temp] == 0 && temp != ' ')
            {
                cout << s.substr(0, j) << "[" << s[j] << "]" << s.substr(j + 1) << "\n";
                m[temp]++;
                ans = true;
                break;
            }
            if (temp == ' ')
                b = false;
            else
                b = true;
        }
        if (!ans)
        {
            for (int j = 0; j < s.length(); j++)
            {
                char temp = s[j];
                if (temp >= 'A' && temp <= 'Z')
                    temp += 32;
                if (m[temp] == 0 && temp != ' ')
                {
                    cout << s.substr(0, j) << "[" << s[j] << "]" << s.substr(j + 1) << "\n";
                    m[temp]++;
                    ans = true;
                    break;
                }
            }
        }
        if (!ans)
            cout << s << "\n";
    }
}