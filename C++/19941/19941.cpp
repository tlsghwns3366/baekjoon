#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    bool sb[s.length()];
    fill(sb, sb + s.length(), false);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'P')
        {
            for (int j = i - k; j <= i + k; j++)
            {
                if (j < 0 || i == j || j > s.length() || sb[j])
                    continue;
                else if (s[j] == 'H')
                {
                    ans++;
                    sb[j] = true;
                    break;
                }
            }
        }
    }
    cout << ans;
}