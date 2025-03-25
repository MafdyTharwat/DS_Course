#include <iostream>
using namespace std;
class clsQueue
{
private:
    struct Node
    {
        int Val;
        Node* Next;
    };
    Node* frontPtr;
    Node* rearPtr;
    int length;

public:
    clsQueue()
    {
        frontPtr = NULL;
        rearPtr = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return (length == 0);
    }

    void Enqueue(int element)
    {
        if (isEmpty())
        {
            frontPtr = new Node;
            frontPtr->Val = element;
            frontPtr->Next = NULL;
            rearPtr = frontPtr;
            length++;
        }
        else
        {
            Node* newPtr = new Node;
            newPtr->Val = element;
            newPtr->Next = NULL;
            rearPtr->Next = newPtr;
            rearPtr = newPtr;
            length++;
        }
    }

    void Dequeue()
    {
        if (isEmpty())
            cout << "Cannot dequeue\n";
        else
        {
            Node* tempPtr;
            tempPtr = frontPtr;
            if (frontPtr == rearPtr)
            {
                frontPtr = NULL;
                rearPtr = NULL;
                length--;
            }
            else
            {
                frontPtr = frontPtr->Next;
                tempPtr->Next = NULL;
                length--;
                delete tempPtr;
            }
        }
    }

    int getFront()
    {
        return (isEmpty()) ? -1 : frontPtr->Val;
    }

    int getRear()
    {
        return (isEmpty())? -1 : rearPtr->Val;
    }

    void getFront(int& front)
    {
        if (isEmpty())
            front = -1;
        else
            front = frontPtr->Val;
    }

    void getRear(int& rear)
    {
        if (isEmpty())
            rear = -1;
        else
            rear = rearPtr->Val;
    }

    void Clear()
    {
        Node* Current;
        while (frontPtr != NULL)
        {
            Current = frontPtr;
            frontPtr = frontPtr->Next;
            delete Current;
            length--;
        }
        rearPtr = NULL;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty\n";
        }
        else
        {
            Node* Temp = frontPtr;
            while (Temp != NULL)
            {
                cout << Temp->Val << "  ";
                Temp = Temp->Next;
            }
            cout << "\n";
        }
    }
};
int main()
{
    clsQueue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    cout << "Queue after enqueue:\n";
    Q.Display();

    Q.Dequeue();
    cout << "Queue after dequeue one element:\n";
    Q.Display();

    cout << "Front of queue is " << Q.getFront() << endl;

    cout << "Rear of queue is " << Q.getRear() << endl;

    Q.Clear();
    cout << Q.isEmpty() << endl;

    system("pause");
}