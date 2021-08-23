#include <iostream>
using namespace std;
class Qu
{
    int *q;
    int f;
    int b;
    int count;

public:
    Qu()
    {
        q = new int[2000001]{0};
        f = 0;
        b = 0;
        count = 0;
    }
    void push(int x)
    {
        if (q[b] == 0)
        {
            if (b <= 2000000)
            {
                q[b] = x;
                b++;
                count++;
            }
            else
            {
                b = 0;
                q[b] = x;
                count++;
            }
        }
    }
    void pop()
    {
        if (q[f] == 0)
        {
            cout << "-1"
                 << "\n";
        }
        else if (f <= 2000000)
        {
            cout << q[f] << "\n";
            q[f] = 0;
            f++;
            count--;
        }
        else
        {
            f = 0;
            cout << q[f] << "\n";
            q[f] = 0;
            count--;
        }
    }
    int size()
    {
        return count;
    }
    int empty()
    {
        if (count != 0)
            return 0;
        else
            return 1;
    }
    int front()
    {
        if (q[f] != 0)
            return q[f];
        else
            return -1;
    }
    int back()
    {
        if (q[b - 1] != 0 && b != 0)
            return q[b - 1];
        else
            return -1;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Qu qu;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "push")
        {
            int temp;
            cin >> temp;
            qu.push(temp);
        }
        else if (a == "pop")
        {
            qu.pop();
        }
        else if (a == "size")
        {
            cout << qu.size() << "\n";
        }
        else if (a == "empty")
        {
            cout << qu.empty() << "\n";
        }
        else if (a == "front")
        {
            cout << qu.front() << "\n";
        }
        else if (a == "back")
        {
            cout << qu.back() << "\n";
        }
    }
}