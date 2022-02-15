#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int nn[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    v.push_back(nn[0]);
    for (int i = 1; i < n; i++)
    {
        if (v.back() < nn[i])
            v.push_back(nn[i]);
        else
        {
            int a = 0;
            int b = v.size() - 1;
            while (a < b)
            {
                int c = (a + b) / 2;
                if (nn[i] > v[c])
                    a = c + 1;
                else
                {
                    b = c;
                }
            }
            v[b] = nn[i];
        }
    }
    cout << v.size();
}