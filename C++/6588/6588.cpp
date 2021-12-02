#include <iostream>
using namespace std;
bool f(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    cin.tie(NULL);
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 3; i <= 1000000; i += 2)
        {
            if (f(i) && f(n - i))
            {
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }
    }
}