#include <iostream>
#include <vector>
using namespace std;
int bn[10];
int n;
vector<pair<int, int>> v;
int ans = 987654321;
void f(int a, int c)
{
    if (c != 0)
    {
        int ansa = 1;
        int ansb = 0;
        for (int i = 0; i < c; i++)
        {
            ansa *= v[bn[i]].first;
            ansb += v[bn[i]].second;
        }
        ans = ans < abs(ansa - ansb) ? ans : abs(ansa - ansb);
    }
    for (int i = a; i < n; i++)
    {
        bn[c] = i;
        f(i + 1, c + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    f(0, 0);
    cout << ans;
}