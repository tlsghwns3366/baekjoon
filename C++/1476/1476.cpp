#include <iostream>
using namespace std;
int main()
{
    int e, s, m;
    cin >> e >> s >> m;
    int a = 1;
    int b = 1;
    int c = 1;
    int count = 1;
    while (!(a == e && b == s && c == m))
    {
        a++;
        b++;
        c++;
        if (a > 15)
            a = 1;
        if (b > 28)
            b = 1;
        if (c > 19)
            c = 1;
        count++;
    }
    cout << count;
}