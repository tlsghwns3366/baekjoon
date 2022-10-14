#include <iostream>
using namespace std;
int n, m;
char nm[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dc[4] = {'U','R','D','L'};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            nm[i][j] = s[j - 1];
        }
    }
    int x, y;
    cin >> x >> y;
    string ansc = "U";
    int anst = 0;
    for (int q = 0; q < 4; q++)
    {
        int time = 0;
        int tx = x;
        int ty = y;
        int b = q;
        while (true)
        {
            time++;
            if (tx + dx[b] <= n && tx + dx[b] > 0 && ty + dy[b] <= m && ty + dy[b] > 0)
            {
                tx+=dx[b];
                ty+=dy[b];
                if(tx == x && ty == y && b == q)
                {
                    time = 987654321;
                    break;
                }
                if (nm[tx][ty] == 'C')
                    break;
                else if (nm[tx][ty] == '\\')
                {
                    if (b == 0)
                        b = 3;
                    else if (b == 1)
                        b = 2;
                    else if (b == 2)
                        b = 1;
                    else
                        b = 0;
                }
                else if (nm[tx][ty] == '/')
                {
                    if (b == 0)
                        b = 1;
                    else if (b == 1)
                        b = 0;
                    else if (b == 2)
                        b = 3;
                    else
                        b = 2;
                }
            }
            else
                break;
        }
        if(time>anst)
        {
            ansc = dc[q];
            anst = time;
        }
    }
    cout<<ansc<<endl;
    if(anst == 987654321)
        cout<<"Voyager";
    else
        cout<<anst;
}