#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int bb[n];
    int ans = 1;
    fill(bb, bb + n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (nn[j] < nn[i] && bb[j] <= bb[i])
            {
                bb[j] = bb[i] + 1;
            }
            if (ans < bb[j])
                ans = bb[j];
        }
    }
    cout << ans;
}