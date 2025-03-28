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
            cout << "\t\t\t\t\tStack Overflow!\n";
            return;
        }
        top++;
        arr[top] = x;
        cout <<"\t\t\t\t\t\t\t\t" << x << " pushed to stack\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\t\t\t\t\tStack Underflow!\n";
            return -1;
        }
        top--;
        int x = arr[top];
        cout << "\t\t\t\t\t\t\t\t" << x << " popped from stack\n";
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
            cout << "\t\t\t\t\tStack is empty\n";
            return;
        }
        cout << "\t\t\t\t\tStack elements: ";
        for (int i = top; i >= 0; i--) 
        {
            cout << "\t\t\t\t\t\t\t\t" << arr[i] << " ";
        }
        cout << endl;
    }
};

struct Node 
{
    int data;
    Node* next;
};

class StackPointer
{
private:
    Node* top;
public:
    StackPointer()
    {
        top = nullptr;
    }

    void push(int x)
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << "\t\t\t\t\t\t\t\t" << x << " pushed to stack\n";
    }

    int pop()
    {
        if (isEmpty()) 
        {
            cout << "\t\t\t\t\tStack Underflow!\n";
            return -1;
        }
        Node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        cout << "\t\t\t\t\t\t\t\t" << x << " popped from stack\n";
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
            cout << "\t\t\t\t\tStack is empty\n";
            return;
        }
        cout << "\t\t\t\t\tStack elements: ";
        Node* current = top;
        while (current != nullptr)
        {
            cout << "\t\t\t\t\t\t" << current->data << " ";
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
            cout << "\t\t\t\t\tQueue Overflow!\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " enqueued\n";
    }

    int dequeue() 
    {
        if (isEmpty())
        {
            cout << "\t\t\t\t\tQueue Underflow!\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " dequeued\n";
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
            cout << "\t\t\t\t\tQueue is empty\n";
            return;
        }
        cout << "\t\t\t\t\tQueue elements: ";
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
    Node* front;
    Node* rear;
public:
    QueuePointer() 
    {
        front = rear = nullptr;
    }

    void enqueue(int x)
    {
        Node* newNode = new Node();
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
        cout << "\t\t\t\t\t\t\t\t" << x << " enqueued\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "\t\t\t\t\tQueue Underflow!\n";
            return -1;
        }
        Node* temp = front;
        int x = temp->data;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        cout << "\t\t\t\t\t\t\t\t" << x << " dequeued\n";
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
            cout << "\t\t\t\t\tQueue is empty\n";
            return;
        }
        cout << "\t\t\t\t\tQueue elements: ";
        Node* current = front;
        while (current != nullptr) 
        {
            cout << "\t\t\t\t\t\t" << current->data << " ";
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
            cout << "\t\t\t\t\tQueue is full\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " enqueued\n";
    }

    int dequeue() 
    {
        if (isEmpty())
        {
            cout << "\t\t\t\t\tQueue is empty\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " dequeued\n";
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
            cout << "\t\t\t\t\tQueue is empty\n";
            return;
        }
        cout << "\t\t\t\t\tQueue elements: ";
        int i = front;
        while (true)
        {
            cout << "\t\t\t\t\t\t" << arr[i] << " ";
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
            cout << "\t\t\t\t\tQueue is full\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " enqueued at front\n";
    }

    void enqueueRear(int x)
    {
        if (isFull()) 
        {
            cout << "\t\t\t\t\tQueue is full\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " enqueued at rear\n";
    }

    int dequeueFront() 
    {
        if (isEmpty()) 
        {
            cout << "\t\t\t\t\tQueue is empty\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " dequeued from front\n";
        return x;
    }

    int dequeueRear()
    {
        if (isEmpty()) 
        {
            cout << "\t\t\t\t\tQueue is empty\n";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " dequeued from rear\n";
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
            cout << "\t\t\t\t\tQueue is empty\n";
            return;
        }
        cout << "\t\t\t\t\tQueue elements: ";
        int i = front;
        while (true)
        {
            cout << "\t\t\t\t\t\t\t\t" << arr[i] << " ";
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
        cout << "\t\t\t\t\t\t\t\t" << x << " enqueued with priority " << p << endl;
    }

    int dequeue()
    {
        if (front == nullptr)
        {
            cout << "\t\t\t\t\tQueue is empty\n";
            return -1;
        }
        PQNode* temp = front;
        int x = temp->data;
        front = front->next;
        delete temp;
        cout << "\t\t\t\t\t\t\t\t" << x << " dequeued\n";
        return x;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "\t\t\t\t\tQueue is empty\n";
            return;
        }
        cout << "\t\t\t\t\tQueue elements: ";
        PQNode* current = front;
        while (current != nullptr)
        {
            cout << "\t\t\t\t\t\t\t\t" << current->data << "(" << current->priority << ") ";
            current = current->next;
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
    cout << "\n\t\t\t\t\t====================================\n";
    cout << "\t\t\t\t\tWelcome to Data Structures Program\n";
    cout << "\t\t\t\t\tCreated by: Mafdy Tharwat\n";
    cout << "\t\t\t\t\t====================================\n";
    cout << "\t\t\t\t\tThis program demonstrates various data structure implementations\n";
    cout << "\t\t\t\t\tincluding stacks, queues, and expression conversions.\n";
    cout << "\t\t\t\t\t====================================\n";
}

void stackApplicationsMenu()
{
    int choice;
    string expression;

    do 
    {
        cout << "\n\t\t\t\tStack Applications Menu:\n";
        cout << "\t\t\t\t\t1. Convert Infix to Postfix Expression\n";
        cout << "\t\t\t\t\t2. Convert Postfix to Infix Expression\n";
        cout << "\t\t\t\t\t3. Convert Infix to Prefix Expression\n";
        cout << "\t\t\t\t\t4. Convert Prefix to Infix Expression\n";
        cout << "\t\t\t\t\t5. Exit to Previous Menu\n";
        cout << "\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
            cout << "\t\t\t\t\tEnter infix expression: ";
            getline(cin, expression);
            cout << "\t\t\t\t\tPostfix expression: " << infixToPostfix(expression) << endl;
            break;
        case 2:
            cout << "\t\t\t\t\tEnter postfix expression: ";
            getline(cin, expression);
            cout << "\t\t\t\t\tInfix expression: " << postfixToInfix(expression) << endl;
            break;
        case 3:
            cout << "\t\t\t\t\tEnter infix expression: ";
            getline(cin, expression);
            cout << "\t\t\t\t\tPrefix expression: " << infixToPrefix(expression) << endl;
            break;
        case 4:
            cout << "\t\t\t\t\tEnter prefix expression: ";
            getline(cin, expression);
            cout << "\t\t\t\t\tInfix expression: " << prefixToInfix(expression) << endl;
            break;
        case 5:
            cout << "\t\t\t\t\tReturning to previous menu...\n";
            break;
        default:
            cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
        }
    }
    while (choice != 5);
}

void stackMenu() 
{
    int choice;
    StackArray arrStack;
    StackPointer ptrStack;
    int item;

    do
    {
        cout << "\n\t\t\t\t\tStack Operations Menu:\n";
        cout << "\t\t\t\t\t1. Stack Using Arrays\n";
        cout << "\t\t\t\t\t2. Stack Using Pointers\n";
        cout << "\t\t\t\t\t3. Stack Applications\n";
        cout << "\t\t\t\t\t4. Exit to Main Menu\n";
        cout << "\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int stackChoice;
            do 
            {
                cout << "\n\t\t\t\t\tStack Using Array Menu:\n";
                cout << "\t\t\t\t\t1. Push\n";
                cout << "\t\t\t\t\t2. Pop\n";
                cout << "\t\t\t\t\t3. Display\n";
                cout << "\t\t\t\t\t4. Exit to Stack Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> stackChoice;

                switch (stackChoice)
                {
                case 1:
                    cout << "\t\t\t\t\tEnter item to push: ";
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
                    cout << "\t\t\t\t\tReturning to stack menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (stackChoice != 4);
            break;
        }
        case 2: 
        {
            int stackChoice;
            do
            {
                cout << "\n\t\t\t\t\tStack Using Pointers Menu:\n";
                cout << "\t\t\t\t\t1. Push\n";
                cout << "\t\t\t\t\t2. Pop\n";
                cout << "\t\t\t\t\t3. Display\n";
                cout << "\t\t\t\t\t4. Exit to Stack Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> stackChoice;

                switch (stackChoice) 
                {
                case 1:
                    cout << "\t\t\t\t\tEnter item to push: ";
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
                    cout << "\t\t\t\t\tReturning to stack menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (stackChoice != 4);
            break;
        }
        case 3:
            stackApplicationsMenu();
            break;
        case 4:
            cout << "\t\t\t\t\tReturning to main menu...\n";
            break;
        default:
            cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
            clearInput();
        }
    }
    while (choice != 4);
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
        cout << "\n\t\t\t\t\tQueue Operations Menu:\n";
        cout << "\t\t\t\t\t1. Queue using Arrays\n";
        cout << "\t\t\t\t\t2. Queue using Pointers\n";
        cout << "\t\t\t\t\t3. Circular Queue\n";
        cout << "\t\t\t\t\t4. DE-Queue\n";
        cout << "\t\t\t\t\t5. Priority Queue\n";
        cout << "\t\t\t\t\t6. Exit to Main Menu\n";
        cout << "\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int queueChoice;
            do
            {
                cout << "\n\t\t\t\t\tQueue Using Array Menu:\n";
                cout << "\t\t\t\t\t1. Enqueue\n";
                cout << "\t\t\t\t\t2. Dequeue\n";
                cout << "\t\t\t\t\t3. Display\n";
                cout << "\t\t\t\t\t4. Exit to Queue Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> queueChoice;

                switch (queueChoice) {
                case 1:
                    cout << "\t\t\t\t\tEnter item to enqueue: ";
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
                    cout << "\t\t\t\t\tReturning to queue menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (queueChoice != 4);
            break;
        }
        case 2: 
        {
            int queueChoice;
            do 
            {
                cout << "\n\t\t\t\t\tQueue Using Pointers Menu:\n";
                cout << "\t\t\t\t\t1. Enqueue\n";
                cout << "\t\t\t\t\t2. Dequeue\n";
                cout << "\t\t\t\t\t3. Display\n";
                cout << "\t\t\t\t\t4. Exit to Queue Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "\t\t\t\t\tEnter item to enqueue: ";
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
                    cout << "\t\t\t\t\tReturning to queue menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (queueChoice != 4);
            break;
        }
        case 3:
        {
            int queueChoice;
            do
            {
                cout << "\n\t\t\t\t\tCircular Queue Menu:\n";
                cout << "\t\t\t\t\t1. Enqueue\n";
                cout << "\t\t\t\t\t2. Dequeue\n";
                cout << "\t\t\t\t\t3. Display\n";
                cout << "\t\t\t\t\t4. Exit to Queue Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> queueChoice;

                switch (queueChoice) 
                {
                case 1:
                    cout << "\t\t\t\t\tEnter item to enqueue: ";
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
                    cout << "\t\t\t\t\tReturning to queue menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (queueChoice != 4);
            break;
        }
        case 4:
        {
            int queueChoice;
            do
            {
                cout << "\n\t\t\t\t\tDEQueue Menu:\n";
                cout << "\t\t\t\t\t1. Enqueue at Front\n";
                cout << "\t\t\t\t\t2. Enqueue at Rear\n";
                cout << "\t\t\t\t\t3. Dequeue from Front\n";
                cout << "\t\t\t\t\t4. Dequeue from Rear\n";
                cout << "\t\t\t\t\t5. Display\n";
                cout << "\t\t\t\t\t6. Exit to Queue Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "\t\t\t\t\tEnter item to enqueue at front: ";
                    cin >> item;
                    dq.enqueueFront(item);
                    break;
                case 2:
                    cout << "\t\t\t\t\tEnter item to enqueue at rear: ";
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
                    cout << "\t\t\t\t\tReturning to queue menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            }
            while (queueChoice != 6);
            break;
        }
        case 5:
        {
            int queueChoice;
            do
            {
                cout << "\n\t\t\t\t\tPriority Queue Menu:\n";
                cout << "\t\t\t\t\t1. Enqueue\n";
                cout << "\t\t\t\t\t2. Dequeue\n";
                cout << "\t\t\t\t\t3. Display\n";
                cout << "\t\t\t\t\t4. Exit to Queue Menu\n";
                cout << "\t\t\t\t\tEnter your choice: ";
                cin >> queueChoice;

                switch (queueChoice)
                {
                case 1:
                    cout << "\t\t\t\t\tEnter item to enqueue: ";
                    cin >> item;
                    cout << "\t\t\t\t\tEnter priority: ";
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
                    cout << "\t\t\t\t\tReturning to queue menu...\n";
                    break;
                default:
                    cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
                    clearInput();
                }
            } 
            while (queueChoice != 4);
            break;
        }
        case 6:
            cout << "\t\t\t\t\tReturning to main menu...\n";
            break;
        default:
            cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
            clearInput();
        }
    }
    while (choice != 6);
}

int main()
{
    displayWelcome();

    int mainChoice;
    do 
    {
        cout << "\n\t\t\t\t\tMain Menu:\n";
        cout << "\t\t\t\t\t1. Stack Operations\n";
        cout << "\t\t\t\t\t2. Queue Operations\n";
        cout << "\t\t\t\t\t3. End Program\n";
        cout << "\t\t\t\t\tEnter your choice: ";
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
            cout << "\t\t\t\t\tThank you for using my program. Goodbye!\n";
            break;
        default:
            cout << "\t\t\t\t\tInvalid choice! Please try again.\n";
            clearInput();
        }
    }
    while (mainChoice != 3);

    system("pause");
}