#include <iostream>
using namespace std;
bool f(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}
int main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "end")
            break;
        int ans = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                ans = true;

            if (i < s.length() - 2)
            {
                if ((f(s[i]) && f(s[i + 1]) && f(s[i + 2])) || (!f(s[i]) && !f(s[i + 1]) && !f(s[i + 2])))
                {
                    ans = false;
                    break;
                }
            }

            if (s[i] == s[i + 1])
            {
                if (s[i] == 'e' || s[i] == 'o')
                    continue;
                else
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
            cout << "<" << s << "> is acceptable.\n";
        else
            cout << "<" << s << "> is not acceptable.\n";
    }
}