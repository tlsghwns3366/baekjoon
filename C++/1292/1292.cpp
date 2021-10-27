#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int n[b];
    fill(n, n + b, 0);
    int s = 0;
    int c = 1;
    int p = 0;
    while (p < b)
    {
        for (int i = 0; i < c; i++)
        {
            if (p == b)
                break;
            n[p] = c;
            p++;
        }
        c++;
    }
    for (int i = a; i <= b; i++)
    {
        s += n[i - 1];
    }
    cout << s;
}