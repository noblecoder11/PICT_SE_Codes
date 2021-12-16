/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as (), {}, []. Write C++ program using stack to check whether given expression is well parenthesized or not. 
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
    int top;
 
public:
    char a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(char x);
    char pop();
    char peek();
    bool empty();
};
 
bool Stack::push(char x)
{
    // Stack Overflow
    if (top >= (MAX - 1)) {
        return false;
    }
    else {
        // x pushed into stack
        a[++top] = x;
        return true;
    }
}
 
char Stack::pop()
{
    if (top < 0) {
        // Stack Underflow
        return 0;
    }
    else {
        char x = a[top--];
        return x;
    }
}
char Stack::peek()
{
    if (top < 0) {
        // Stack is Empty
        return 0;
    }
    else {
        char x = a[top];
        return x;
    }
}
 
bool Stack::empty()
{
    return (top < 0);
}

// Function to check whether two characters are opening and closing of same type. 
bool ArePair(char opening,char closing) {
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool areBracketsBalanced(string expr)
{ 
    Stack s;
    char x;
 
    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{') {
            // Push the element in the stack
            cout << "Pushed: "<< expr[i] << endl;
            s.push(expr[i]);
            continue;
        } else if (expr[i] == ')' || expr[i] == ']'
            || expr[i] == '}') {
            // closing bracked is found and if stack is empty or top element doesn't pair with bracket (e.g. '[' pairs with ']')
            if (s.empty() || !ArePair(s.peek(), expr[i])) {
                return false;
            } else {
                cout << "Popped: " << expr[i] << endl;
                s.pop();
            }
        }
    }
    // after traversing through full expression, if stack is empty, expression is balanced
    return s.empty() ? true : false;
       
}

int main()
{
    cout << "This program checks whether given expression is well parenthesized or not.\n";
    bool cont = true;
    while (cont)
    {
        cout << "\nEnter an expression: ";
        string expr;
        cin.ignore();
        getline(cin, expr);

        bool balanced = areBracketsBalanced(expr);

        if (balanced) {
            cout << "\nThe expression is BALANCED.\n";
        } else {
            cout << "\nThe expression is NOT BALANCED.\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        string choice;
        cin >> choice;
        if (choice == "n") {
            cont = false;
        } else {
            cont = true;
        }
    }
    cout << "\nThank You. Exiting..." << endl;
return 0;
}