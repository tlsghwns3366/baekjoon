#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int count = 1;
    while (a != b)
    {
        if (b < a)
        {
            count = -1;
            break;
        }
        if (b % 10 == 1)
        {
            b = b / 10;
            count++;
        }
        else if (b % 2 == 0)
        {
            b = b / 2;
            count++;
        }
        else
        {
            count = -1;
            break;
        }
    }
    cout << count;
}