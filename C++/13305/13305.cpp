#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long *doro = new long long[n - 1];
    long long *ga = new long long[n];
    long long maxdoro = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> doro[i];
        maxdoro += doro[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> ga[i];
    }
    long long minga = ga[0];
    long long mingasum = 0;
    for (int i = 1; i < n; i++)
    {
        mingasum += minga * doro[i - 1];
        if (minga > ga[i])
            minga = ga[i];
        maxdoro -= doro[i - 1];
    }
    cout << mingasum << endl;
}