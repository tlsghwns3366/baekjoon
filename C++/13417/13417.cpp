#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char s[n];
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        ans = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] <= ans[0])
                ans = s[i] + ans;
            else
                ans += s[i];
        }
        cout << ans << "\n";
    }
}