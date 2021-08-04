#include <iostream>
using namespace std;
void man(bool *sw, int a, int n)
{
    for (int i = 1; i * a <= n; i++)
    {
        sw[i * a - 1] = !sw[i * a - 1];
    }
}
void woman(bool *sw, int a, int n)
{
    sw[a] = !sw[a];
    for (int i = 1; i < n; i++)
    {
        if (a - i < 0 || a + i > n - 1)
            break;
        if (sw[a - i] == sw[a + i])
        {
            sw[a - i] = !sw[a - i];
            sw[a + i] = !sw[a + i];
        }
        else
            break;
    }
}
int main()
{
    int n;
    cin >> n;
    bool *sw = new bool[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sw[i];
    }
    int student;
    cin >> student;

    for (int i = 0; i < student; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            man(sw, b, n);
        }
        else
        {
            woman(sw, b - 1, n);
        }
    }
    for (int j = 0; j < n; j++)
    {
        cout << sw[j]<<" ";
        if (j % 20 == 19)
            cout << endl;
    }
    cout << endl;
}