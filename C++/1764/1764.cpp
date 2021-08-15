#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string *eme = new string[n];
    string *qh = new string[m];
    bool *emeqh = new bool[n]{0};
    for (int i = 0; i < n; i++)
    {
        cin >> eme[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> qh[i];
    }
    sort(eme, eme + n);
    sort(qh, qh + m);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int r = m - 1;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (eme[i] == qh[mid])
            {
                emeqh[i] = true;
                count++;
                break;
            }
            else if (eme[i] < qh[mid])
            {
                r = mid - 1;
            }
            else if (eme[i] > qh[mid])
            {
                l = mid + 1;
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; i++)
    {
        if (emeqh[i] == true)
            cout << eme[i] << endl;
    }
}