#include <iostream>
using namespace std;
class Matx
{
public:
    int **nn;
    int n;
    Matx(int n)
    {
        nn = new int *[n];
        this->n = n;
    }
    Matx operator*(Matx b)
    {
        Matx nk = Matx(n);
        for (int i = 0; i < n; i++)
        {
            nk.nn[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                int a = 0;
                nk.nn[i][j] = 0;
                while (a < n)
                {
                    nk.nn[i][j] += nn[i][a] * b.nn[a][j];
                    a++;
                }
            }
        }
        return nk;
    }
    Matx operator%(int c)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nn[i][j] = nn[i][j] % c;
            }
        }
        return *this;
    }
};
Matx f(Matx nn, long long b, int c)
{
    if (b == 1)
        return nn % c;
    Matx temp = f(nn, b / 2, c);
    temp = (temp * temp) % c;

    if (b % 2 == 0)
        return temp;
    else
        return (temp * nn) % c;
}
int main()
{
    int n;
    long long b;
    cin >> n >> b;
    Matx nn = Matx(n);
    for (int i = 0; i < n; i++)
    {
        nn.nn[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn.nn[i][j];
        }
    }
    nn = f(nn, b, 1000);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nn.nn[i][j] << " ";
        }
        cout << endl;
    }
}