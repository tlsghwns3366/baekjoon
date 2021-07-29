#include <iostream>
using namespace std;

int main()
{
    int *a = new int[8];

    int b;
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
        if (i != 0 && b != 3)
        {
            if (a[i - 1] + 1 == a[i])
                b = 1;
            else if (a[i - 1] - 1 == a[i])
                b = 2;
            else
                b = 3;
        }
    }
    if (b == 1)
        cout << "ascending" << endl;
    if (b == 2)
        cout << "descending" << endl;
    if (b == 3)
        cout << "mixed" << endl;
}