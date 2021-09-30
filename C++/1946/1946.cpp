#include <iostream>
#include <algorithm>
class NN
{
public:
    int n1;
    int n2;
};
int cmp(NN a, NN b)
{
    if (a.n1 == b.n1)
        return a.n2 < b.n2;
    else
        return a.n1 < b.n1;
}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        NN nn[n];
        for (int j = 0; j < n; j++)
        {
            cin >> nn[j].n1 >> nn[j].n2;
        }
        sort(nn, nn + n, cmp);
        int temp = nn[0].n2;
        int count = 1;
        for (int j = 1; j < n; j++)
        {
            if (nn[j].n2 < temp)
            {
                count++;
                temp = nn[j].n2;
            }
        }
        cout << count << "\n";
    }
}