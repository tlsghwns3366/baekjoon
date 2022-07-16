#include <iostream>
using namespace std;
int nn[201];
int find(int a)
{
    if (nn[a] == a)
        return a;
    else
        return nn[a] = find(nn[a]);
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        nn[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (temp)
            {
                int x = find(i);
                int y = find(j);
                if (x == y)
                    continue;
                nn[x] = y;
            }
        }
    }
    int root;
    bool ans = true;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        if (i == 0)
            root = find(temp);
        else
        {
            if (root != find(temp))
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";
}