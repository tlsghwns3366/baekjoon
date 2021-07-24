#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        string s;
        cin >> s;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == '(' && s[i] == ')')
            {
                s.erase(i - 1, 2);
                i = 0;
            }
        }
        if (s.length() == 0)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}