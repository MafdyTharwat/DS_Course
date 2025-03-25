#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
    int count;
    int front;
    int rear;
    int MaxSize;
    T* ArrQueue;
public:
    Queue(int Size)
    {
        if (Size <= 0)
            Size = 100;

        MaxSize = Size;
        ArrQueue = new T[MaxSize];
        count = 0;
        front = -1;
        rear = MaxSize - 1;
    }

    void Enqueue(T element)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
        }
        else
        {
            count++;
            rear = (rear + 1) % MaxSize;
            ArrQueue[rear] = element;
        }
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            count--;
            front = (front + 1) % MaxSize;
        }
    }

    T getFront()
    {
        if(!isEmpty())
            return ArrQueue[front];
    }

    T getRear()
    {
        if (!isEmpty())
            return ArrQueue[rear];
    }

    bool isFull()
    {
        return count == MaxSize;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int Find(T element)
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            for (int i = front + 1; i != rear; i = (i + 1) % MaxSize)
            {
                if (element == ArrQueue[i])
                    return i;
            }
            if (element == ArrQueue[rear])
                return rear;
            else
                return -1;
        }
    }

    void print()
    {
        for (int i = front+1; i != rear; i = (i + 1) % MaxSize)
        {
            cout << ArrQueue[i] << " ";
        }
        cout << ArrQueue[rear] << endl;
    }
};
int main()
{
    Queue<int> Q(5);
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);
    /*Q.print();

    Q.Dequeue();
    cout << "After Dequeue:\n";
    Q.print();

    Q.Enqueue(10);
    cout << "After Enqueue:\n";
    Q.print();

    Q.Dequeue();
    cout << "After Dequeue:\n";
    Q.print();

    if (Q.Find(3) == -1)
        cout << "3 doesn't found\n";
    else
    {
        cout << "3 was found at index: ";
        cout << Q.Find(3) << endl;
    }*/
    Q.Dequeue();
    Q.Enqueue(120);
    Q.print();
    if (Q.Find(120) == -1)
        cout << "120 wasn't found\n";
    else
    {
        cout << "120 was found at index: ";
        cout << Q.Find(120) << endl;
    }

    system("pause");
}
