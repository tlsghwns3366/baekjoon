#include <iostream>
using namespace std;
int temp;

int n;
bool b;
void f(int a)
{
    if (a == 0)
    {
        temp += 3;
        if (temp == n)
            b = true;
        return;
    }
    else
    {
        f(a - 1);
        temp += a + 3;
        if (temp == n)
            b = true;
        f(a - 1);
    }
}
int main()
{
    cin >> n;
    temp = 1;
    b = false;
    f(27);
    if (b)
        cout << "m";
    else
        cout << "o";
}