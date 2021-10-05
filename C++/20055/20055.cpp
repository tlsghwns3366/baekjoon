#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int nn[2 * n];
    bool rr[2 * n];
    fill(rr, rr + 2 * n, false);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nn[i];
    }
    int c = 0;
    int temp = 0;
    while (temp < k)
    {
        c++;
        int temp1 = nn[2 * n - 1];
        bool temp2 = rr[2 * n - 1];
        for (int i = 0; i < 2 * n; i++)
        {
            int a = nn[i];
            bool b = rr[i];
            nn[i] = temp1;
            rr[i] = temp2;
            temp1 = a;
            temp2 = b;

            if (rr[n - 1] == true)
                rr[n - 1] = false;
        }
        temp = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (nn[i] > 0 && rr[i - 1] && !rr[i])
            {
                rr[i - 1] = false;
                rr[i] = true;
                nn[i]--;
            }
            if (rr[n - 1] == true)
                rr[n - 1] = false;
        }
        if (nn[0] > 0 && !rr[0])
        {
            rr[0] = true;
            nn[0]--;
        }
        for (int i = 0; i < 2 * n; i++)
        {
            if (nn[i] == 0)
                temp++;
        }
    }
    cout << c;
}