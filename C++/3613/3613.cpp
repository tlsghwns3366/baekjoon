#include <iostream>
using namespace std;
int main()
{
    string s;
    string ans;
    ans = "";
    cin >> s;
    bool cb = false;
    bool jab = false;
    bool err = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (i == 0 || cb)
            {
                err = true;
                break;
            }
            ans += '_';
            ans += s[i] + 32;
            jab = true;
        }
        else if (s[i] == '_')
        {
            if (i == 0 || jab || i == s.length() - 1 || s[i + 1] == '_' || s[i + 1] >= 'A' && s[i + 1] <= 'Z')
            {
                err = true;
                break;
            }
            ans += s[i + 1] - 32;
            i++;
            cb = true;
        }
        else
            ans += s[i];
    }
    if (err)
        cout << "Error!";
    else
        cout << ans;
}