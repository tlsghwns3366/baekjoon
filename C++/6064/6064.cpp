#include <iostream>
using namespace std;
int main()
{
    int w;
    cin >> w;
    for (int q = 0; q < w; q++)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int tempx = x;
        int tempy = y;
        int ans=x;
        while (true)
        {
            if (tempx < tempy)
            {
                tempx += m;
                ans = tempy;
            }
            else if (tempx > tempy)
            {
                tempy += n;
                ans = tempy;
            }
            else
                break;
            if (tempx > m * n || tempy > m * n)
            {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
}