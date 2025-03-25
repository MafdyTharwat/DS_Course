#include <iostream>
using namespace std;
class clsLinkedList 
{
private:
    struct Node
    {
        int Val;
        Node* Next;
    };
    Node* Head;
    Node* Tail;
    int length;
public:
    clsLinkedList()
    {
        Head = NULL;
        Tail = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return (Head == NULL);
    }

    void insertAtFirst(int element)
    {
        Node* newNode = new Node;
        newNode->Val = element;
        if (isEmpty())
        {
            Head = newNode;
            Tail = newNode;
            newNode->Next = NULL;
        }
        else
        {
            newNode->Next = Head;
            Head = newNode;
        }
        length++;
    }

    void insertAtEnd(int element)
    {
        Node* newNode = new Node;
        newNode->Val = element;
        if (isEmpty())
        {
            Head = newNode;
            Tail = newNode;
            newNode->Next = NULL;
        }
        else
        {
            Tail->Next = newNode;
            newNode->Next = NULL;
            Tail = newNode;
        }
        length++;
    }

    void insertAt(int pos, int element)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Invalid Position\n";
        }
        else
        {
            if (pos == 0)
            {
                insertAtFirst(element);
            }
            else if (pos == length)
            {
                insertAtEnd(element);
            }
            else
            {
                Node* newNode = new Node;
                newNode->Val = element;
                Node* Current = Head;
                while (pos > 1)
                {
                    Current = Current->Next;
                    pos--;
                }
                newNode->Next = Current->Next;
                Current->Next = newNode;
                length++;
            }
        }
    }

    void removeHead()
    {
        if (isEmpty())
        {
            cout << "Can't remove from empty list\n";
        }
        else if (length == 1)
        {
            delete Head;
            Head = Tail = NULL;
            length--;
        }
        else
        {
            Node* Current = Head;
            Head = Head->Next;
            delete Current;
            length--;
        }
    }

    void removeTail()
    {
        if (isEmpty())
        {
            cout << "Can't remove from empty list\n";
        }
        else if (length == 1)
        {
            delete Tail;
            Head = Tail = NULL;
            length--;
        }
        else
        {
            Node* Current = Head->Next;
            Node* Prev = Head;
            while (Current != Tail)
            {
                Prev = Current;
                Current = Current->Next;
            }
            delete Current;
            Prev->Next = NULL;
            Tail = Prev;
            length--;
        }
    }

    void remove(int element)
    {
        if (isEmpty())
        {
            cout << "Can't remove from empty list\n";
        }
        else
        {
            Node* Current;
            Node* Prev;
            if (Head->Val == element)
            {
                Current = Head;
                Head = Head->Next;
                delete Current;
                length--;
                if (isEmpty())
                {
                    Tail = NULL;
                }
            }
            else
            {
                Current = Head->Next;
                Prev = Head;
                while (Current->Val != element && Current != NULL)
                {
                    Prev = Current;
                    Current = Current->Next;
                }
                if (Current == NULL)
                {
                    cout << "Can't find element: " << element << "in this list\n";
                }
                else
                {
                    if (Current == Tail)
                    {
                        removeTail();
                    }
                    else
                    {
                        Prev->Next = Current->Next;
                        delete Current;
                        length--;
                    }
                }
            }
        }
    }

    void removeAt(int pos)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Invalid Position\n";
        }
        else
        {
            if (pos == 0)
            {
                removeHead();
            }
            else if (pos == length)
            {
                removeTail();
            }
            else
            {
                Node* Current = Head->Next;
                Node* Prev = Head;
                while (pos > 1)
                {
                    Prev = Current;
                    Current = Current->Next;
                    pos--;
                }
                if (Current == Tail)
                {
                    removeTail();
                }
                else
                {
                    Prev->Next = Current->Next;
                    delete Current;
                    length--;
                }
            }
        }
    }

    void print()
    {
        Node* Temp = Head;
        while (Temp != NULL)
        {
            cout << Temp->Val << " ";
            Temp = Temp->Next;
        }
        cout << "\n";
        delete Temp;
    }
};
int main()
{
    clsLinkedList l;
    l.insertAtFirst(10);
    l.insertAtEnd(30);
    l.insertAtEnd(40);
    l.insertAt(1, 20);
    l.insertAtFirst(0);
    l.insertAtEnd(50);
    l.removeHead();
    l.removeTail();
    l.remove(20);
    l.removeAt(1);
    l.print();

    system("pause");
}