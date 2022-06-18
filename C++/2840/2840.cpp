#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    char nn[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = '?';
    }
    int p = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        a %= n;

        if (p - a < 0)
            p = (p - a) + n;
        else
            p = p - a;
        if (nn[p] != '?' && nn[p] != b)
        {
            cout << "!";
            return 0;
        }
        else
            nn[p] = b;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nn[i] != '?' && nn[i] == nn[j])
            {
                cout << "!";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nn[(i + p) % n];
    }
}
