#include <iostream>
#include <algorithm>
using namespace std;
int c;

class No
{
public:
    int a;
    int b;
};
void DFS(bool *visi, No *no, int v, int m)
{
    if (visi[v])
        return;
    visi[v] = true;
    if (v != 1)
        c++;
    for (int i = 0; i < m; i++)
    {
        if (no[i].a == v && visi[no[i].b] == false)
        {
            DFS(visi, no, no[i].b, m);
        }
        else if (no[i].b == v && visi[no[i].a] == false)
        {
            DFS(visi, no, no[i].a, m);
        }
    }
}
bool cmp(No a, No b)
{
    if (a.a == b.b)
        return a.b < b.b;
    else
        return a.a < b.a;
}
int main()
{
    int n, m;
    cin >> n >> m;
    bool nn[n+1];
    fill(nn, nn + n+1, false);
    No mm[m];
    for (int i = 0; i < m; i++)
    {
        cin >> mm[i].a >> mm[i].b;
    }
    sort(mm, mm + m, cmp);
    DFS(nn, mm, 1, m);
    cout << c;
}