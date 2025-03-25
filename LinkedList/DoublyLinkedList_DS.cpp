#include <iostream>
using namespace std;
class clsDoublyList
{
private:
    struct Node
    {
        int Val;
        Node* Next;
        Node* Prev;
    };
    Node* Head;
    Node* Tail;
    int length;

public:
    clsDoublyList()
    {
        length = 0;
        Head = Tail = NULL;
    }

    bool isEmpty()
    {
        return (Head == NULL);
    }

    void insertAtFirst(int element)
    {
        Node* newNode = new Node;
        newNode->Val = element;
        newNode->Prev = NULL;
        if (isEmpty())
        {
            Head = newNode;
            newNode->Next = NULL;
            Tail = newNode;
        }
        else
        {
            newNode->Next = Head;
            Head->Prev = newNode;
            Head = newNode;
        }
        length++;
    }

    void insertAtEnd(int element)
    {
        Node* newNode = new Node;
        newNode->Val = element;
        newNode->Next = NULL;
        if (isEmpty())
        {
            Head = newNode;
            newNode->Prev = NULL;
            Tail = newNode;
        }
        else
        {
            newNode->Prev = Tail;
            Tail->Next = newNode;
            Tail = newNode;
        }
        length++;
    }

    void insertAt(int Pos, int element)
    {
        if (Pos < 0 || Pos > length)
        {
            cout << "Invalid Position\n";
        }
        else if (Pos == 0)
        {
            insertAtFirst(element);
        }
        else if (Pos == length)
        {
            insertAtEnd(element);
        }
        else
        {
            Node* newNode = new Node;
            newNode->Val = element;
            Node* Current = Head->Next;
            while (Pos > 1)
            {
                Current = Current->Next;
                Pos--;
            }
            newNode->Next = Current->Next;
            newNode->Prev = Current;
            Current->Next->Prev = newNode;
            Current->Next = newNode;
            length++;
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
            Node* Temp = Head;
            Head = Head->Next;
            Head->Prev = NULL;
            delete Temp;
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
            Node* Temp = Tail;
            Tail = Tail->Prev;
            Tail->Next = NULL;
            delete Temp;
            length--;
        }
    }

    void removeAt(int pos)
    {
        if (pos < 0 || pos >= length)
        {
            cout << "Out Of Range" << endl;
            return;
        }
        else if (pos == 0)
        {
            removeHead();
        }
        else if (pos == length - 1)
        {
            removeTail();
        }
        else {
            Node* current = Head->Next;


            for (int i = 1; i < pos; i++)
            {
                current = current->Next;
            }
            current->Prev->Next = current->Next;
            current->Next->Prev = current->Prev;
            delete current;
        }
        length--;
    }

    void remove(int element)
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Remove ";
            return;
        }
        Node* current = Head->Next;

        if (Head->Val == element)
        {
            removeHead();
            return;
        }
        else
        {
            while (current != NULL)
            {
                if (current->Val == element)
                    break;
                current = current->Next;
            }

            if (current == NULL) 
            {
                cout << "The item is not there\n";
                return;
            }
            else if (current->Next == NULL)
            {
                removeTail();
                return;
            }

            else
            {
                current->Prev->Next = current->Next;
                current->Next->Prev = current->Prev;
                delete current;
                length--;
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

    void reversedDisplay()
    {
        Node* Temp = Tail;
        while (Temp != NULL)
        {
            cout << Temp->Val << " ";
            Temp = Temp->Prev;
        }
        cout << "\n";
        delete Temp;
    }


    ~clsDoublyList()
    {
        Node* temp;
        while (Head != NULL)
        {
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
        Tail = NULL;
        length = 0;
    }
};
int main()
{
    clsDoublyList dl;
    dl.insertAt(0,10);
    dl.insertAt(1, 20);
    dl.insertAt(2, 30);
    dl.insertAt(3, 40);
    dl.insertAt(4, 50);

    dl.insertAtFirst(0);
    dl.insertAtEnd(60);

    dl.removeHead();
    dl.removeTail();

    dl.removeAt(4);

    dl.remove(10);
    cout << "Linked List Elements...\n";
    dl.print();
    cout << "\nReversed Linked List Elements...\n";
    dl.reversedDisplay();

    system("pause");
}