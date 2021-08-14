#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *tn = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tn[i];
    }
    sort(tn, tn + n);
    cout << tn[0] * tn[n - 1];
}