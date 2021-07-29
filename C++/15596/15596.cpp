#include <vector>
long long sum(std::vector<int> &a)
{
    long long b = 0;
    for (int i = 0; i < a.size(); i++)
    {
        b += a[i];
    }
    return b;
}