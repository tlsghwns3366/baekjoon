#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    string ns;
    cin >> s;
    ns = "IOI";
    for (int i = 1; i < n; i++)
    {
        ns += "OI";
    }
    int *bb = new int[ns.length() + 1];
    fill(bb, bb + ns.length() + 1, 0);
    int j = 0;
    for (int i = 1; i < ns.length(); i++)
    {
        while (ns[j] != ns[i] && j > 0)
        {
            j = bb[j - 1];
        }
        if (ns[j] == ns[i])
            bb[i] = ++j;
    }

    int ans = 0;
    int sidx = 0;
    j = 0;
    for (int i = 0; i < m; i++)
    {
        while (s[i] != ns[j] && j != 0)
            j = bb[j - 1];
        if (s[i] == ns[j])
        {
            if (j == ns.length() - 1)
            {
                ans++;
                j = bb[j];
            }
            else
                j++;
        }
    }
    cout << ans;
}