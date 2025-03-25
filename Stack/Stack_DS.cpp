#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
template <class T>
class stack
{
    int top;
    T item[MAX_SIZE];

public:
    stack()
    {
        top = -1;
    }
    void push(T element)
    {
        if (top >= MAX_SIZE - 1)
            cout << "ERROR!\n";
        else
            item[++top] = element;
    }
    bool isEmpty()
    {
        return top < 0;
    }
    void pop()
    {
        if (!isEmpty())
            top--;
        else
            cout << "Can't pop\n";

    }
    void pop(T& element)
    {
        if (!isEmpty())
        {
            element = item[top];
            top--;
        }
        else
            cout << "Can't pop\n";
    }
    void getTop()
    {
        if (isEmpty())
            cout << "Can't get top\n";
        else
        {
            int stackTop = item[top];
            cout << stackTop << endl;
        }
    }
    void print()
    {
        cout << "[";
        for (int i = top; i > 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << "]\n";
    }
};
int main()
{
    stack<int> S;
    S.push(5);
    S.push(10);
    S.push(15);
    S.push(20);
    S.push(25);
    S.pop();
    S.push(7);
    S.print();
}