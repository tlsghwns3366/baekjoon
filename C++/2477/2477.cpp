#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int n[6];
    for (int i = 0; i < 6; i++)
    {
        int temp;
        cin >> temp >> n[i];
    }
    for (int i = 0; i < 6; i++)
    {
        if (n[(0 + i) % 6] > n[(2 + i) % 6] && n[(1 + i) % 6] > n[(5 + i) % 6])
        {
            cout << (n[(0 + i) % 6] * n[(5 + i) % 6] + n[(2 + i) % 6] * n[(3 + i) % 6]) * k;
            break;
        }
    }
}