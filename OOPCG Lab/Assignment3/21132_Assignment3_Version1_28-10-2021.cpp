#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Exception handling: empty, numbers, 

class publication
{
    string title;
    float price;

    publication()
    {
        title = "Unknown";
        price = 0;
    }

};

class book: public publication
{
    int pageCount;

    public:
    void createBook()
    {
        
    }

};

class tape: public publication
{
    float playTime;
};

int main()
{
    list <tape> tapeList;
    list <book> bookList;
    while (true)
    {
        cout<<"1. Create record\n2. Display record(s)\n3. Update record\n4. Delete record"<<endl;
        string choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice == "1")
        {
            while (true)
            {
                string createChoice;
                cout<<"1. Create book\n2. Create tape\n3. Back"<<endl;
                cout<<"Enter choice: ";
                cin>>createChoice;
                if (createChoice == "1")
                {
                    book newBook;
                    newBook.createBook();
                    break;
                }
                else if (createChoice == "2")
                {
                    createTape();
                    break;
                }
                else if (createChoice == "3")
                {
                    break;
                }
                else
                {
                    cout<<"The choice you entered is invalid. Please enter a valid choice."<<endl;
                }
            }
        }
        else if (choice == "2")
        {
            while (true)
            {
                string displayChoice;
                cout<<"1. Display book(s)\n2. Display tape(s)\n3. Back"<<endl;
                cout<<"Enter choice: ";
                cin>>displayChoice;
                if (displayChoice == "1")
                {
                    while (true)
                    {
                        cout<<"1. Search by name\n2. Display all\n3.Back"<<endl;
                        string displayChoice2;
                        cout<<"Enter choice: ";
                        cin>>displayChoice2;
                        if (displayChoice2 == "1")
                        {
                            searchTitle(bookList);
                            break;
                        }
                        else if (displayChoice2 == "2")
                        {
                            displayAll(bookList);
                            break;
                        }
                        else if (displayChoice2 == "3")
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Enter a valid choice"<<endl;
                        }
                    }
                    
                }
                else if (displayChoice == "2")
                {
                    while (true)
                    {
                        cout<<"1. Search by name\n2. Display all\n3.Back"<<endl;
                        string displayChoice2;
                        cout<<"Enter choice: ";
                        cin>>displayChoice2;
                        if (displayChoice2 == "1")
                        {
                            searchTitle(tapeList);
                            break;
                        }
                        else if (displayChoice2 == "2")
                        {
                            displayAll(tapeList);
                            break;
                        }
                        else if (displayChoice2 == "3")
                        {
                            break;
                        }
                        else
                        {
                            cout<<"Enter a valid choice"<<endl;
                        }
                    }
                }
                else
                {
                    cout<<"Enter a valid choice."<<endl;
                }

            }
        }
    }
}