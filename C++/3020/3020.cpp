#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nn1[500001];
int nn2[500001];
int sum1[500001];
int sum2[500001];
vector<int> ans;
int main()
{
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
            nn2[temp]++;
        else
            nn1[temp]++;
    }
    for (int i = 1; i <= h; i++)
    {
        if (i == 1)
        {
            sum1[i] += nn1[h - i + 1];
            sum2[i] += nn2[h - i + 1];
        }
        else
        {
            sum1[i] = sum1[i - 1] + nn1[h - i + 1];
            sum2[i] = sum2[i - 1] + nn2[h - i + 1];
        }
    }
    for (int i = 1; i <= h; i++)
    {
        ans.push_back(sum1[i] + sum2[h - i + 1]);
    }
    sort(ans.begin(), ans.end());

    int a = ans[0];
    int b = 1;
    for (int i = 1; i < ans.size(); i++)
    {
        if (a == ans[i])
            b++;
    }
    cout << a << " " << b << "\n";
}