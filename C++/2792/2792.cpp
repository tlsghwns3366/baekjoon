#include <iostream>
using namespace std;
int nn[300005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> nn[i];
    }
    int a = 1;
    int b = 1000000000;
    while (a <= b)
    {
        int c = (a + b) / 2;
        int temp = 0;
        for (int i = 0; i < m; i++)
        {
            temp += nn[i] / c;
            if (nn[i] % c != 0)
                temp++;
        }
        if (temp <= n)
        {
            b = c - 1;
        }
        else
        {
            a = c + 1;
        }
    }
    cout << a;
}