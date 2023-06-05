#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool nn[2001][2001];
int main()
{
    int done, dtwo;
    cin >> done >> dtwo;
    int ans = 1;
    for (int i = done; i <= dtwo; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int temp = gcd(i, j);
            int a = i / temp;
            int b = j / temp;
            if (!nn[a][b])
            {
                ans++;
                nn[a][b] = true;
            }
        }
    }
    cout<<ans;
}