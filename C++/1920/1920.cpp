#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    a = b;
    *b = temp;
}
int partition(int *list, int left, int right)
{
    int pivot;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do
    {
        do
        {
            low++;
        } while (low <= right && list[low] < pivot);
        do
        {
            high--;
        } while (high >= left && list[high] > pivot);
        if (low < high)
            swap(list[high], list[low]);
    } while (low < high);
    swap(list[left], list[high]);
    return high;
}
void quick(int *list, int left, int right)
{

    if (left < right)
    {
        int q = partition(list, left, right);
        quick(list, left, q - 1);
        quick(list, q + 1, right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *A = new int[n];

    for (int i = 0; i < n; i++)
    {
    scanf("%d", &A[i]);
    }
    int m;
    scanf("%d", &m);
    quick(A, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int B; 
        scanf("%d", &B);
        int c = 0;
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (B == A[mid])
            {
                c = 1;
                break;
            }
            else if (B < A[mid])
            {
                r = mid - 1;
            }
            else if (B > A[mid])
            {
                l = mid + 1;
            }
        }
        printf("%d\n", c);
    }
}