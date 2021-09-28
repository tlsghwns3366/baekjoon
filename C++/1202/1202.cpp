#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
class mivi
{
public:
    int mi;
    int vi;
};
int cmp(mivi a, mivi b)
{
    if (a.vi == b.vi)
        return a.mi > b.mi;
    else
        return a.vi > b.vi;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    mivi mvi[n];
    multiset<int> ci;
    for (int i = 0; i < n; i++)
    {
        cin >> mvi[i].mi >> mvi[i].vi;
    }
    for (int i = 0; i < k; ++i)
    {
        int a;
        cin >> a;
        ci.insert(a);
    }
    sort(mvi, mvi + n, cmp);
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        auto temp = ci.lower_bound(mvi[i].mi);
        if (temp != ci.end())
        {
            sum += mvi[i].vi;
            ci.erase(temp);
        }
    }
    cout << sum;
}