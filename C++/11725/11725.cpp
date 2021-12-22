#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> *v;
int *b;
void f(int a)
{
    for (int i = 0; i < v[a].size(); i++)
    {
        if (b[v[a][i]] == 0)
        {
            b[v[a][i]] = a;
            f(v[a][i]);
        }
    }
}
int main()
{
    cin >> n;
    v = new vector<int>[n + 1];
    b = new int[n + 1];
    fill(b, b + n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    b[1] = 1;
    f(1);
    for (int i = 2; i <= n; i++)
    {
        cout << b[i] << "\n";
    }
}