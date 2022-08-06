#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    int nn[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + N, cmp);
    int ans = C / A;
    for (int i = 0; i < N; i++)
    {
        C += nn[i];
        A += B;
        if (ans < C / A)
            ans = C / A;
    }
    cout << ans;
}