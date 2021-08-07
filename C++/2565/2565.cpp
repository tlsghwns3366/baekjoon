#include <iostream>
using namespace std;

int main()
{
   int n;
   cin >> n;
   int *a = new int[500]{0};
   int *b = new int[500]{0};
   for (int i = 0; i < n; i++)
   {
      int temp = 0;
      cin >> temp;
      cin >> a[temp - 1];
   }
   int sum = 0;
   for (int i = 0; i < 500; i++)
   {
      if (a[i] != 0)
      {
         b[i] = 1;
         for (int j = 0; j < i; j++)
         {
            if (a[j] < a[i] && b[i] < b[j] +1)
            {
               b[i] = b[j] + 1;
            }
         }
         if (b[i] > sum)
            sum = b[i];
      }
   }
   cout << n - sum;
}