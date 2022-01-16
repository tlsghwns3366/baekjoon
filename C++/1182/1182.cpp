#include <iostream>
using namespace std;

int *nn;
int n, s;
int ans;
void f(int a, int sum)
{
    if (s == sum)
        ans++;
    for(int i = a+1;i<n;i++)
    {
        f(i,sum+nn[i]);
    }
}
int main()
{
    cin >> n >> s;
    nn = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        f(i, nn[i]);
    }
    cout<<ans;
}