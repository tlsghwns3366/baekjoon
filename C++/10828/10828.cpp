#include <iostream>
#include <string>
using namespace std;
class Stack
{
    int *stack;
    int p;

public:
    Stack()
    {
        stack = new int[10001];
        p = 0;
    }
    void push(int n)
    {
        stack[p] = n;
        p++;
    }
    int pop()
    {
        if (p != 0)
        {
            p--;
            return stack[p];
        }
        else
            return -1;
    }
    int size()
    {
        return p;
    }
    int empty()
    {
        if (p == 0)
            return 1;
        else
            return 0;
    }
    int top()
    {
        if (p != 0)
            return stack[p - 1];
        else
            return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    Stack stack = Stack();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int c;
            scanf("%d",&c);
            stack.push(c);
        }
        else if (str == "pop")
        {
            printf("%d\n",stack.pop());
        }
        else if (str == "size")
        {
            printf("%d\n",stack.size());
        }
        else if (str == "empty")
        {
            printf("%d\n",stack.empty());
        }
        else if (str == "top")
        {
            printf("%d\n",stack.top());
        }
    }
}
