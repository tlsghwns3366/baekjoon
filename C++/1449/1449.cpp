#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n, l;
    cin >> n >> l;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = nn[i];
        count++;
        while (i < n - 1)
        {
            if (nn[i + 1] < temp + l)
                i++;
            else
                break;
        }
    }
    cout << count;
}