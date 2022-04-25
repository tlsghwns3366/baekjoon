#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n + 1];
    bool b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> nn[i];
        b[nn[i]] = true;
    }
    int ans = -1;
    for (int i = n; i > 1; i--)
    {
        b[nn[i]] = false;

        if (nn[i - 1] > nn[i])
        {
            for (int j = nn[i - 1]; j > 0; j--)
            {
                if (!b[j])
                {
                    b[nn[i - 1]] = false;
                    nn[i - 1] = j;
                    b[j] = true;
                    break;
                }
            }
            for (int j = n; j > 0; j--)
            {
                if (!b[j])
                {
                    nn[i] = j;
                    i++;
                }
            }
            ans = 0;
            break;
        }
    }
    if (ans == -1)
        cout << ans;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << nn[i] << " ";
        }
    }
}