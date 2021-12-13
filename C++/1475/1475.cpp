#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n[10];
    fill(n, n + 10, 0);
    for (int i = 0; i < s.length(); i++)
    {
        n[s[i] - '0']++;
    }
    int ans;
    if ((n[6] + n[9]) % 2 == 0)
        ans = (n[6] + n[9]) / 2;
    else
        ans = (n[6] + n[9]) / 2 + 1;

    for (int i = 0; i < 10; i++)
    {
        if (i != 6 && i != 9 && ans < n[i])
            ans = n[i];
    }
    cout << ans;
}