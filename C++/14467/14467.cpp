#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int so[11];
    fill(so, so + 11, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (so[a] == -1)
            so[a] = b;
        else
        {
            if (so[a] != b)
            {
                ans++;
                so[a] = b;
            }
        }
    }
    cout << ans;
}