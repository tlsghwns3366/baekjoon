#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.length() % 3 == 1)
        s = "00" + s;
    else if (s.length() % 3 == 2)
        s = "0" + s;
    string ans = "";
    for (int i = s.length() - 1; i >= 0; i -= 3)
    {
        if (s[i - 2] == '0' && s[i - 1] == '0' && s[i] == '0')
            ans += "0";
        else if (s[i - 2] == '0' && s[i - 1] == '0' && s[i] == '1')
            ans += "1";
        else if (s[i - 2] == '0' && s[i - 1] == '1' && s[i] == '0')
            ans += "2";
        else if (s[i - 2] == '0' && s[i - 1] == '1' && s[i] == '1')
            ans += "3";
        else if (s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0')
            ans += "4";
        else if (s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '1')
            ans += "5";
        else if (s[i - 2] == '1' && s[i - 1] == '1' && s[i] == '0')
            ans += "6";
        else if (s[i - 2] == '1' && s[i - 1] == '1' && s[i] == '1')
            ans += "7";
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}