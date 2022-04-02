#include <iostream>
#include <vector>
using namespace std;
int n;
int k;
int ans = 0;
vector<int> v[51];
void f(int s)
{
    if (s == k)
        return;

    if (v[s].empty())
        ans++;

    for (int i = 0; i < v[s].size(); i++)
    {
        if (v[s][i] == k && v[s].size() == 1)
            ans++;
        f(v[s][i]);
    }
}
int main()
{
    cin >> n;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == -1)
            start = i;
        else
            v[temp].push_back(i);
    }
    cin >> k;
    f(start);
    cout << ans;
}