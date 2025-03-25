#include <iostream>
using namespace std;
template <class T>
class stack
{
private:

    struct Node
    {
        T item;
        Node* Next;
    };

    Node* Top;

    Node* Current;

public:

    stack()
    {
        Top = NULL;
    }

    void push(T newItem)
    {
        Node* newItemPtr = new Node;
        if (newItemPtr == NULL)
        {
            cout << "Stack push cannot allocate memory\n";
        }
        else
        {
            newItemPtr->item = newItem;
            newItemPtr->Next = Top;
            Top = newItemPtr;
        }
    }

    bool isEmpty()
    {
        return (Top == NULL);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Cannot pop from this stack\n";
        }
        else
        {
            Node* Temp = new Node;
            Temp = Top;
            Top = Top->Next;
            Temp->Next = NULL;
            delete Temp;
        }
    }

    void pop(T& stackTop)
    {
        if (isEmpty())
        {
            cout << "Cannot pop from this stack\n";
        }
        else
        {
            stackTop = Top->item;
            Node* Temp = new Node;
            Temp = Top;
            Top = Top->Next;
            Temp->Next = NULL;
            delete Temp;
        }
    }

    void getTop(T& stackTop)
    {
        if (isEmpty())
            cout << "Cannot pop from this stack\n";
        else
            stackTop = Top->item;
    }

    void displayElements()
    {
        Current = Top;
        while (Current != NULL)
        {
            cout << Current->item << " ";
            Current = Current->Next;
        }
        cout << endl;
    }
};
int main()
{
    stack<int> S;
    S.push(100);
    S.push(90);
    S.push(80);
    S.push(70);
    S.push(60);
    S.push(50);
    S.push(40);
    S.push(30);
    S.push(20);
    S.push(10);
    S.displayElements();
    S.pop();
    S.displayElements();
}