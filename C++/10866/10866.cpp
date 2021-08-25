#include <iostream>
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
            cout << "-1" << endl;
        }
        else
        {
            df1->last->last->first = df1;
            df1->last = df1->last->last;

            cout << front << endl;
            size--;
        }
    }
    void push_back(int a, dl *d)
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
            d->last = db1;
            d->first = db1->first;
            db1->first->last = d;
            db1->first = d;
        }

        d->de = a;
        back = a;

        size++;
    }
    void pop_back()
    {
        back = db1->first->de;
        if (back == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            db1->first->first->last = db1;
            db1->first = db1->first->first;

            cout << back << endl;
            size--;
        }
    }
    void size2()
    {
        cout << size << endl;
    }
    void empty()
    {
        if (size == 0)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    void front2()
    {
        if (df1->last->de == 0)
            cout << "-1" << endl;
        else
            cout << df1->last->de << endl;
    }
    void back2()
    {
        if (db1->first->de == 0)
            cout << "-1" << endl;
        else
            cout << db1->first->de << endl;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dequ dee;

    for (int i = 0; i < n; i++)
    {
        dl *a = new dl();
        string s;
        cin >> s;

        if (s == "push_front")
        {
            int temp;
            cin >> temp;
            dee.push_front(temp, a);
        }
        else if (s == "pop_front")
        {
            dee.pop_front();
        }
        else if (s == "push_back")
        {
            int temp;
            cin >> temp;
            dee.push_back(temp, a);
        }
        else if (s == "pop_back")
        {
            dee.pop_back();
        }
        else if (s == "front")
        {
            dee.front2();
        }
        else if (s == "back")
        {
            dee.back2();
        }
        else if (s == "size")
        {
            dee.size2();
        }
        else if (s == "empty")
        {
            dee.empty();
        }
    }
}