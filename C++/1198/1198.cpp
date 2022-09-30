#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double t[40][2];
    for (int i = 0; i < n; i++)
    {
        cin >> t[i][0] >> t[i][1];
    }
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                double a = sqrt((t[j][0] - t[i][0]) * (t[j][0] - t[i][0]) + (t[j][1] - t[i][1]) * (t[j][1] - t[i][1]));
                double b = sqrt((t[k][0] - t[j][0]) * (t[k][0] - t[j][0]) + (t[k][1] - t[j][1]) * (t[k][1] - t[j][1]));
                double c = sqrt((t[i][0] - t[k][0]) * (t[i][0] - t[k][0]) + (t[i][1] - t[k][1]) * (t[i][1] - t[k][1]));
                double s = (a + b + c) / 2;
                double temp = sqrt(s * (s - a) * (s - b) * (s - c));
                max = max < temp ? temp : max;
            }
        }
    }
    cout<<fixed;
    cout.precision(9);
    cout << max;
}