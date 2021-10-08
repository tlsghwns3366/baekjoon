#include <iostream>
using namespace std;
int c[300000];
int ap(int a, int p)
{
    int temp = 1;
    for (int i = 0; i < p; i++)
    {
        temp *= a;
    }
    return temp;
}
int main()
{
    int a, p;
    cin >> a >> p;
    int n[300000];
    fill(n, n + 300000, 0);
    int i = 0;
    int z = 0;
    n[0] = a;
    while (true)
    {
        n[i + 1] = 0;
        int temp = n[i];
        for (int j = 0; j < 5; j++)
        {
            if (temp / 10 > 0)
            {
                n[i + 1] += ap(temp % 10, p);
                temp = temp / 10;
            }
            else
            {
                n[i + 1] += ap(temp % 10, p);
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (n[i + 1] == n[j])
            {
                c[z] = n[i + 1];
                z++;
                break;
            }
        }
        i++;
        if (z > 1 && c[0] == c[z - 1])
            break;
    }
    int count = i - z + 1;
    for (int j = 0; j <= i - z; j++)
    {
        for (int k = 0; k < z; k++)
        {
            if (n[j] == c[k])
            {
                count--;
                break;
            }
        }
    }
    cout << count;
}