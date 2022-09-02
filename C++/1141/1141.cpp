#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool ans[n];
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ans[i] = false;
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[j].substr(0, s[i].length()) == s[i])
            {
                ans[i] = true;
                break;
            }
        }
    }
    int sum = n;
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
            sum--;
    }
    cout << sum;
}