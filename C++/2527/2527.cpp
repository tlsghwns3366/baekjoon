#include <iostream>
#include <algorithm>
using namespace std;
struct RECT
{
    long long int x[4];
    long long int y[4];
};

int main()
{
    for (int q = 0; q < 4; q++)
    {
        RECT r1, r2, r3;
        cin >> r1.x[0] >> r1.y[0] >> r1.x[3] >> r1.y[3];
        cin >> r2.x[0] >> r2.y[0] >> r2.x[3] >> r2.y[3];

        r1.x[1] = r1.x[0];
        r1.y[1] = r1.y[3];
        r1.x[2] = r1.x[3];
        r1.y[2] = r1.y[0];

        r2.x[1] = r2.x[0];
        r2.y[1] = r2.y[3];
        r2.x[2] = r2.x[3];
        r2.y[2] = r2.y[0];

        if (r1.x[0] > r2.x[3] || r1.x[3] < r2.x[0] || r1.y[3] < r2.y[0] || r1.y[0] > r2.y[3])
        {
            cout << "d\n";
        }
        else
        {
            r3.x[0] = max(r1.x[0], r2.x[0]);
            r3.y[0] = max(r1.y[0], r2.y[0]);
            r3.x[3] = min(r1.x[3], r2.x[3]);
            r3.y[3] = min(r1.y[3], r2.y[3]);

            r3.x[1] = r3.x[0];
            r3.y[1] = r3.y[3];
            r3.x[2] = r3.x[3];
            r3.y[2] = r3.y[0];

            long long int ans = (r3.x[3] - r3.x[0]) * (r3.y[3] - r3.y[0]);
            if (ans > 0)
            {
                cout << "a\n";
            }
            else
            {
                if (r1.x[3] == r2.x[0] && r1.y[3] == r2.y[0] || r1.x[1] == r2.x[2] && r1.y[1] == r2.y[2] || r1.x[2] == r2.x[1] && r1.y[2] == r2.y[1] || r1.x[0] == r2.x[3] && r1.y[0] == r2.y[3])
                {
                    cout << "c\n";
                }
                else
                {
                    cout << "b\n";
                }
            }
        }
    }
}