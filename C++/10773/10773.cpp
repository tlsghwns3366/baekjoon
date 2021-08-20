#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int *st = new int[k + 1]{0};
    int p = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            p--;
        }
        else
        {
            p++;
            st[p] = a;
        }
    }
    for (int i = 1; i <= p; i++)
    {
        sum += st[i];
    }
    cout << sum;
}