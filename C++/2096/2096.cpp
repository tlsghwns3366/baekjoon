#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    int n;
    cin >> n;
    int dpa[3] = {0,};
    int dpb[3] = {0,};
    for (int i = 0; i < n; i++)
    {
        int nn[3];
        cin >> nn[0] >> nn[1] >> nn[2];
        dpa[0] = max(dpa[0] + nn[0], dpa[1] + nn[0]);
        dpa[2] = max(dpa[1] + nn[2], dpa[2] + nn[2]);
        dpa[1] = max(dpa[0] - nn[0] + nn[1], dpa[2] - nn[2] + nn[1]);

        dpb[0] = min(dpb[0] + nn[0], dpb[1] + nn[0]);
        dpb[2] = min(dpb[1] + nn[2], dpb[2] + nn[2]);
        dpb[1] = min(dpb[0] - nn[0] + nn[1], dpb[2] - nn[2] + nn[1]);
    }
    cout << max(max(dpa[0], dpa[1]), dpa[2]) << " " << min(min(dpb[0], dpb[1]), dpb[2]);
}