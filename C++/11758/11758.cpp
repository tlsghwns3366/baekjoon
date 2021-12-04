#include <iostream>
using namespace std;
struct P
{
    int x;
    int y;
};

int main()
{
    P p[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    P p1,p2;
    p1.x = p[1].x-p[0].x;
    p1.y = p[1].y-p[0].y;
    p2.x = p[2].x-p[1].x;
    p2.y = p[2].y-p[1].y;
    int temp = p1.x * p2.y - p1.y*p2.x;
    if(temp > 0)
        cout<<1;
    else if(temp == 0)
        cout<<0;
    else
        cout<<-1;
}