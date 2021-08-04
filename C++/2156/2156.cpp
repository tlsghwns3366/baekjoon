#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *podo = new int[10000];
    int *suma = new int[10000];
    int *sumb = new int[10000];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> podo[i];
    }
    suma[0] = podo[0];
    sumb[0] = 0;
    suma[1] = suma[0] + podo[1];
    sumb[1] = podo[1];
    suma[2] = sumb[1] + podo[2];
    sumb[2] = suma[0] + podo[2];

    for (int i = 0; i < n; i++)
    {
        if (i > 2)
        {
            int c = 0;
            suma[i] = sumb[i - 1] + podo[i];
            if (c < suma[i - 2])
                c = suma[i - 2];
            if (c < suma[i - 3])
                c = suma[i - 3];
            if (c < sumb[i - 2])
                c = sumb[i - 2];
            if (c < sumb[i - 3])
                c = sumb[i - 3];
            sumb[i] = c + podo[i];
        }
        if (suma[i] > max)
            max = suma[i];
        if (sumb[i] > max)
            max = sumb[i];
    }
    cout << max;
}