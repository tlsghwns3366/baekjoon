#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}
int main()
{
    int k, l;
    cin >> k >> l;
    map<string, int> m;
    for (int i = 1; i <= l; i++)
    {
        string temp;
        cin >> temp;
        m[temp] = i;
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++)
    {
        if (i < v.size())
            cout << v[i].first << "\n";
    }
}