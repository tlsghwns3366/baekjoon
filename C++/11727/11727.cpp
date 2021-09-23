#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[1000];
    nn[0] = 1;
    nn[1] = 3;
    for (int i = 2; i < n; i++)
    {
        nn[i] = (nn[i - 1] + (2 * nn[i - 2])) % 10007;
    }
    cout << nn[n - 1];
}