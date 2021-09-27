#include <iostream>
using namespace std;
int n[21];
void f(int a, int b)
{
    for (int i = 0; i < (b - a + 1) / 2; i++)
    {
        int temp = n[b - i];
        n[b - i] = n[a + i];
        n[a + i] = temp;
    }
}
int main()
{
    for (int i = 1; i <= 20; i++)
    {
        n[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        f(a, b);
    }
    for (int i = 1; i <= 20; i++)
    {
        cout << n[i] << " ";
    }
}