#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int *nn = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);

    int a = n - 1;
    int b = 0;
    int min = 2000000000;
    int temp1 = a;
    int temp2 = b;
    while (a > b)
    {
        int c = nn[a] + nn[b];
        if (min > abs(c))
        {
            min = abs(c);
            temp1 = a;
            temp2 = b;
        }

        if (c < 0)
            b++;
        else
            a--;
    }
    cout << nn[temp2] << " " << nn[temp1];
}