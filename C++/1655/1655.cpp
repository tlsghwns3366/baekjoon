#include <iostream>
using namespace std;
int sizea = 1;
int sizeb = 1;
void mfpush(int x, int *mn)
{
    mn[sizea] = x;
    int a = sizea;
    int b = sizea / 2;
    while (a > 1 && mn[b] < mn[a])
    {
        int temp = mn[b];
        mn[b] = mn[a];
        mn[a] = temp;
        a = b;
        b = a / 2;
    }
    sizea++;
}
int mfpop(int *mn)
{
    int x = mn[1];
    mn[1] = mn[sizea - 1];
    mn[sizea - 1] = 0;
    if (sizea > 1)
        sizea--;
    int a = 1;
    int b = a * 2;

    if (mn[b] < mn[b + 1])
        b = b + 1;
    while (b < sizea && mn[b] > mn[a])
    {
        int temp = mn[b];
        mn[b] = mn[a];
        mn[a] = temp;
        a = b;
        b = a * 2;
        if (mn[b] < mn[b + 1])
            b = b + 1;
    }
    return x;
}
void nfpush(int x, int *nn)
{
    nn[sizeb] = x;
    int a = sizeb;
    int b = sizeb / 2;

    while (a > 1 && nn[b] > nn[a])
    {
        int temp = nn[b];
        nn[b] = nn[a];
        nn[a] = temp;
        a = b;
        b = a / 2;
    }
    sizeb++;
}
int nfpop(int *nn)
{
    int x = nn[1];
    nn[1] = nn[sizeb - 1];
    nn[sizeb - 1] = 0;
    if (sizeb > 1)
        sizeb--;
    int a = 1;
    int b = a * 2;

    if (b + 1 < sizeb && nn[b] > nn[b + 1])
        b = b + 1;

    while (b < sizeb && nn[b] < nn[a])
    {
        int temp = nn[b];
        nn[b] = nn[a];
        nn[a] = temp;
        a = b;
        b = a * 2;
        if (b + 1 < sizeb && nn[b] > nn[b + 1])
            b = b + 1;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int mn[n + 2];
    fill(mn, mn + n + 2, 0);
    int nn[n + 2];
    fill(nn, nn + n + 2, 0);
    int center = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a; /* 
        if (a == 0)
        {
            mfpop(mn);
        }
        else
        {
            mfpush(a, mn);
        }

        for (int j = 1; j < sizea; j++)
        {
            cout << mn[j] << " ";
        }
        cout << endl
             << "-----------" << endl;
 */
        if (i > 0)
        {
            if (center < a)
            {
                nfpush(a, nn);
                if ((sizea + sizeb - 2) % 2 == 0)
                {
                    mfpush(center, mn);
                    center = nfpop(nn);
                }
                else
                {
                    nfpush(center, nn);
                    center = nfpop(nn);
                }
                cout << center << "\n";
            }
            else
            {
                mfpush(a, mn);
                if ((sizea + sizeb - 2) % 2 == 1)
                {
                    nfpush(center, nn);
                    center = mfpop(mn);
                }

                cout << center << "\n";
            }
        }
        else
        {
            center = a;
            cout << center << "\n";
        }
    }
}