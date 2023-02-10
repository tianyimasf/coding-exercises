#include <iostream>
using namespace std;

class QueueNode{
    public:
    int data;
    QueueNode* next;

    QueueNode(int d){
        data = d;
        next = NULL;
    }
};

class Queue{
    public:
    QueueNode* first;
    QueueNode* last;

    Queue(int d){
        first = new QueueNode(d);
        last = first;
    }
};

// add(item): add an item to the end of the list
void add(Queue** queue, int d){
    QueueNode *tmp = new QueueNode(d);
    if ((*queue)->first == NULL){
        (*queue)->first = tmp;
        (*queue)->last = (*queue)->first;
    } else {
        (*queue)->last->next = tmp;
        (*queue)->last = tmp;
    }
    cout << d << " queued\n";
}

// isEmpty(): return true if the queue is empty
bool isEmpty(Queue* queue){
    return !(queue->first);
}

// remove(): remove and return the first item in the list
int remove(Queue** queue){
    QueueNode *tmp = (*queue)->first;
    if ((*queue)->first == (*queue)->last){
        (*queue)->first = NULL;
        (*queue)->last = NULL;
    } else {
        (*queue)->first = (*queue)->first->next;
    }
    int data = tmp->data;
    free(tmp);
    return data;
}

// peek(): return the top of the queue
int peek(Queue* queue){
    int data = NULL;
    if (!isEmpty(queue)){
        data = queue->first->data;
    }
    return data;
}

int main()
{
    Queue *queue = new Queue(1);
    add(&queue, 2);
    add(&queue, 3);
    add(&queue, 4);
    add(&queue, 5);

    cout << remove(&queue) << " dequeued\n";

    cout << "Top element is " << peek(queue) << endl;

    cout << "Elements present in stack : ";

    // print all elements in stack :
    while (!isEmpty(queue))
    {
        // print top element in stack
        cout << peek(queue) << " ";
        // remove top element in stack
        remove(&queue);
    }
}