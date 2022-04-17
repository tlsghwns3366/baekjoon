#include <iostream>
#include <vector>
using namespace std;
vector<pair<pair<string, int>, int>> v;
int ans[3];
bool a[10];
int anscount = 0;
void f(int s)
{
    if (s == 3)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int b = 0;
            int c = 0;
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (ans[j] == v[i].first.first[k] - '0')
                    {
                        if (j == k)
                            b++;
                        else
                            c++;
                        break;
                    }
                }
            }
            if (b != v[i].first.second || c != v[i].second)
                return;
        }
        anscount++;
        return;
    }
    for (int i = 1; i < 10; i++)
    {
        if (!a[i])
        {
            ans[s] = i;
            a[i] = true;
            f(s + 1);
            a[i] = false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        string a;
        int b, c;
        cin >> a >> b >> c;
        v.push_back({{a, b}, c});
    }
    f(0);
    cout << anscount;
}