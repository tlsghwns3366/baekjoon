#include <iostream>
using namespace std;
int f(int a, int b)
{
    if (a % b == 0)
        return b;
    return f(b, a % b);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int ans = n;
    cout << m - f(n, m);
}