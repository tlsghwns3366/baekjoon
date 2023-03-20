#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k;
vector<int> v;
bool cmp(int a, int b)
{
    return a > b;
}
double f(int a, int c)
{
    double avg = 0;
    for (int i = a; i < a + c; i++)
    {
        avg += v[i];
    }
    avg /= (double)c;
    double temp = 0;
    for (int i = a; i < a + c; i++)
    {
        temp += (v[i] - avg) * (v[i] - avg);
    }
    return sqrt(temp / (double)c);
}
int main()
{
    cin >> n >> k;
	cout.precision(10);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    double ans = 1000000;
    for (int i = k; i <= n; i++)
    {
        for (int j = 0; j + i <= n; j++)
        {
            double temp = f(j, i);
            if (ans > temp)
                ans = temp;
        }
    }
    cout << ans;
}