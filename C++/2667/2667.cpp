#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
int vsize = 0;
void f(int **nn, bool **bb, int a, int b)
{
    if (!bb[a][b])
        return;
    else
    {
        bb[a][b] = false;
        v[vsize - 1]++;
        if (a - 1 >= 0)
            f(nn, bb, a - 1, b);
        if (a + 1 < n)
            f(nn, bb, a + 1, b);
        if (b - 1 >= 0)
            f(nn, bb, a, b - 1);
        if (b + 1 < n)
            f(nn, bb, a, b + 1);
    }
}
int main()
{
    cin >> n;
    int **nn = new int *[n];
    bool **bb = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        nn[i] = new int[n];
        bb[i] = new bool[n];
        for (int j = 0; j < a.length(); j++)
        {
            nn[i][j] = a[j] - '0';
            if (nn[i][j] == 1)
                bb[i][j] = true;
            else
                bb[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nn[i][j] == 1 && bb[i][j])
            {
                v.push_back(0);
                vsize++;
                f(nn, bb, i, j);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << vsize << endl;
    for (int i = 0; i < vsize; i++)
    {
        cout << v[i] << endl;
    }
}