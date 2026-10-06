#include <iostream>
using namespace std;

class Stack
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int x)
    {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    bool isEmpty() { return top == NULL; }
};

int calculate(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePostfix(string exp)
{
    Stack s;
    for (char ch : exp)
    {
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int b = s.pop();
            int a = s.pop();
            int result = calculate(a, b, ch);
            s.push(result);
        }
    }
    return s.pop();
}

int main()
{
    string exp;
    cout << "Enter Postfix Expression: ";
    cin >> exp;
    cout << "Result = " << evaluatePostfix(exp);
    return 0;
}

