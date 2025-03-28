#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>
using namespace std;
void clearInput() 
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
template <typename T>
struct Node 
{
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

struct sqNode
{
    int data;
    sqNode* next;
};

class SinglyLinkedList 
{
private:
    Node<int>* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    void insertAtEnd(int value)
    {
        Node<int>* newNode = new Node<int>(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node<int>* temp = head;
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
        cout << value << " inserted at end.\n";
    }

    void deleteFromEnd() 
    {
        if (!head)
        {
            cout << "List is empty!\n";
            return;
        }

        if (!head->next) 
        {
            cout << head->data << " deleted.\n";
            delete head;
            head = nullptr;
        }
        else
        {
            Node<int>* temp = head;
            while (temp->next->next)
            {
                temp = temp->next;
            }
            cout << temp->next->data << " deleted.\n";
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    void display() 
    {
        if (!head) 
        {
            cout << "List is empty!\n";
            return;
        }
        cout << "List elements: ";
        Node<int>* temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nSize: " << size << endl;
    }

    ~SinglyLinkedList()
    {
        Node<int>* temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class DoublyLinkedList 
{
private:
    Node<int>* head;
    Node<int>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertAtEnd(int value)
    {
        Node<int>* newNode = new Node<int>(value);
        if (!head) 
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        cout << value << " inserted at end.\n";
    }

    void deleteFromEnd()
    {
        if (!head) 
        {
            cout << "List is empty!\n";
            return;
        }

        cout << tail->data << " deleted.\n";
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else 
        {
            Node<int>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }

    void displayForward()
    {
        if (!head) 
        {
            cout << "List is empty!\n";
            return;
        }
        cout << "List elements (forward): ";
        Node<int>* temp = head;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nSize: " << size << endl;
    }

    void displayBackward()
    {
        if (!tail)
        {
            cout << "List is empty!\n";
            return;
        }
        cout << "List elements (backward): ";
        Node<int>* temp = tail;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\nSize: " << size << endl;
    }

    ~DoublyLinkedList()
    {
        Node<int>* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class CircularSinglyLinkedList
{
private:
    Node<int>* tail;
    int size;

public:
    CircularSinglyLinkedList() : tail(nullptr), size(0) {}

    void insertAtEnd(int value)
    {
        Node<int>* newNode = new Node<int>(value);
        if (!tail) 
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        cout << value << " inserted at end.\n";
    }

    void deleteFromEnd()
    {
        if (!tail)
        {
            cout << "List is empty!\n";
            return;
        }

        if (tail->next == tail) 
        {
            cout << tail->data << " deleted.\n";
            delete tail;
            tail = nullptr;
        }
        else {
            Node<int>* temp = tail;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = tail->next;
            cout << tail->data << " deleted.\n";
            delete tail;
            tail = temp;
        }
        size--;
    }

    void display() 
    {
        if (!tail) 
        {
            cout << "List is empty!\n";
            return;
        }
        cout << "List elements: ";
        Node<int>* temp = tail->next;
        do 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != tail->next);
        cout << "\nSize: " << size << endl;
    }

    ~CircularSinglyLinkedList()
    {
        if (!tail) return;

        Node<int>* current = tail->next;
        Node<int>* nextNode;
        tail->next = nullptr;

        while (current) 
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

class StackLinkedList 
{
private:
    Node<int>* top;
    int size;

public:
    StackLinkedList() : top(nullptr), size(0) {}

    void push(int value)
    {
        Node<int>* newNode = new Node<int>(value);
        newNode->next = top;
        top = newNode;
        size++;
        cout << value << " pushed to stack.\n";
    }

    int pop() 
    {
        if (!top) 
        {
            cout << "Stack underflow!\n";
            return -1;
        }
        Node<int>* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        size--;
        cout << value << " popped from stack.\n";
        return value;
    }

    void display()
    {
        if (!top) 
        {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node<int>* temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nSize: " << size << endl;
    }

    ~StackLinkedList()
    {
        Node<int>* temp;
        while (top) 
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
};

class QueueLinkedList 
{
private:
    Node<int>* front;
    Node<int>* rear;
    int size;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(int value)
    {
        Node<int>* newNode = new Node<int>(value);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << value << " enqueued.\n";
    }

    int dequeue()
    {
        if (!front) 
        {
            cout << "Queue underflow!\n";
            return -1;
        }
        Node<int>* temp = front;
        int value = temp->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        size--;
        cout << value << " dequeued.\n";
        return value;
    }

    void display() 
    {
        if (!front) 
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements (front to rear): ";
        Node<int>* temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nSize: " << size << endl;
    }

    ~QueueLinkedList()
    {
        Node<int>* temp;
        while (front)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};

class QueueUsingStacks
{
private:
    stack<int> s1, s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
        cout << "Enqueued: " << x << endl;
    }

    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        cout << "Dequeued: " << x << endl;

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return x;
    }

    void display() 
    {
        if (s1.empty()) 
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements (front to rear): ";
        stack<int> temp = s1;
        stack<int> temp2;

        while (!temp.empty())
        {
            temp2.push(temp.top());
            temp.pop();
        }

        while (!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix;

    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

string postfixToInfix(string postfix)
{
    stack<string> s;

    for (char c : postfix)
    {
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string temp = "(" + op1 + string(1, c) + op2 + ")";
            s.push(temp);
        }
    }

    return s.top();
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for (char& c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string postfix = infixToPostfix(infix);

    reverse(postfix.begin(), postfix.end());

    return postfix;
}

string prefixToInfix(string prefix)
{
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else if (isOperator(c))
        {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op1 + string(1, c) + op2 + ")";
            s.push(temp);
        }
    }

    return s.top();
}

void displayWelcome()
{
    cout << "\n====================================\n";
    cout << "Advanced Data Structures Program\n";
    cout << "Created by: Mafdy Tharwat\n";
    cout << "====================================\n";
    cout << "This program demonstrates various data structure implementations\n";
    cout << "including stacks, queues, and linked lists.\n";
    cout << "====================================\n";
}

void linkedListMenu()
{
    int choice;
    SinglyLinkedList sll;
    DoublyLinkedList dll;
    CircularSinglyLinkedList csll;
    StackLinkedList stll;
    QueueLinkedList qll;
    QueueUsingStacks qus;
    int item;

    do 
    {
        cout << "\nLinked List Operations Menu:\n";
        cout << "1. Single Linked List\n";
        cout << "2. Stack Using Linked List\n";
        cout << "3. Queue Using Linked List\n";
        cout << "4. Queue Using Two Stacks\n";
        cout << "5. Doubly Linked List\n";
        cout << "6. Circular Singly Linked List\n";
        cout << "7. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int subChoice;
            do 
            {
                cout << "\nSingle Linked List Menu:\n";
                cout << "1. Insert at End\n";
                cout << "2. Delete from End\n";
                cout << "3. Display List\n";
                cout << "4. Exit to Linked List Menu\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    cout << "Enter item to insert: ";
                    cin >> item;
                    sll.insertAtEnd(item);
                    break;
                case 2:
                    sll.deleteFromEnd();
                    break;
                case 3:
                    sll.display();
                    break;
                case 4:
                    cout << "Returning to Linked List menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (subChoice != 4);
            break;
        }
        case 2:
        {
            int subChoice;
            do
            {
                cout << "\nStack Using Linked List Menu:\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display Stack\n";
                cout << "4. Exit to Linked List Menu\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice) 
                {
                case 1:
                    cout << "Enter item to push: ";
                    cin >> item;
                    stll.push(item);
                    break;
                case 2:
                    stll.pop();
                    break;
                case 3:
                    stll.display();
                    break;
                case 4:
                    cout << "Returning to Linked List menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (subChoice != 4);
            break;
        }
        case 3: 
        {
            int subChoice;
            do
            {
                cout << "\nQueue Using Linked List Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display Queue\n";
                cout << "4. Exit to Linked List Menu\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    cout << "Enter item to enqueue: ";
                    cin >> item;
                    qll.enqueue(item);
                    break;
                case 2:
                    qll.dequeue();
                    break;
                case 3:
                    qll.display();
                    break;
                case 4:
                    cout << "Returning to Linked List menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (subChoice != 4);
            break;
        }
        case 4:
        {
            int subChoice;
            do
            {
                cout << "\nQueue Using Two Stacks Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display Queue\n";
                cout << "4. Exit to Linked List Menu\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    cout << "Enter item to enqueue: ";
                    cin >> item;
                    qus.enqueue(item);
                    break;
                case 2:
                    qus.dequeue();
                    break;
                case 3:
                    qus.display();
                    break;
                case 4:
                    cout << "Returning to Linked List menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (subChoice != 4);
            break;
        }
        case 5:
        {
            int subChoice;
            do
            {
                cout << "\nDoubly Linked List Menu:\n";
                cout << "1. Insert at End\n";
                cout << "2. Delete from End\n";
                cout << "3. Display Forward\n";
                cout << "4. Display Backward\n";
                cout << "5. Exit to Linked List Menu\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice) 
                {
                case 1:
                    cout << "Enter item to insert: ";
                    cin >> item;
                    dll.insertAtEnd(item);
                    break;
                case 2:
                    dll.deleteFromEnd();
                    break;
                case 3:
                    dll.displayForward();
                    break;
                case 4:
                    dll.displayBackward();
                    break;
                case 5:
                    cout << "Returning to Linked List menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (subChoice != 5);
            break;
        }
        case 6:
        {
            int subChoice;
            do
            {
                cout << "\nCircular Singly Linked List Menu:\n";
                cout << "1. Insert at End\n";
                cout << "2. Delete from End\n";
                cout << "3. Display List\n";
                cout << "4. Exit to Linked List Menu\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    cout << "Enter item to insert: ";
                    cin >> item;
                    csll.insertAtEnd(item);
                    break;
                case 2:
                    csll.deleteFromEnd();
                    break;
                case 3:
                    csll.display();
                    break;
                case 4:
                    cout << "Returning to Linked List menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (subChoice != 4);
            break;
        }
        case 7:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            clearInput();
        }
    } 
    while (choice != 7);
}

class StackArray
{
private:
    int* arr;
    int top;
    int capacity;
public:
    StackArray(int size = 100)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~StackArray()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow!\n";
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed to stack\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!\n";
            return -1;
        }
        top--;
        int x = arr[top];
        cout << x << " popped from stack\n";
        return x;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class StackPointer
{
private:
    sqNode* top;
public:
    StackPointer()
    {
        top = nullptr;
    }

    void push(int x)
    {
        sqNode* newNode = new sqNode();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed to stack\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!\n";
            return -1;
        }
        sqNode* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        cout << x << " popped from stack\n";
        return x;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        sqNode* current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class QueueArray
{
private:
    int* arr;
    int front, rear, capacity;
public:
    QueueArray(int size = 100)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~QueueArray()
    {
        delete[] arr;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow!\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        cout << x << " dequeued\n";
        return x;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

class QueuePointer
{
private:
    sqNode* front;
    sqNode* rear;
public:
    QueuePointer()
    {
        front = rear = nullptr;
    }

    void enqueue(int x)
    {
        sqNode* newNode = new sqNode();
        newNode->data = x;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " enqueued\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return -1;
        }
        sqNode* temp = front;
        int x = temp->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        cout << x << " dequeued\n";
        return x;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        sqNode* current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

class CircularQueue
{
private:
    int* arr;
    int front, rear, capacity;
public:
    CircularQueue(int size = 100)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        cout << x << " dequeued\n";
        return x;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

class DEQueue
{
private:
    int* arr;
    int front, rear, capacity;
public:
    DEQueue(int size = 100)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    ~DEQueue()
    {
        delete[] arr;
    }

    void enqueueFront(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = capacity - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        cout << x << " enqueued at front\n";
    }

    void enqueueRear(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        cout << x << " enqueued at rear\n";
    }

    int dequeueFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        cout << x << " dequeued from front\n";
        return x;
    }

    int dequeueRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = arr[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = capacity - 1;
        }
        else
        {
            rear--;
        }
        cout << x << " dequeued from rear\n";
        return x;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

class PriorityQueue
{
private:
    struct PQNode
    {
        int data;
        int priority;
        PQNode* next;
    };
    PQNode* front;
public:
    PriorityQueue()
    {
        front = nullptr;
    }

    void enqueue(int x, int p)
    {
        PQNode* newNode = new PQNode();
        newNode->data = x;
        newNode->priority = p;

        if (front == nullptr || p > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            PQNode* temp = front;
            while (temp->next != nullptr && temp->next->priority >= p)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << x << " enqueued with priority " << p << endl;
    }

    int dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        PQNode* temp = front;
        int x = temp->data;
        front = front->next;
        delete temp;
        cout << x << " dequeued\n";
        return x;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements : ";
        PQNode* current = front;
        while (current != nullptr)
        {
            cout << current->data << "(" << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

void stackApplicationsMenu()
{
    int choice;
    string expression;

    do
    {
        cout << "Stack Applications Menu:\n";
        cout << "1. Convert Infix to Postfix Expression\n";
        cout << "2. Convert Postfix to Infix Expression\n";
        cout << "3. Convert Infix to Prefix Expression\n";
        cout << "4. Convert Prefix to Infix Expression\n";
        cout << "5. Exit to Previous Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
            cout << "Enter infix expression: ";
            getline(cin, expression);
            cout << "Postfix expression: " << infixToPostfix(expression) << endl;
            break;
        case 2:
            cout << "Enter postfix expression: ";
            getline(cin, expression);
            cout << "Infix expression: " << postfixToInfix(expression) << endl;
            break;
        case 3:
            cout << "Enter infix expression: ";
            getline(cin, expression);
            cout << "Prefix expression: " << infixToPrefix(expression) << endl;
            break;
        case 4:
            cout << "Enter prefix expression: ";
            getline(cin, expression);
            cout << "Infix expression: " << prefixToInfix(expression) << endl;
            break;
        case 5:
            cout << "Returning to previous menu...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

void stackMenu()
{
    int choice;
    StackArray arrStack;
    StackPointer ptrStack;
    int item;

    do
    {
        cout << "Stack Operations Menu:\n";
        cout << "1. Stack Using Arrays\n";
        cout << "2. Stack Using Pointers\n";
        cout << "3. Stack Applications\n";
        cout << "4. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int stackChoice;
            do
            {
                cout << "Stack Using Array Menu:\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display\n";
                cout << "4. Exit to Stack Menu\n";
                cout << "Enter your choice: ";
                cin >> stackChoice;

                switch (stackChoice)
                {
                case 1:
                    cout << "Enter item to push: ";
                    cin >> item;
                    arrStack.push(item);
                    break;
                case 2:
                    arrStack.pop();
                    break;
                case 3:
                    arrStack.display();
                    break;
                case 4:
                    cout << "Returning to stack menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (stackChoice != 4);
            break;
        }
        case 2:
        {
            int stackChoice;
            do
            {
                cout << "Stack Using Pointers Menu:\n";
                cout << "1. Push\n";
                cout << "2. Pop\n";
                cout << "3. Display\n";
                cout << "4. Exit to Stack Menu\n";
                cout << "Enter your choice: ";
                cin >> stackChoice;

                switch (stackChoice)
                {
                case 1:
                    cout << "Enter item to push: ";
                    cin >> item;
                    ptrStack.push(item);
                    break;
                case 2:
                    ptrStack.pop();
                    break;
                case 3:
                    ptrStack.display();
                    break;
                case 4:
                    cout << "Returning to stack menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (stackChoice != 4);
            break;
        }
        case 3:
            stackApplicationsMenu();
            break;
        case 4:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            clearInput();
        }
    } while (choice != 4);
}

void queueMenu()
{
    int choice;
    QueueArray qa;
    QueuePointer qp;
    CircularQueue cq;
    DEQueue dq;
    PriorityQueue pq;
    int item, priority;

    do
    {
        cout << "Queue Operations Menu:\n";
        cout << "1. Queue using Arrays\n";
        cout << "2. Queue using Pointers\n";
        cout << "3. Circular Queue\n";
        cout << "4. DE-Queue\n";
        cout << "5. Priority Queue\n";
        cout << "6. Exit to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int queueChoice;
            do
            {
                cout << "Queue Using Array Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Exit to Queue Menu\n";
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice) {
                case 1:
                    cout << "Enter item to enqueue: ";
                    cin >> item;
                    qa.enqueue(item);
                    break;
                case 2:
                    qa.dequeue();
                    break;
                case 3:
                    qa.display();
                    break;
                case 4:
                    cout << "Returning to queue menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (queueChoice != 4);
            break;
        }
        case 2:
        {
            int queueChoice;
            do
            {
                cout << "Queue Using Pointers Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Exit to Queue Menu\n";
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "Enter item to enqueue: ";
                    cin >> item;
                    qp.enqueue(item);
                    break;
                case 2:
                    qp.dequeue();
                    break;
                case 3:
                    qp.display();
                    break;
                case 4:
                    cout << "Returning to queue menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (queueChoice != 4);
            break;
        }
        case 3:
        {
            int queueChoice;
            do
            {
                cout << "Circular Queue Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Exit to Queue Menu\n";
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "Enter item to enqueue: ";
                    cin >> item;
                    cq.enqueue(item);
                    break;
                case 2:
                    cq.dequeue();
                    break;
                case 3:
                    cq.display();
                    break;
                case 4:
                    cout << "Returning to queue menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (queueChoice != 4);
            break;
        }
        case 4:
        {
            int queueChoice;
            do
            {
                cout << "DEQueue Menu:\n";
                cout << "1. Enqueue at Front\n";
                cout << "2. Enqueue at Rear\n";
                cout << "3. Dequeue from Front\n";
                cout << "4. Dequeue from Rear\n";
                cout << "5. Display\n";
                cout << "6. Exit to Queue Menu\n";
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "Enter item to enqueue at front: ";
                    cin >> item;
                    dq.enqueueFront(item);
                    break;
                case 2:
                    cout << "Enter item to enqueue at rear: ";
                    cin >> item;
                    dq.enqueueRear(item);
                    break;
                case 3:
                    dq.dequeueFront();
                    break;
                case 4:
                    dq.dequeueRear();
                    break;
                case 5:
                    dq.display();
                    break;
                case 6:
                    cout << "Returning to queue menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (queueChoice != 6);
            break;
        }
        case 5:
        {
            int queueChoice;
            do
            {
                cout << "Priority Queue Menu:\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Display\n";
                cout << "4. Exit to Queue Menu\n";
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "Enter item to enqueue: ";
                    cin >> item;
                    cout << "Enter priority: ";
                    cin >> priority;
                    pq.enqueue(item, priority);
                    break;
                case 2:
                    pq.dequeue();
                    break;
                case 3:
                    pq.display();
                    break;
                case 4:
                    cout << "Returning to queue menu...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    clearInput();
                }
            } while (queueChoice != 4);
            break;
        }
        case 6:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
            clearInput();
        }
    } while (choice != 6);
}

int main()
{
    displayWelcome();

    int mainChoice;
    do 
    {
        cout << "\nMain Menu:\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "3. Linked List Operations\n";
        cout << "4. End Program\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) 
        {
        case 1:
            stackMenu();
            break;
        case 2:
            queueMenu();
            break;
        case 3:
            linkedListMenu();
            break;
        case 4:
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            clearInput();
        }
    } 
    while (mainChoice != 4);

    return 0;
}