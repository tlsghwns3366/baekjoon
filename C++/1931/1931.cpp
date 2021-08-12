#include <iostream>
#include <algorithm>
using namespace std;
class Gr
{
public:
    int st;
    int lt;
};
int cmp2(Gr a, Gr b)
{
    if (a.lt == b.lt)
        return a.st < b.st;
    else
        return a.lt < b.lt;
}
int main()
{
    int n;
    cin >> n;
    Gr *gr = new Gr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> gr[i].st >> gr[i].lt;
    }
    sort(gr, gr + n, cmp2);
    int count = 1;
    int ltm = gr[0].lt;
    for (int i = 1; i < n; i++)
    {
        if (ltm <= gr[i].st)
        {
            ltm = gr[i].lt;
            count++;
        }
    }
    cout << count;
}