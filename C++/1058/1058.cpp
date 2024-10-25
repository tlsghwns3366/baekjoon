#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> vn(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            bool CheckFriend = false;
            if (v[j][i] == 'Y')
            {
                vn[i][j] = 1;
                CheckFriend = true;
            }
            for (int k = 0; k < v[j].length(); k++)
            {
                if (i == k)
                    continue;
                if (v[j][k] == 'Y')
                {
                    vn[j][k] = 1;
                    if (CheckFriend)
                    {
                        vn[i][k] = 1;
                    }
                }
            }
        }
    }
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if(i==j)
                continue;
            count += vn[i][j];
        }
        answer = answer < count ? count : answer;
    }
    cout << answer;
}
