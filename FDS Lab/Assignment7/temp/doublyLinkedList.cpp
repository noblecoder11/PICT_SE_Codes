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

    // Friend function
    friend class binaryNumber;
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

// // this function is incomplete
// void doublyLinkedList::deleteNode(int n)
// {
//     cout<<"deleting"<<endl;
//     Node *temp1 = head, *temp2 = NULL;
//     int listLength = 0;

//     // Check for empty list
//     if (head == NULL) {
//         cout << "List empty" << endl;
//         return;
//     }

//     // finding the length of list
//     while (temp1->next != NULL)
//     {
//         listLength++;
//         temp1 = temp1->next;
//     }

//     if (listLength < n)
//     {
//         cout<<"Index out of range"<<endl;
//         return;
//     }

//     temp1 = head;
    
//     // this code doesn't delete node at first position, need to add if (n == 1) condition here

//     while (n-- > 1)
//     {
//         temp2 = temp1;
//         temp1 = temp1->next;
//     }

//     // Node* temp3 = temp1->next;

//     temp2->next = temp1->next;
//     temp1->prev = temp2;

//     delete temp1;

// }

class binaryNumber : public doublyLinkedList
{
public:
    void input()
    {
        // Clearing earlier input
        // Node* temp = head;
        // while (temp != NULL)
        // {
        //     delete temp;
        //     temp = temp->next;
        // }
        
        int bits;
        cout << "\nEnter no of bits: ";
        cin >> bits;
        if (bits > 0)
        {
            for (int i = 0; i < bits; ++i)
            {
                int data;
                cout<<"Enter space separated 0 or 1: ";
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

    binaryNumber onesComplement()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            temp->data ? temp->data = 0 : temp->data = 1;
            temp = temp->next;
        }
        return *this;
    }

    binaryNumber twosComplement()
    {
        binaryNumber one;
        one.insertNodeAtTail(1);
        return (this->onesComplement() + one);
    }

    // void Addition(doublyLinkedList number1, doublyLinkedList number2)
    // {

    // }

    binaryNumber operator+ (binaryNumber num)
    {
        auto number1_ptr = this->head;
        auto number2_ptr = num.head;

        // making pointers point to the end of list because addition is performed right to left
        // Node* temp = head;
        while (number1_ptr->next != NULL)
        {
            number1_ptr = number1_ptr->next;
        }
        // Node* temp2 = num.head;
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

};

int main()
{
    binaryNumber n1, n2;
    while (true)
    {
        cout<<"\n---------- MAIN MENU ----------\n";
        cout<<"1. Enter new numbers\n2. One's Complement\n3. Two's Complement\n4. Sum\n5. Exit\n";

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

                if (choice2 == "1")
                {
                    n1.onesComplement();
                    cout<<"\nNumber after one's complement is: ";
                    n1.printList();
                }
                else if (choice == "2")
                {
                    n2.onesComplement();
                    cout<<"\nNumber after one's complement is: ";
                    n2.printList();
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
                string choice2;
                cin>>choice2;

                if (choice2 == "1")
                {
                    n1.twosComplement();
                    cout<<"\nNumber after two's complement is: ";
                    n1.printList();
                }
                else if (choice == "2")
                {
                    n2.twosComplement();
                    cout<<"\nNumber after two's complement is: ";
                    n2.printList();
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
    

    // binaryNumber l;
    // binaryNumber n1;
    // binaryNumber n2;
    // n1.insertNodeAtTail(1);
    // n1.insertNodeAtTail(0);
    // n2.insertNodeAtTail(1);
    // n2.insertNodeAtTail(0);
    // binaryNumber sum = n1.onesComplement();
    // sum.printList();
    // l.insertNodeAtTail(4);
    // l.printList();
    // l.insertNodeAtTail(5);
    // l.insertNodeAtTail(8);
    // l.insertNodeAtTail(0);
    // l.insertNodeAtTail(7);
    // l.insertNodeAtTail(3);
    // l.printList();
    // l.deleteNode(1);
    // l.printList();
    // l.deleteNode(2);
    // l.deleteNode(3);

}