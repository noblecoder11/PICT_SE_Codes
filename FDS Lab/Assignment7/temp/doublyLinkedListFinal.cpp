/*
Write C++ program for storing binary number using doubly linked lists. Write function
a) To compute 1‘s and 2‘s complement
b) Add two binary numbers
*/

#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* prev;
    Node* next;

    // Default constructor
    Node ()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    // Parameterized constructor
    Node (int data)
    {
        this -> data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class doublyLinkedList
{
protected:
    Node* head;
public:
    // Default constructor
    doublyLinkedList() { head = NULL; }
  
    // Function to insert a node at the beginning of the linked list.
    void insertNodeAtHead(int);

    // Function to insert a node at the end of the linked list.
    void insertNodeAtTail(int);
  
    // Function to print the linked list.
    void printList();
  
    // Function to delete the node at given position
    void deleteNode(int);

};

void doublyLinkedList::insertNodeAtHead(int Data)
{
    // create a new node
    Node* newNode = new Node(Data);

    // if list is empty
    if (head == NULL)
    {
        head = newNode;
        newNode -> prev = NULL;
        newNode -> next = NULL;
        return;
    }

    newNode->prev = NULL;
    newNode->next =  head;
    head->prev = newNode;
    head = newNode;

}

void doublyLinkedList::insertNodeAtTail(int Data)
{
    // create a new node
    Node* newNode = new Node(Data);

    // if list is empty
    if (head == NULL) 
    {
        head = newNode;
        newNode -> prev = NULL;
        newNode -> next = NULL;
        return;
    }

    // traversing to the end of list
    Node* temp = head;
    while (temp -> next != NULL)
    {
        temp = temp->next;
    }

    // pointing next of last node to prev of newNode AND previous of newNode to next of last node. Pointing next of newNode to NULL
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}

void doublyLinkedList::printList()
{
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // traversing to the end of list
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

class binaryNumber : public doublyLinkedList
{
public:
    // Function to input binary numbers
    void input();

    // Function to calculate one's complement
    binaryNumber onesComplement();

    // Function to calculate two's complement
    binaryNumber twosComplement();

    // Overloading + operator for binary numbers
    binaryNumber operator+ (binaryNumber num);
    
};

void binaryNumber::input()
{ 
    int bits;
    cout << "\nEnter no of bits: ";
    cin >> bits;
    if (bits > 0)
    {
        for (int i = 0; i < bits; ++i)
        {
            int data;
            cout<<"Enter 0 or 1: ";
            cin >> data;
            while (data != 0 && data != 1)
            {
                cout << "Enter 0 or 1 only." << endl;
                cin >> data;
            }
            insertNodeAtTail(data);
        }
    }
}

binaryNumber binaryNumber::onesComplement()
{
    Node* temp = head;
    binaryNumber oc;
    while (temp != NULL)
    {
        temp->data ? oc.insertNodeAtTail(0) : oc.insertNodeAtTail(1);
        temp = temp->next;
    }
    return oc;
}

binaryNumber binaryNumber::twosComplement()
{
    binaryNumber tc;
    binaryNumber one;
    one.insertNodeAtTail(1);
    tc = onesComplement() + one;
    return tc;
    // return (tc.onesComplement() + one);
}

binaryNumber binaryNumber::operator+ (binaryNumber num)
{
    auto number1_ptr = this->head;
    auto number2_ptr = num.head;

    // making pointers point to the end of list because addition is performed right to left
    while (number1_ptr->next != NULL)
    {
        number1_ptr = number1_ptr->next;
    }

    while (number2_ptr->next != NULL)
    {
        number2_ptr = number2_ptr->next;
    }
    
    binaryNumber sum;
    int carry = 0;
    while (number1_ptr != nullptr || number2_ptr != nullptr)
    {

        int data = carry;
        carry = 0;
        if (number1_ptr != nullptr)
        {
            data += number1_ptr->data;
            number1_ptr = number1_ptr->prev;
        }

        if (number2_ptr != nullptr)
        {
            data += number2_ptr->data;
            number2_ptr = number2_ptr->prev;
        }

        if (data == 3)
        {
            carry = 1;
            data = 1;
        }
        if (data == 2)
        {
            carry = 1;
            data = 0;
        }
        sum.insertNodeAtHead(data);
    }
    if (carry == 1)
    {
        sum.insertNodeAtHead(carry);
    }
    return sum;
}

int main()
{
    binaryNumber n1, n2;
    while (true)
    {
        cout<<"\n---------- MAIN MENU ----------\n";
        cout<<"1. Enter new numbers\n2. One's Complement\n3. Two's Complement\n4. Sum\n5. Exit\n";
        cout<<"Enter your choice: ";
        string choice;
        cin>>choice;

        if (choice == "1")
        {
            n1.input();
            cout<<"Number 1: ";
            n1.printList();
            n2.input();
            cout<<"Number 2: ";
            n2.printList();
        }
        else if (choice == "2")
        {
            while (true)
            {
                cout<<"\n";
                cout<<"1. ";
                n1.printList();
                cout<<"2. ";
                n2.printList();
                cout<<"Select the number: ";
                string choice2;
                cin>>choice2;
                binaryNumber oc;
                if (choice2 == "1")
                {
                    oc = n1.onesComplement();
                    cout<<"\nNumber after one's complement is: ";
                    oc.printList();
                }
                else if (choice2 == "2")
                {
                    oc = n2.onesComplement();
                    cout<<"\nNumber after one's complement is: ";
                    oc.printList();
                }
                else
                {
                    cout<<"\nEnter a valid input. 1 or 2.";
                    continue;
                }
                break;
            }
        }
        else if (choice == "3")
        {
            while (true)
            {
                cout<<"\n";
                cout<<"1. ";
                n1.printList();
                cout<<"2. ";
                n2.printList();
                cout<<"Select the number: ";
                string choice3;
                cin>>choice3;
                binaryNumber tc;
                if (choice3 == "1")
                {
                    tc = n1.twosComplement();
                    cout<<"\nNumber after two's complement is: ";
                    tc.printList();
                }
                else if (choice3 == "2")
                {
                    tc = n2.twosComplement();
                    cout<<"\nNumber after two's complement is: ";
                    tc.printList();
                }
                else
                {
                    cout<<"\nEnter a valid input. 1 or 2.";
                    continue;
                }
                break;
            }
        }
        else if (choice == "4")
        {
            cout<<"\nSum of two numbers is: ";
            binaryNumber sum = n1 + n2;
            sum.printList();
        }
        else if (choice == "5")
        {
            cout<<"\nThank You. Exiting...";
            break;
        }
        else
        {
            cout<<"\nEnter a valid choice (1 to 5)"<<endl;
        }
    }

}