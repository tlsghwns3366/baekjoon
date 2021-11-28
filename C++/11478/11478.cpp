#include <iostream>
#include <map>
using namespace std;
int main()
{
    string s;
    map<string, int> m;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        string temp = "";
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];
            if (m[temp] == 0)
            {
                m[temp]++;
                ans++;
            }
        }
    }
    cout << ans;
}