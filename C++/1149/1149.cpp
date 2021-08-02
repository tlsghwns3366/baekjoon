#include <iostream>
using namespace std;

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int n;
    cin >> n;
    int *r = new int[n];
    int *g = new int[n];
    int *b = new int[n];
    int *home = new int[3]{0};
    for (int i = 0; i < n; i++)
    {
        cin >> r[i] >> g[i] >> b[i];
    }
    home[0] = r[0];
    home[1] = g[0];
    home[2] = b[0];
    for (int i = 0; i < n - 1; i++)
    {
        int temp1 = home[0];
        int temp2 = home[1];
        int temp3 = home[2];
        home[0] = min(temp2, temp3) + r[i + 1];
        home[1] = min(temp1, temp3) + g[i + 1];
        home[2] = min(temp1, temp2) + b[i + 1];
    }
    cout << min(min(home[0], home[1]), home[2]);
}