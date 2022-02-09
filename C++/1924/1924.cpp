#include <iostream>
using namespace std;
int main()
{
    int m, d;
    cin >> m >> d;
    int mm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int temp = d;
    for (int i = 0; i < m - 1; i++)
    {
        temp += mm[i];
    }
    if (temp % 7 == 0)
        cout << "SUN";
    else if (temp % 7 == 1)
        cout << "MON";
    else if (temp % 7 == 2)
        cout << "TUE";
    else if (temp % 7 == 3)
        cout << "WED";
    else if (temp % 7 == 4)
        cout << "THU";
    else if (temp % 7 == 5)
        cout << "FRI";
    else if (temp % 7 == 6)
        cout << "SAT";
}