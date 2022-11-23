#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int a = 0;
        for (int i = 1; i <= n; i++)
        {
            a = a * 10 + 1;
            a %= n;
            if(a==0)
            {
                cout<<i<<"\n";
                break;
            }
        }
    }
}