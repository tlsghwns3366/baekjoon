#include <iostream>
#include <climits>
using namespace std;
int d[51];
int ans[51];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        double a = -9999999999;
        for (int j = i + 1; j <= n; j++)
        {
            double temp = (double)(d[j] - d[i]) / (double)(j - i);
            if(temp > a)
            {
                ans[i]++;
                ans[j]++;
                a = temp;
            }
        }
    }
    int s = 0;
    for(int i = 1;i<=n;i++)
    {
        s = ans[i] < s ? s : ans[i];
        cout<<ans[i]<<" ";
    }
    cout<<s;
}