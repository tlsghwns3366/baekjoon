#include <iostream>
using namespace std;

int main()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        b = min(a - b, b);
        long long int ans = 1;
        for (int i = 1; i <= b; i++)
        {
            ans *= a;
            ans /= i;
            a--;
        }
        cout << ans << "\n";
    }
}