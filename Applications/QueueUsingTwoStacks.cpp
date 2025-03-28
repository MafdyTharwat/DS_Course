#include <iostream>
#include <stack>
using namespace std;
class QueueUsing2Stacks
{
private:
    stack<int> s1;  
    stack<int> s2;  

public:
    void enqueue(int item) 
    {
        s1.push(item);
        cout << "Enqueued: " << item << endl;
    }

    int dequeue()
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        while (!s1.empty()) 
        {
            s2.push(s1.top());
            s1.pop();
        }

        int front = s2.top();
        s2.pop();
        cout << "Dequeued: " << front << endl;
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return front;
    }

    bool isEmpty()
    {
        return s1.empty();
    }

    void display()
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        stack<int> temp;
        while (!s1.empty())
        {
            temp.push(s1.top());
            s1.pop();
        }
        while (!temp.empty()) 
        {
            cout << temp.top() << " ";
            s1.push(temp.top());
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    QueueUsing2Stacks q;
    int choice, item;

    cout << "Queue Implementation Using Two Stacks\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";

    while (true) 
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter item to enqueue: ";
            cin >> item;
            q.enqueue(item);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}