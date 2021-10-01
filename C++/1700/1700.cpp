#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int kk[k];
    int nn[n];
    fill(kk, kk + k, 0);
    fill(nn, nn + n, 0);
    for (int i = 0; i < k; i++)
    {
        cin >> kk[i];
    }
    int count = 0;
    int p = 0;
    for (int i = 0; i < k; i++)
    {
        bool a = false;
        for (int j = 0; j < n; j++)
        {
            if (kk[i] == nn[j])
            {
                a = true;
                break;
            }
        }
        if (!a)
        {
            if (p < n)
            {
                nn[p] = kk[i];
                p++;
                continue;
            }
            int max = 0;
            int index = 0;
            for (int j = 0; j < n; j++)
            {
                int temp = 0;
                for (int z = i + 1; z < k; z++)
                {
                    if (nn[j] == kk[z])
                    {
                        temp = z;
                        break;
                    }
                }
                if (temp == 0)
                {
                    index = j;
                    break;
                }
                if (max < temp)
                {
                    max = temp;
                    index = j;
                }
            }
            nn[index] = kk[i];
            count++;
        }
    }
    cout << count;
}