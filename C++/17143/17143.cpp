#include <iostream>
#include <vector>
using namespace std;
struct SHARK
{
    int s = 0;
    int d = 0;
    int z = 0;
    bool ul = false;
};
int main()
{
    int r, c, m;
    cin >> r >> c >> m;
    int rc[r + 1][c + 1];
    vector<SHARK> shark[r + 1][c + 1];
    for (int i = 0; i < m; i++)
    {
        int tr, tc, ts, td, tz;
        SHARK tshark;
        cin >> tr >> tc >> ts >> td >> tz;
        tshark.s = ts;
        tshark.d = td;
        tshark.z = tz;
        if (td == 1)
        {
            tshark.d = 2 * r - tr;
            tshark.ul = false;
        }
        else if (td == 2)
        {
            tshark.d = tr;
            tshark.ul = false;
        }
        else if (td == 3)
        {
            tshark.d = tc;
            tshark.ul = true;
        }
        else if (td == 4)
        {
            tshark.d = 2 * c - tc;
            tshark.ul = true;
        }
        shark[tr][tc].push_back(tshark);
    }
    int ans = 0;
    for (int t = 1; t <= c; t++)
    {
        for (int i = 1; i <= r; i++)
        {
            if (!shark[i][t].empty())
            {
                ans += shark[i][t].front().z;
                shark[i][t].clear();
                break;
            }
        }
        vector<SHARK> tshark[r + 1][c + 1];
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (shark[i][j].size() == 1)
                {
                    int x = i;
                    int y = j;
                    if (shark[i][j].front().ul)
                    {
                        shark[i][j].front().d = (shark[i][j].front().d + shark[i][j].front().s - 1) % (2 * c - 2) + 1;
                        if (shark[i][j].front().d > c)
                            y = 2 * c - shark[i][j].front().d;
                        else
                            y = shark[i][j].front().d;
                    }
                    else
                    {
                        shark[i][j].front().d = (shark[i][j].front().d + shark[i][j].front().s - 1) % (2 * r - 2) + 1;
                        if (shark[i][j].front().d > r)
                            x = 2 * r - shark[i][j].front().d;
                        else
                            x = shark[i][j].front().d;
                    }
                    tshark[x][y].push_back(shark[i][j].front());
                    shark[i][j].clear();
                }
            }
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                int maxshark = 0;
                if (tshark[i][j].size() > 1)
                {
                    for (int k = 0; k < tshark[i][j].size(); k++)
                    {
                        if (tshark[i][j][maxshark].z < tshark[i][j][k].z)
                            maxshark = k;
                    }
                    shark[i][j].push_back(tshark[i][j][maxshark]);
                    tshark[i][j].clear();
                }
                if (tshark[i][j].size() == 1)
                {
                    shark[i][j].push_back(tshark[i][j].front());
                    tshark[i][j].clear();
                }
            }
        }
    }
    cout << ans;
}