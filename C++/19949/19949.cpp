#include <iostream>
using namespace std;
int *nn;
int *bb;
int ans;
void f(int a, int b, int c)
{
    if (a == 10)
    {
        int temp = 0;
        for (int i = 0; i < 10; i++)
        {
            if (nn[i] == bb[i])
            {
                temp++;
            }
        }
        if (temp >= 5)
        {
            ans++;
        }
        return;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (!(b == c && c == i))
        {
            bb[a] = i;
            f(a + 1, c, i);
        }
    }
}
int main()
{
    nn = new int[10];
    bb = new int[10];
    ans = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> nn[i];
    }
    f(0, 0, 0);
    cout << ans;
}