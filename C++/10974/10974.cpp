#include <iostream>
using namespace std;
int n;
int *ans;
bool *nb;
void f(int a)
{
    if (a == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        if (!nb[i])
        {
            ans[a] = i + 1;
            nb[i] = true;
            f(a + 1);
            nb[i] = false;
            ans[a] = 0;
        }
    }
}

int main()
{
    cin >> n;
    ans = new int[n];
    nb = new bool[n];
    fill(nb, nb + n, false);
    f(0);
}