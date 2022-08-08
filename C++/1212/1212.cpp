#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ans = "";
    for (long long int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            ans += "000";
        else if (s[i] == '1')
            ans += "001";
        else if (s[i] == '2')
            ans += "010";
        else if (s[i] == '3')
            ans += "011";
        else if (s[i] == '4')
            ans += "100";
        else if (s[i] == '5')
            ans += "101";
        else if (s[i] == '6')
            ans += "110";
        else if (s[i] == '7')
            ans += "111";
    }
    if (ans == "000")
        cout << "0";
    else
    {
        bool temp = false;
        for (long long int i = 0; i < ans.length(); i++)
        {
            if (ans[i] == '1')
                temp = true;
            if (temp)
                cout << ans[i];
        }
    }
}