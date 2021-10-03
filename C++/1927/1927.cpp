#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int nn[n + 2];
    fill(nn, nn + n + 2, 0);
    int size = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[size];
        if (nn[size] == 0)
        {
            cout << nn[1] << "\n";
            nn[1] = nn[size - 1];
            nn[size - 1] = 0;
            if (size > 1)
                size--;
            int a = 1;
            int b = a * 2;

            if (b + 1 < size && nn[b] > nn[b + 1])
                b = b + 1;

            while (b < size && nn[b] < nn[a])
            {
                int temp = nn[b];
                nn[b] = nn[a];
                nn[a] = temp;
                a = b;
                b = a * 2;
                if (b + 1 < size && nn[b] > nn[b + 1])
                    b = b + 1;
            }
        }
        else
        {
            int a = size;
            int b = size / 2;

            while (a > 1 && nn[b] > nn[a])
            {
                int temp = nn[b];
                nn[b] = nn[a];
                nn[a] = temp;
                a = b;
                b = a / 2;
            }
            size++;
        }
    }
}