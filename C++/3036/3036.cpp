#include <iostream>
using namespace std;
int chleo(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return chleo(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    int *ring = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ring[i];
    }

    for (int i = 1; i < n; i++)
    {
        cout << ring[0] / chleo(ring[0], ring[i]) << "/" << ring[i] / chleo(ring[0], ring[i]) << endl;
    }
}