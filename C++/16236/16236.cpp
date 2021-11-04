#include <iostream>
#include <queue>
#include <climits>
using namespace std;
class Shark
{
public:
    pair<int, int> xy;
    int size;
    int e;
    int time;
    Shark()
    {
        size = 2;
        time = 0;
        e = 0;
    }
    void eat()
    {
        e++;
        if (e == size)
        {
            size++;
            e = 0;
        }
    }
};
int n;
int **nn;
int **bb;
int nx[4] = {-1, 0, 0, 1};
int ny[4] = {0, -1, 1, 0};
Shark shark;
void f(int a, int b)
{
    bb = new int *[n];
    for (int i = 0; i < n; i++)
    {
        bb[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            bb[i][j] = INT_MAX;
        }
    }
    queue<pair<int, int>> q;
    nn[a][b] = 0;
    bb[a][b] = 0;
    q.push({a, b});
    while (!q.empty())
    {
        int te1 = q.front().first;
        int te2 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (te1 + nx[i] >= 0 && te1 + nx[i] < n && te2 + ny[i] >= 0 && te2 + ny[i] < n)
            {
                if (bb[te1 + nx[i]][te2 + ny[i]] > bb[te1][te2] + 1 && nn[te1 + nx[i]][te2 + ny[i]] <= shark.size)
                {
                    bb[te1 + nx[i]][te2 + ny[i]] = bb[te1][te2] + 1;
                    q.push({te1 + nx[i], te2 + ny[i]});
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 9)
            {
                shark.xy.first = i;
                shark.xy.second = j;
            }
        }
    }

    while (true)
    {
        f(shark.xy.first, shark.xy.second);
        int temp = INT_MAX;
        pair<int, int> xy;
        bool b = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nn[i][j] < shark.size && nn[i][j] != 0 && temp > bb[i][j])
                {
                    temp = bb[i][j];
                    xy.first = i;
                    xy.second = j;
                    b = true;
                }
            }
        }
        if (b)
        {
            shark.eat();
            shark.time += temp;
            nn[xy.first][xy.second] = 9;
            shark.xy.first = xy.first;
            shark.xy.second = xy.second;
        }
        else
        {
            cout << shark.time;
            break;
        }
    }
}