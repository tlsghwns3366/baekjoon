#include <iostream>
using namespace std;

int main()
{
    long long int xy[4][2];
    for (int i = 0; i < 4; i++)
    {
        cin >> xy[i][0] >> xy[i][1];
    }
    string ans = "NULL";
    if (xy[0][0] == xy[3][0] || xy[1][0] == xy[2][0])
    {
        if (xy[0][1] == xy[3][1] || xy[1][1] == xy[2][1])
            ans = "POINT";
        else if (((xy[1][1] - xy[0][1]) + (xy[3][1] - xy[2][1])) > max(xy[3][1] - xy[0][1], xy[1][1] - xy[2][1]))
            ans = "LINE";
        else
            ans = "NULL";
    }
    else if ((xy[1][0] - xy[0][0]) + (xy[3][0] - xy[2][0]) > max(xy[3][0] - xy[0][0], xy[1][0] - xy[2][0]))
    {
        if (xy[0][1] == xy[3][1] || xy[1][1] == xy[2][1])
            ans = "LINE";
        else if (((xy[1][1] - xy[0][1]) + (xy[3][1] - xy[2][1])) > max(xy[3][1] - xy[0][1], xy[1][1] - xy[2][1]))
            ans = "FACE";
        else
            ans = "NULL";
    }
    else
        ans = "NULL";

    cout << ans;
}