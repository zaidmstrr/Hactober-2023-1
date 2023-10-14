#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int x);
    int pop();
    MyQueue() { front = rear = NULL; }
};

// Function to add an element to the rear of the queue.
void MyQueue::push(int x)
{
    QueueNode* temp = new QueueNode(x);
    if (front == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

// Function to remove and return the front element from the queue.
int MyQueue::pop()
{
    if (front == NULL) {
        return -1; // Queue is empty
    }

    int val = front->data;
    QueueNode* temp = front;
    front = front->next;
    delete temp; // Deallocate memory
    return val;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        MyQueue* sq = new MyQueue();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
//optimal approach
