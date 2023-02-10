#include <iostream>
using namespace std;

class StackNode{
    public:
    int data;
    StackNode* next;

    // constructor
    StackNode(int d)
    {
        data = d;
        next = NULL;
    }
};
    
// pop(): remove and return the top item from the stack
int pop(StackNode** top){
    StackNode* tmp = *top;
    *top = (*top)->next;
    int tmp_data = tmp->data;
    free(tmp);
    return tmp_data;
}

// push(data): add data to the top of the stack
void push(StackNode** top, int data){
    StackNode* tmp = new StackNode(data);
    tmp->next = *top;
    *top = tmp;
    cout << data << " pushed to stack\n";
}

// isEmpty(): return of the stack is empty
bool isEmpty(StackNode* top){
    return !top;
}

// peek(): return the top item of the stack
int peek(StackNode* top){
    int d = NULL;
    if (isEmpty(top)==false){
        d = top->data;
    }
    return d;
}

void printStack(StackNode* top){
    StackNode tmp = *top;
    while (!isEmpty(&tmp)){
        cout << (&tmp)->data << " ";
        tmp = *((&tmp)->next);
    }
}

int main(){
    StackNode* top = new StackNode(1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);

    cout << pop(&top) << " popped from stack\n";

    cout << "Top element is " << peek(top) << endl;

    cout << "Elements present in stack : ";

    // print all elements in stack :
    while (!isEmpty(top))
    {
        // print top element in stack
        cout << peek(top) << " ";
        // remove top element in stack
        pop(&top);
    }
}