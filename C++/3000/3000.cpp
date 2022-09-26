#include <iostream>
using namespace std;
long long int dx[100001];
long long int dy[100001];
long long int cx[100001];
long long int cy[100001];
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        dx[i] = a;
        dy[i] = b;
        cx[a]++;
        cy[b]++;
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cx[dx[i]] > 1 && cy[dy[i]] > 1)
            ans += (cx[dx[i]] - 1) * (cy[dy[i]] - 1);
    }
    cout << ans;
}