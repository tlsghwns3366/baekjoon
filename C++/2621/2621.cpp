#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    if (p1.second < p2.second)
        return true;
    else
        return false;
}
int main()
{
    vector<pair<char, int>> v;
    int intcount[10] = {0};
    int RBYGcount[4] = {0};
    for (int i = 0; i < 5; i++)
    {
        char tempc;
        int tempi;
        cin >> tempc >> tempi;
        intcount[tempi]++;
        if (tempc == 'R')
            RBYGcount[0]++;
        else if (tempc == 'B')
            RBYGcount[1]++;
        else if (tempc == 'Y')
            RBYGcount[2]++;
        else if (tempc == 'G')
            RBYGcount[3]++;
        v.push_back({tempc, tempi});
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 100 + v[4].second;
    int b1 = 0;
    int b2 = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (intcount[i] == 2)
        {
            ans = max(200 + i, ans);
            if (b1 != 0)
                ans = max(300 + (i * 10) + b1, ans);
            if (b2 != 0)
                ans = max(700 + (b2 * 10) + i, ans);
            b1 = i;
        }
        else if (intcount[i] == 3)
        {
            ans = max(400 + i, ans);
            if (b1 != 0)
                ans = max(700 + (i * 10) + b1, ans);
            b2 = i;
        }
        else if (intcount[i] == 4)
            ans = max(800 + i, ans);
    }
    bool b3 = false;
    for (int i = 1; i < 7; i++)
    {
        if (intcount[i] == 1 && intcount[i + 1] == 1 && intcount[i + 2] == 1 && intcount[i + 3] == 1 && intcount[i + 4] == 1)
        {
            ans = max(500 + v[4].second, ans);
            b3 = true;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (RBYGcount[i] == 5 && b3)
            ans = max(900 + v[4].second, ans);
        else if (RBYGcount[i] == 5)
            ans = max(600 + v[4].second, ans);
    }
    cout << ans;
}