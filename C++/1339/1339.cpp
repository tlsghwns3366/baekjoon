#include <iostream>
#include <algorithm>
using namespace std;
int f(int a)
{
    if (a == 1)
        return 1;
    return 10 * f(a - 1);
}
int main()
{
    int n;
    cin >> n;
    string nn[n];
    int tx[26] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        int temp = nn[i].length();
        for (int j = temp; j > 0; j--)
        {
            tx[nn[i][temp - j] - 'A'] += f(j) * 1;
        }
    }
    int a = 9;
    int sum = 0;
    sort(tx, tx + 26);
    for (int i = 25; i > 15; i--)
    {
        if (tx[i] != 0)
        {
            sum += a * tx[i];
            a--;
        }
    }
    cout << sum;
}