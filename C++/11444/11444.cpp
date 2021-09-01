#include <iostream>
using namespace std;
class Matx
{
public:
    long long **nn;
    int n;
    Matx(int n)
    {
        nn = new long long *[n];
        this->n = n;
    }
    Matx operator*(Matx b)
    {
        Matx nk = Matx(n);
        for (int i = 0; i < n; i++)
        {
            nk.nn[i] = new long long[n];
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
    int n = 2;
    long long b;
    cin >> b;
    Matx nn = Matx(2);
    nn.nn[0] = new long long[2];
    nn.nn[1] = new long long[2];
    nn.nn[0][0] = 1;
    nn.nn[0][1] = 1;
    nn.nn[1][0] = 1;
    nn.nn[1][1] = 0;

    nn = f(nn, b, 1000000007);
    cout << nn.nn[0][1];
}