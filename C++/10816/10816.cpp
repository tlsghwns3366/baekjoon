#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *nc = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nc[i];
    }
    int m;
    cin >> m;
    sort(nc, nc + n);
    int *mb = new int[m]{0};
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (a <= nc[mid])
            {
                r = mid - 1;
            }
            else if (a > nc[mid])
            {
                l = mid + 1;
            }
        }
        int b = r + 1;
        l = 0;
        r = n - 1;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (a < nc[mid])
            {
                r = mid - 1;
            }
            else if (a >= nc[mid])
            {
                l = mid + 1;
            }
        }
        mb[i] = r - b + 1;
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ", mb[i]);
    }
}