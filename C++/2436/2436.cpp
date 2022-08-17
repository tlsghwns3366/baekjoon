#include <iostream>
#include <climits>
using namespace std;
long long int uc(long long int a, long long int b)
{
    long long int r = a % b;
    if (r == 0)
        return b;
    return uc(b, r);
}
int main()
{
    long long int A, B;
    cin >> A >> B;
    long long int a, b;
    a = A;
    b = B;
    long long int i = 1;
    long long int ansa = A;
    long long int ansb = B;
    while (a < b)
    {
        if (B % i != 0)
        {
            i++;
            continue;
        }
        a = A * i;
        b = B / i;
        if (uc(a, b) == A)
        {
            if (ansa + ansb > a + b)
            {
                ansa = a;
                ansb = b;
            }
        }
        i++;
    }
    cout<<ansa<<" "<<ansb;
}