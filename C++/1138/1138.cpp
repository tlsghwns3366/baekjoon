#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int n2[n];
    fill(n2, n2 + n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (n2[j] == 0)
            {
                if (temp == nn[i])
                    n2[j] = i + 1;
                temp++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << n2[i] << " ";
    }
}