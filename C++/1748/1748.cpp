#include <iostream>
using namespace std;
int t(int a)
{
    if (a == 0)
        return 1;
    return 10 * t(a - 1);
}
int main()
{
    int n;
    cin >> n;
    long long int sum = 0;
    int a = 1;
    int temp = n;
    for (int i = 0; i < 9; i++)
    {
        if (temp / 10 > 0)
        {
            temp = temp / 10;
            a++;
        }
    }
    for (int i = 0; i < a; i++)
    {
        sum += (9 * t(i)) * (i + 1);
    }
    cout << sum - ((t(a) - n - 1) * a);
}