#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int *nn;
int *mm;
void f(int a, int b)
{
    if (a == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << mm[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = b; i < n; i++)
    {
        mm[a] = nn[i];
        f(a + 1, b);
        b++;
    }
}
int main()
{
    cin >> n >> m;
    nn = new int[n];
    mm = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    f(0, 0);
}