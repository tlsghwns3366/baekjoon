#include <iostream>
using namespace std;
int abs(int a)
{
    if (a < 0)
        return -a;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int nn[n + 2];
    fill(nn, nn + n + 2, 0);
    int size = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            cout << nn[1] << "\n";
            nn[1] = nn[size - 1];
            nn[size - 1] = 0;
            if (size > 1)
                size--;
            int temp1 = 1;
            int temp2 = temp1 * 2;
            if (temp2 + 1 < size && abs(nn[temp2]) > abs(nn[temp2 + 1]))
                temp2 = temp2 + 1;
            else if (temp2 + 1 < size && abs(nn[temp2]) == abs(nn[temp2 + 1]) && nn[temp2] > nn[temp2 + 1])
                temp2 = temp2 + 1;

            while (temp2 < size && abs(nn[temp2]) <= abs(nn[temp1]))
            {
                if (abs(nn[temp2]) == abs(nn[temp1]))
                {
                    if (nn[temp2] < nn[temp1])
                    {
                        int temp3 = nn[temp2];
                        nn[temp2] = nn[temp1];
                        nn[temp1] = temp3;
                    }
                }
                else
                {
                    int temp3 = nn[temp2];
                    nn[temp2] = nn[temp1];
                    nn[temp1] = temp3;
                }
                temp1 = temp2;
                temp2 = temp1 * 2;
                if (temp2 + 1 < size && abs(nn[temp2]) > abs(nn[temp2 + 1]))
                    temp2 = temp2 + 1;
                else if (temp2 + 1 < size && abs(nn[temp2]) == abs(nn[temp2 + 1]) && nn[temp2] > nn[temp2 + 1])
                    temp2 = temp2 + 1;
            }
        }
        else
        {
            nn[size] = a;
            int temp1 = size;
            int temp2 = size / 2;
            while (temp1 > 1 && abs(nn[temp1]) <= abs(nn[temp2]))
            {
                if (abs(nn[temp1]) == abs(nn[temp2]))
                {
                    if (nn[temp1] < nn[temp2])
                    {
                        int temp3 = nn[temp2];
                        nn[temp2] = nn[temp1];
                        nn[temp1] = temp3;
                    }
                }
                else
                {
                    int temp3 = nn[temp2];
                    nn[temp2] = nn[temp1];
                    nn[temp1] = temp3;
                }
                temp1 = temp2;
                temp2 = temp1 / 2;
            }
            size++;
        }
    }
}