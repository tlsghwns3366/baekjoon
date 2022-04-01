#include <iostream>
#include <vector>
using namespace std;

int nn[1000001];
int find(int a)
{
    if (nn[a] == a)
        return a;
    else
        return nn[a] = find(nn[a]);
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        nn[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            int x = find(b);
            int y = find(c);
            if (x == y)
                continue;
            nn[x] = y;
        }
        else
        {
            if (find(b) == find(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}