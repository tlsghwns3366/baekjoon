#include <iostream>
using namespace std;
struct XY
{
    int x;
    int y;
};

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    XY xy[4];
    xy[0].x = x1;
    xy[0].y = y1;
    xy[1].x = x1;
    xy[1].y = y2;
    xy[2].x = x2;
    xy[2].y = y1;
    xy[3].x = x2;
    xy[3].y = y2;

    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < 4; i++)
    {
        if (xy[i].x * a + xy[i].y * b + c <= 0)
            t1++;
        if (xy[i].x * a + xy[i].y * b + c >= 0)
            t2++;
    }
    if (t1 == 4 || t2 == 4)
        cout << "Lucky";
    else
        cout << "Poor";
}