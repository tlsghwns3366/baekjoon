#include <iostream>
using namespace std;
long long int n[1000001];
long long int sum[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = 1; j <= 1000000 / i; j++)
        {
            n[i * j] += j;
        }
        sum[i] = sum[i - 1] + n[i];
    }
    for (int test = 0; test < t; test++)
    {
        int temp;
        cin >> temp;
        cout << sum[temp] << "\n";
    }
}