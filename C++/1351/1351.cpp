#include <iostream>
#include <map>
using namespace std;
long long int n;
long long int p, q;
map<long long, long long> m;
void f(long long a)
{
    if (a == 0)
        return;
    if (m[a / p] == 0)
    {
        f(a / p);
    }
    if (m[a / q] == 0)
    {
        f(a / q);
    }
    m[a] = m[a / p] + m[a / q];
}
int main()
{
    cin >> n >> p >> q;
    m[0] = 1;
    f(n);
    cout << m[n];
}