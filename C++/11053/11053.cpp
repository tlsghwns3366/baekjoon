#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n]{0};
    int *b = new int[n]{0};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int c = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[i];
        int max = 0;
        for (int j = i; j < n; j++)
        {
            if (temp < a[j])
            {
                if (b[j] > 0)
                {
                    if (b[j] > max)
                        max = b[j];
                }
                else
                {
                    b[i]++;
                    temp = a[j];
                }
            }
        }
        b[i] += max + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] > c)
            c = b[i];
    }
    cout << c;
}