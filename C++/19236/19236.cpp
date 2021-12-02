#include <iostream>
using namespace std;
struct Fish
{
    int x[17];
    int y[17];
    int b[17];
};
int nx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int ny[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int ans;
void movefish(int **nn, Fish *fish)
{
    for (int i = 1; i <= 16; i++)
    {
        if (fish->b[i] != 0)
        {
            int x = fish->x[i];
            int y = fish->y[i];
            int b = fish->b[i];
            while (!(x + ny[b] >= 0 && x + ny[b] < 4 && y + nx[b] >= 0 && y + nx[b] < 4 && nn[x + ny[b]][y + nx[b]] != -1))
            {
                b++;
                if (b > 8)
                    b = 1;
            }
            fish->b[i] = b;
            int tempnn = nn[x + ny[b]][y + nx[b]];
            int tempx = fish->x[tempnn];
            int tempy = fish->y[tempnn];
            fish->x[tempnn] = x;
            fish->y[tempnn] = y;
            nn[x + ny[b]][y + nx[b]] = i;
            fish->x[i] = tempx;
            fish->y[i] = tempy;
            nn[x][y] = tempnn;
        }
    }
}
void f(int x, int y, int **nn, int sum, Fish fish)
{
    if (fish.b[nn[x][y]] == 0)
    {
        return;
    }
    int b = fish.b[nn[x][y]];
    int tempnn = nn[x][y];
    fish.b[nn[x][y]] = 0;
    sum += tempnn;
    if (sum > ans)
        ans = sum;

    int **nn2 = new int *[4];
    for (int q = 0; q < 4; q++)
    {
        nn2[q] = new int[4];
        for (int w = 0; w < 4; w++)
        {
            nn2[q][w] = nn[q][w];
        }
    }

    nn2[x][y] = -1;
    movefish(nn2, &fish);
    nn2[x][y] = tempnn;
    for (int i = 1; i <= 3; i++)
    {
        if (x + i * ny[b] >= 0 && x + i * ny[b] < 4 && y + i * nx[b] >= 0 && y + i * nx[b] < 4)
        {
            f(x + i * ny[b], y + i * nx[b], nn2, sum, fish);
        }
    }
}
int main()
{
    Fish fish;
    int **nn;
    ans = 0;
    nn = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        nn[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            int temp, a;
            cin >> temp >> a;
            fish.x[temp] = i;
            fish.y[temp] = j;
            fish.b[temp] = a;
            nn[i][j] = temp;
        }
    }
    f(0, 0, nn, 0, fish);
    cout << ans;
}
