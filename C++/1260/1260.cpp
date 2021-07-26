#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
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
    cout << v << " ";
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

void BFS(bool *visi, No *no, int v, int m)
{
    visi[v] = true;
    cout << v << " ";
    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        int j = q.front();
        q.pop();
        for (int i = 0; i < m; i++)
        {
            if (no[i].a == j && visi[no[i].b] == false)
            {
                q.push(no[i].b);
                visi[no[i].b] = true;
                cout << no[i].b << " ";
            }
            else if (no[i].b == j && visi[no[i].a] == false)
            {
                q.push(no[i].a);
                visi[no[i].a] = true;
                cout << no[i].a << " ";
            }
        }
    }
}
bool compare(No a, No b)
{
    if (a.a == b.a)
    {
        return a.b < b.b;
    }
    else
    {
        return a.a < b.a;
    }
}
int main()
{
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    bool *visi = new bool[n + 1];
    No *no = new No[m];
    for (int i = 0; i < n + 1; i++)
    {
        visi[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < b)
        {
            no[i].a = a;
            no[i].b = b;
        }
        else
        {
            no[i].a = b;
            no[i].b = a;
        }
    }
    sort(no, no + m, compare);
    DFS(visi, no, v, m);
    for (int i = 0; i < n + 1; i++)
    {
        visi[i] = false;
    }
    cout << endl;
    BFS(visi, no, v, m);
}