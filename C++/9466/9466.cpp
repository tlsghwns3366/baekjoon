#include <iostream>
using namespace std;
int *nn;
int *bb;
int *dd;

int ans;
void f(int a, int b, int c)
{
    if (bb[b] != 0 && bb[b] != a)
    {
        return;
    }
    
    if (bb[b] == 0)
    {
        bb[b] = a;
        dd[b] = c;
        f(a, nn[b], c + 1);
    }
    else
    {
        ans += (c - dd[b]);
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        nn = new int[n + 1];
        bb = new int[n + 1];
        dd = new int[n + 1];
        
        for (int i = 1; i <= n; i++)
        {
            cin >> nn[i];
        }
        ans = 0;
        fill(bb, bb + n + 1, 0);
        fill(dd, dd + n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            f(i, i, 0);
        }
        cout << n - ans << "\n";
    }
}