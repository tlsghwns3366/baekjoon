#include <iostream>
using namespace std;
int chleo(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return chleo(b, a % b);
}
int chlth(int a, int b)
{
    return abs(a * b) / chleo(a, b);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << chlth(a, b) << endl;
    }
}