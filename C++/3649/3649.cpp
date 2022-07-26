#include <iostream>
#include <algorithm>
using namespace std;
int x, n;
int e[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> x)
    {
        x *= 10000000;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> e[i];
        }
        sort(e, e + n);
        int a = 0;
        int b = n - 1;
        int sum = 0;
        while (a < b)
        {
            sum = e[a] + e[b];
            if (sum == x)
                break;
            else if (sum < x)
                a++;
            else
                b--;
        }
        if (sum == x)
            cout << "yes " << e[a] << " " << e[b] << endl;
        else
            cout << "danger\n";
    }
    return 0;
}