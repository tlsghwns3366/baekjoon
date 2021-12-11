#include <iostream>
#include <climits>
using namespace std;
int main()
{
    long long int s, c;
    cin >> s >> c;
    int ss[s];
    int pa = 0;
    long long int sum = 0;
    for (int i = 0; i < s; i++)
    {
        cin >> ss[i];
        sum += ss[i];
        if (pa < ss[i])
            pa = ss[i];
    }

    int a = 1;
    int b = pa;
    int m = (a + b) / 2;
    int ans = INT_MAX;
    while (a <= b)
    {
        int temp = 0;
        for (int i = 0; i < s; i++)
        {
            temp += ss[i] / m;
        }
        if (temp >= c)
        {
            a = m + 1;
        }
        else if (temp < c)
        {
            b = m - 1;
        }
        m = (a + b) / 2;
    }
    cout << sum - m * c;
}