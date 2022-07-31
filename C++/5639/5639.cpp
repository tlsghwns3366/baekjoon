#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void f(int a, int b)
{
    if (a >= b)
        return;
    if (a == b - 1)
    {
        cout << v[a] << "\n";
        return;
    }

    int c = a;
    for (int i = a; i < b; i++)
    {
        if (v[a] < v[i])
            break;
        c++;
    }
    f(a + 1, c);
    f(c, b);
    cout << v[a] << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n)
    {
        v.push_back(n);
    }
    f(0, v.size());
}