#include <iostream>
using namespace std;
int main()
{
    int c = 0;
    while (true)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
            break;
        int ans = 0;
        c++;
        while (true)
        {
            if (s == "")
                break;
            if (s.find("{}") != string::npos)
                s.erase(s.find("{}"), 2);
            else if (s.find("{{") != string::npos)
            {
                ans += 1;
                s.erase(s.find("{{"), 2);
            }
            else if (s.find("}}") != string::npos)
            {
                ans += 1;
                s.erase(s.find("}}"), 2);
            }
            else if (s.find("}{") != string::npos)
            {
                ans += 2;
                s.erase(s.find("}{"), 2);
            }
        }
        cout << c << ". " << ans << "\n";
    }
}