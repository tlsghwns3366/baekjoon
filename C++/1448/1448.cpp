#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    int ans = -1;
    for (int i = 0; i < n - 2; i++)
    {
        if (v[i] < v[i + 1] + v[i + 2])
        {
            ans = v[i] + v[i + 1] + v[i + 2];
            break;
        }
    }
    cout << ans;
}