#include <iostream>
using namespace std;
int n;
int ans[8];
bool sosu(int a)
{
    if(a<2)
        return false;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
void f(int c)
{
    if (c == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i < 10; i++)
    {
        ans[c] = i;
        int temp = 0;
        for (int j = 0; j <= c; j++)
        {
            if (c != 0)
                temp *= 10;
            temp += ans[j];
        }
        if(sosu(temp))
            f(c + 1);
    }
}
int main()
{
    cin >> n;
    f(0);
}