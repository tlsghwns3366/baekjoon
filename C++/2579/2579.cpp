#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *step = new int[300]{0};
    for (int i = 0; i < n; i++)
    {
        cin >> step[i];
    }
    int sumone[300];
    int sumtwo[300];
    sumone[0] = step[0];
    sumtwo[0] = 0;
    sumone[1] = step[1] + sumone[0];
    sumtwo[1] = step[1];

    for (int i = 2; i < n; i++)
    {
        sumone[i] = sumtwo[i - 1] + step[i];
        if (sumone[i - 2] < sumtwo[i - 2])
        {
            sumtwo[i] = sumtwo[i - 2] + step[i];
        }
        else
        {
            sumtwo[i] = sumone[i - 2] + step[i];
        }
    }
    if (sumone[n - 1] < sumtwo[n - 1])
        cout << sumtwo[n - 1];
    else
        cout << sumone[n - 1];
}