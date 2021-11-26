#include <iostream>
using namespace std;
int n;
int *nn;
int *nn2;
bool *bb;
int ans;
int minans()
{
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        temp += abs(nn2[i - 1] - nn2[i]);
    }
    return temp;
}
void f(int a)
{
    if (a == n)
    {
        int temp = minans();
        if (ans < temp)
            ans = temp;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!bb[i])
        {
            nn2[a] = nn[i];
            bb[i] = true;
            f(a + 1);
            bb[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    nn = new int[n];
    nn2 = new int[n];
    bb = new bool[n];
    ans = 0;
    fill(bb, bb + n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    f(0);
    cout << ans;
}