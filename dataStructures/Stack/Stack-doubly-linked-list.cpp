#include <bits/stdc++.h>

using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
    StackNode *prev;

    StackNode(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class AddingStack
{
public:
    StackNode *first = NULL;
    StackNode *last = NULL;

    void print()
    {
        StackNode *tmp = first;
        cout << "printing...:";
        cout << last->data;
        cout << last->prev->data;
        while (tmp)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }

    void push(int v)
    {
        struct StackNode *tmp = (StackNode *)malloc(sizeof(struct StackNode));
        tmp->data = v;
        tmp->prev = NULL;
        tmp->next = NULL;
        if (first == NULL)
        {
            first = tmp;
            last = first;
        }
        else if (first == last)
        {
            tmp->next = first;
            first->prev = tmp;
            first = tmp;
            print();
        }
        else
        {
            first->prev = tmp;
            tmp->next = first;
            first = tmp;
        }
    }

    void pop()
    {
        StackNode *tmp = first;
        if (first == last)
        {
            first = NULL;
            last = NULL;
        }
        else if (first->next == last)
        {
            last->prev = NULL;
            first = last;
        }
        else
        {
            first = first->next;
            first->prev = NULL;
        }
        free(tmp);
    }

    void inc(int i, int v)
    {
        cout << "=====";
        print();
        StackNode *tmp = last;
        cout << "=====";
        for (int j = 0; j < i; j++)
        {
            tmp->data += v;
            cout << "=====";
            tmp = tmp->prev;
            cout << "=====";
            cout << tmp->prev->data;
            print();
        }
        print();
    }

    bool empty()
    {
        return !first;
    }

    long peek()
    {
        return first->data;
    }

    long sum()
    {
        StackNode *tmp = first;
        int sum = 0;
        while (tmp)
        {
            sum += tmp->data;
            tmp = tmp->next;
        }
        return sum;
    }
};
int main()
{
    int operations_size = 0;
    cin >> operations_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    AddingStack stack;
    for (int i = 0; i < operations_size; i++)
    {
        string operations_item;
        getline(cin, operations_item);

        istringstream command_stream(operations_item);

        string command;
        command_stream >> command;
        if (command == "push")
        {
            int value;
            command_stream >> value;
            stack.push(value);
        }
        else if (command == "pop")
        {
            stack.pop();
        }
        else if (command == "inc")
        {
            int i, v;
            command_stream >> i >> v;
            stack.inc(i, v);
        }

        if (stack.empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            cout << stack.peek() << " " << stack.sum() << endl;
        }
    }

    return 0;
}
