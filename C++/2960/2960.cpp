#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int nn[n + 1];
    bool bb[n + 1];
    fill(bb, bb + n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        nn[i] = i;
    }
    int c = 0;
    int ans;
    bb[1] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!bb[i])
        {
            int j = nn[i];
            for (; j <= n; j += nn[i])
            {
                if (!bb[j])
                {
                    bb[j] = true;
                    c++;
                    if (c == k)
                    {
                        cout << nn[j];
                        break;
                    }
                }
            }
        }
    }
}