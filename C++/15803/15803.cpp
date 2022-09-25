#include <iostream>
using namespace std;
int main()
{
    double x1, x2, x3;
    double y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
        cout << "WHERE IS MY CHICKEN?";
    else if ((double)((x1 - x2) / (y1 - y2)) == (double)((x2 - x3) / (y2 - y3)))
        cout << "WHERE IS MY CHICKEN?";
    else
        cout << "WINNER WINNER CHICKEN DINNER!";
}