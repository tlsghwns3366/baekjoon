#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        int count = 0;
        cin >> n;
        int *nn = new int[n + 1];
        bool *bb = new bool[n + 1];
        fill(nn, nn + n + 1, 0);
        fill(bb, bb + n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            cin >> nn[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!bb[i])
            {
                int temp = nn[i];
                bb[i] = true;
                while (temp != i)
                {
                    bb[temp] = true;
                    temp = nn[temp];
                }
                count++;
            }
        }
        cout << count << endl;
    }
}