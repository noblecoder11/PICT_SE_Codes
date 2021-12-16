#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

// Implementation of stack data structure
class Stack {
    int top;
 
public:
    char a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
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
 
bool Stack::isEmpty()
{
    return (top < 0);
}

//Function to return precedence of operators
int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
// The main function to convert infix expression to postfix expression
char* infixToPostfix(string s) {
 
    Stack st;
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
        else if(c == ')') {
            while(st.peek() != '(')
            {
                result += st.peek();
                st.pop();
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.isEmpty() && precedence(s[i]) <= precedence(st.peek())) {
                result += st.peek();
                st.pop(); 
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.isEmpty()) {
        result += st.peek();
        st.pop();
    }
 
    // cout << result << endl;
    char* char_arr;
    string str_obj(result);
    char_arr = &str_obj[0];
    cout << char_arr << endl;
    return char_arr;
}

// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    Stack stack;
    int i;
 
    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand (number here), push it to the stack.
        if (isdigit(exp[i]))
            stack.push(exp[i] - '0');
 
        // If the scanned character is an operator, pop two elements from stack apply the operator
        else
        {
            int val1 = stack.pop();
            int val2 = stack.pop();
            switch (exp[i])
            {
            case '+': stack.push(val2 + val1); break;
            case '-': stack.push(val2 - val1); break;
            case '*': stack.push(val2 * val1); break;
            case '/': stack.push(val2/val1); break;
            }
        }
    }
    return stack.pop();
}

// function returns number of variable in given string, excludes operators
int noOfVar (string s) {
    char a[100];
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '(' ||s[i] == ')') {
            continue;
        } else {
            a[i] = s[i];
            n++;
        }
    }
    return n;
}
int main()
{
    bool cont = true;
    while (cont)
    {
        string infix;
        cout << "\nEnter INFIX expression: ";
        cin >> infix;

        char* postfix = infixToPostfix(infix);

        // postfix is char array like {'a', 'b', '+'}
        int i=0;
        while(postfix[i]!='\0')
        {
            if(precedence(postfix[i])==-1)
            {
                cout<<"Enter value for "<<postfix[i]<<" = ";
                cin>>postfix[i];
                cout << endl;
            }
            i++;
        }

        int val = evaluatePostfix(postfix);
        cout << "\nExpression evaluates to " << val << endl;

        cout << "\nDo you want to continue? (y/n): ";
        string choice;
        cin >> choice;
        if (choice == "n") {
            cont = false;
        } else {
            cont = true;
        }
    }
    cout << "Thank You. Exiting..." << endl;
return 0;
}