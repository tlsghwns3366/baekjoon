#include <iostream>
using namespace std;
int m, n;
int nn[1000001];
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int a = 1;
    int b = 1000000000;
    int ans = 0;
    while (a <= b)
    {
        int c = (a + b) / 2;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += nn[i] / c;
        }
        if (temp < m)
        {
            b = c - 1;
        }
        else
        {
            ans = c;
            a = c + 1;
        }
    }
    cout<<ans;
}