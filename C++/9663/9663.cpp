#include <iostream>

using namespace std;
int count = 0;
void queen(bool *wn, bool *hn, bool *xn, bool *yn, int n, int x, int c)
{
    if (c == n)
    {
        count++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wn[i] == false && hn[j] == false && xn[i + j] == false && yn[n - 1 + i - j] == false)
            {
                if (i >= c + 1)
                    return;
                wn[i] = true;
                hn[j] = true;
                xn[i + j] = true;
                yn[n - 1 + i - j] = true;
                queen(wn, hn, xn, yn, n, x + 1, c + 1);
                wn[i] = false;
                hn[j] = false;
                xn[i + j] = false;
                yn[n - 1 + i - j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    bool *wn = new bool[n]{false};
    bool *hn = new bool[n]{false};
    bool *xn = new bool[n * 2 - 1]{false};
    bool *yn = new bool[n * 2 - 1]{false};

    queen(wn, hn, xn, yn, n, 0, 0);
    printf("%d\n", count);
}