#include <iostream>
#include <string.h>
using namespace std;
class Party {
   int n;
   int* nb;
   bool r;
public:
   void nbset() {
      r = false;
      cin >> n;
      nb = new int[n];
      for (int i = 0; i < n; i++)
      {
         int k;
         cin >> k;
         nb[i] = k;
      }
   }
   bool nbtest(int* s1,int *s) {
      int c = 0;
      for (int i = 0; i < n; i++)
      {
          if(nb[i]==0)
            {
                c++;
                continue;
            }
         for (int j = 0; j < *s; j++)
         {
            if (nb[i] == s1[j] && nb[i] != 0)
            {
                r = true;
                c++;
                nb[i] = 0;
            }
         }
      }
      if (n != c && c != 0)
      {
          ner(s1, s, (n - c));
          return true;
      }
      else
      {
          return false;
      }
   }
   void ner(int* s1, int* s, int nc) 
   {
      int* s2 = new int[*s+nc];
      memset(s2, 0, sizeof(int) * (*s + nc));
      for(int i = 0; i<*s; i++)
      {
          s2[i] = s1[i];
      }
      *s=*s+nc;
      for(int i =0; i<*s;i++)
      {
          if(s2[i]==0)
          {
              for(int j =0; j< n;j++)
              {
                  if(nb[j] != 0)
                    s2[i] = nb[j];
              }
          }
      }
      for(int i=0;i<*s;i++)
      {
          s1[i]=s2[i];
      }
   }
   bool ret() {
      return r;
   }
};
int main()
{
   int n, m;
   cin >> n >> m;
   int s;
   cin >> s;
   int s1[50];
   int c = m;
   Party* p = new Party[m]{};
   if (s == 0)
   {
      c = m;
   }
   else
   {
      for (int i = 0; i < s; i++)
      {
         cin >> s1[i];
      }
   }
   for (int i = 0; i < m; i++)
   {
      p[i].nbset();
   }
   for (int i = 0; i < m; i++)
   {
      if (p[i].nbtest(s1, &s) == true)
      {
         i = -1;
      }
   }
   for (int i = 0; i < m; i++)
   {
      if (p[i].ret() == true)
      {
         c--;
      }
   }
   cout << c;
}