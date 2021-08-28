#include <iostream>
#include <string>
using namespace std;

class dl
{
public:
    dl *first;
    int de;
    dl *last;
    dl()
    {
        first = NULL;
        last = NULL;
        de = 0;
    }
};
class dequ
{
public:
    int size;
    int front;
    int back;
    dl *df1;
    dl *db1;

    dequ()
    {
        size = 0;
        front = 0;
        back = 0;
        df1 = new dl();
        db1 = new dl();
        df1->last = db1;
        db1->first = df1;
    }
    void push_front(int a, dl *d)
    {
        if (size == 0)
        {
            d->first = df1;
            d->last = db1;
            df1->last = d;
            db1->first = d;
        }
        else
        {
            d->first = df1;
            d->last = df1->last;
            df1->last->first = d;
            df1->last = d;
        }
        d->de = a;
        front = a;

        size++;
    }
    void pop_front()
    {
        front = df1->last->de;
        if (front == 0)
        {
        }
        else
        {
            df1->last->last->first = df1;
            df1->last = df1->last->last;

            size--;
        }
    }
    void pop_back()
    {
        back = db1->first->de;
        if (back == 0)
        {
        }
        else
        {
            db1->first->first->last = db1;
            db1->first = db1->first->first;

            size--;
        }
    }
    int size2()
    {
        return size;
    }

    void front2()
    {
        if (df1->last->de == 0)
            cout << "-1" << endl;
        else
            cout << df1->last->de;
    }
    void back2()
    {
        if (db1->first->de == 0)
            cout << "-1" << endl;
        else
            cout << db1->first->de;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string x;
        cin >> x;

        string *xn;
        if (n != 0)
            xn = new string[n]{""};
        int temp = 0;
        for (int j = 0; j < x.length(); j++)
        {
            if (x[j] >= '0' && x[j] <= '9')
            {
                xn[temp] += x[j];
            }
            else if (x[j] == ',')
            {
                temp++;
            }
        }

        dequ dee;
        for (int j = 0; j < n; j++)
        {
            dl *a = new dl();
            dee.push_front(stoi(xn[j]), a);
        }

        bool b = false;
        int count = 0;
        string temp2 = "";
        for (int j = 0; j < p.length(); j++)
        {
            if (p[j] == 'R')
            {
                b = !b;
            }
            else if (p[j] == 'D')
            {
                count++;
                if (dee.size2() > 0)
                {
                    if (b)
                        dee.pop_front();
                    else
                        dee.pop_back();
                }
            }
        }

        int temp3 = dee.size2();
        if (count <= n)
        {
            cout << "[";
            for (int j = 0; j < temp3; j++)
            {
                if (b)
                {
                    dee.front2();
                    dee.pop_front();
                }
                else
                {
                    dee.back2();
                    dee.pop_back();
                }
                if (j < temp3 - 1)
                {
                    cout << ",";
                }
            }
            cout << "]\n";
        }
        else
            cout << "error\n";
    }
}