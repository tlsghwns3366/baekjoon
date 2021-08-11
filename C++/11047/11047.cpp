#include <iostream>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    int *a = new int[n];

    for (int i = n - 1; i >= 0; i--)
    {
        cin >> a[i];
    }
    int j = 0;
    int count = 0;
    while (v > 0)
    {
        if (a[j] <= v)
        {

            v = v - a[j];
            count++;
        }
        else
        {
            j++;
        }
    }
    cout << count;
}