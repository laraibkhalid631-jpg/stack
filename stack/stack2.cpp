#include <iostream>
#include <cctype>
using namespace std;

class Stack
{
    struct Node
    {
        char data;
        Node* next;
    };
    Node* top;

public:
    Stack() { top = NULL; }

    void push(char x)
    {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == NULL) return '\0';
        char x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    char peek()
    {
        if (top == NULL) return '\0';
        return top->data;
    }

    bool isEmpty() { return top == NULL; }
};

int priority(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }
        else
        {
            while (!s.isEmpty() && priority(s.peek()) >= priority(ch))
                postfix += s.pop();
            s.push(ch);
        }
    }
    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    cout << "Postfix Expression: " << infixToPostfix(infix);
    return 0;
}

