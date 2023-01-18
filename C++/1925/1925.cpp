#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x1, x2, x3;
    int y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    if ((y1 - y2) * (x1 - x3) == (x1 - x2) * (y1 - y3))
    {
        cout << "X";
    }
    else
    {
        int d[3];
        d[0] = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        d[1] = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
        d[2] = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        sort(d, d + 3);
        if (d[0] == d[1] && d[1] == d[2])
        {
            cout << "JungTriangle";
        }
        else if (d[0] == d[1] || d[1] == d[2])
        {
            if (d[2] == d[0] + d[1])
                cout << "Jikkak2Triangle";
            else if (d[2] < d[0] + d[1])
                cout << "Yeahkak2Triangle";
            else
                cout << "Dunkak2Triangle";
        }
        else
        {
            if (d[2] == d[0] + d[1])
                cout << "JikkakTriangle";
            else if (d[2] < d[0] + d[1])
                cout << "YeahkakTriangle";
            else
                cout << "DunkakTriangle";
        }
    }
}