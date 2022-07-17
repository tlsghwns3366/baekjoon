#include <iostream>
using namespace std;
int gg[100001];
int ans = 0;
int f(int x)
{
    if (gg[x] == x)
        return x;
    else
        return gg[x] = f(gg[x]);
}
int main()
{
    int g;
    cin >> g;
    int p;
    cin >> p;
    int gi[p + 1];
    for (int i = 1; i <= g; i++)
    {
        gg[i] = i;
    }
    for (int i = 1; i <= p; i++)
    {
        cin >> gi[i];
    }
    for (int i = 1; i <= p; i++)
    {
        if (f(gi[i]) == 0)
            break;
        else
        {
            ans++;
            gg[f(gi[i])] = f(f(gi[i]) - 1);
        }
    }
    cout<<ans;
}