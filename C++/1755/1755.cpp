#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
bool cmp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.first < p2.first;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> v;
    for (int i = n; i <= m; i++)
    {
        v.push_back({"", i});
        if (i > 9)
            v[i - n].first += s[i / 10] + s[i % 10];
        else
            v[i - n].first += s[i % 10];
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i <= m - n; i++)
    {
        cout << v[i].second << " ";
        if (i % 10 == 9)
            cout << endl;
    }
}