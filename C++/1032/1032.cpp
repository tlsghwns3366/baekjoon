#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string sn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sn[i];
    }
    string ans = "";
    for (int i = 0; i < sn[0].length(); i++)
    {
        bool temp = true;
        char checkstring = sn[0][i];
        for (int j = 1; j < n; j++)
        {
            if (checkstring != sn[j][i])
                temp = false;
        }
        if (temp)
            ans += checkstring;
        else
            ans += "?";
    }
    cout << ans;
}