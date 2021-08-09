#include <iostream>
using namespace std;

int main()
{
    string st1;
    string st2;
    cin >> st1 >> st2;
    int *dp = new int[1000]{0};

    int maxs = 0;
    for (int i = 0; i < st2.length(); i++)
    {
        int max = 0;
        for (int j = 0; j < st1.length(); j++)
        {
            if (max < dp[j])
                max = dp[j];
            else if (st1[j] == st2[i])
            {
                dp[j] = max + 1;
                if (maxs < dp[j])
                    maxs = dp[j];
            }
        }
    }
    cout << maxs;
}