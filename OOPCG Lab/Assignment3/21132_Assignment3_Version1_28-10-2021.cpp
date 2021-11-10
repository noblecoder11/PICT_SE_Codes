/* 
Imagine a publishing company which does marketing for book and audio cassette 
versions. Create a class publication that stores the title (a string) and price (type float) of 
a publication. 
From this class derive two classes: book, which adds a page count (type int), and tape, 
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data 
and displays the data members. If an exception is caught, replace all the data member 
values with zero values.
*/

#include <bits/stdc++.h>
using namespace std;

// this fuction checks whether the passed string is number or not. It is used in title exception handling.
// keyword const is used to make sure that function doesn't make any change to original string
bool isNumber(string str)
{
    for (auto c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

// template is used here to handle both book and tape type of lists
template <typename T>
void displayAll(list <T> anyList)
{
    for (auto it : anyList)
    {
        it.getDetails();
    }
}

// this function searches the book using title and also displays the details of the book
template <typename X>
void searchTitle(list <X> anyList)
{
    string title;
    cout<<"Enter the title you want to search: ";
    cin.ignore();
    getline(cin, title);
    bool found = false;
    for (auto it : anyList)
    {
        if (it.title == title)
        {
            found = true;
            it.getDetails();
        }
    }
        if (!found)
        {
            cout<<"The title you entered is not present\n";
        }

}


// Class publication
class publication
{
public:
    string title; // this is public so that we can access it in main function to search publication
protected:
    float price;
};

class book: public publication
{
    int pageCount;

public:    
    // this fuction displays the details of required book
    void getDetails()
    {
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Page Count: "<<pageCount<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }

    // this fuction is used to set new book details. it also handles exception handling for various parameters
    void setBookDetails()
    {
        try
        {
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            if (title.length() == 0)
            {
                throw 0;
            }
            else
            {
                if (isNumber(title))
                {
                    throw 0;
                }
            }
        }
        catch (...) // catch statement for all exceptions
        {
            cout << "Exception caught, Initializing all paramters to 0\n";
            title = "";
            price = 0.0;
            pageCount = 0;
            return;
        }

        try
        {
            cout << "Enter Page count: ";
            if (cin >> pageCount)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore();
            cout << "Exception caught. Setting all values to 0\n";
            title = "";
            price = 0.0;
            pageCount = 0;
            return;
        }

        try
        {
            cout << "Enter Price: ";
            if (cin >> price)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Exception caught. Setting all values to 0\n";
            title = "";
            price = 0.0;
            pageCount = 0;
            return;
        }
    }

};

class tape: public publication
{

    float playTime;
public:
    // this fuction displays the details of required tape
    void getDetails()
    {
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Playing Time(in minutes): "<<playTime<<endl;
        cout<<"-----------------------------------------------"<<endl;
    }


    // this fuction is used to set new tape details. it also handles exception handling for various parameters
    void setTapeDetails()
    {
        try
        {
            cout << "Enter Title: ";
            cin.ignore(1000, '\n');
            getline(cin, title);
            if (title.length() == 0)
            {
                throw 0;
            }
            else
            {
                if (isNumber(title))
                {
                    throw 100;
                }
            }
        }
        catch (...) // catch statement for all exceptions
        {
            cout << "Failed to set title. initializing all paramters to 0\n";
            title = "";
            price = 0.0;
            playTime = 0;
            return;
        }

        try
        {
            cout << "Enter Playing Time (in minutes): ";
            if (cin >> playTime)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Setting page count failed. setting all values to 0\n";
            title = "";
            price = 0.0;
            playTime = 0;
            return;
        }

        try
        {
            cout << "Enter Price: ";
            if (cin >> price)
            {
            }
            else // exception handling for input
                throw 0;
        }
        catch (...) // catch all the exceptions
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Setting price failed setting all values to 0\n";
            title = "";
            price = 0.0;
            playTime = 0;
            return;
        }
    }
};

int main()
{
    list <tape> tapeList;
    list <book> bookList;
    while (true)
    {
        cout<<"-------- MAIN MENU --------\n";
        cout<<"1. Create record\n2. Search record\n3. Display record\n4. Delete record\n5. Exit\n"<<endl;
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
                    newBook.setBookDetails();
                    bookList.push_back(newBook);
                    break;
                }
                else if (createChoice == "2")
                {
                    tape newTape;
                    newTape.setTapeDetails();
                    tapeList.push_back(newTape);
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
                string searchChoice;
                cout<<"1. Search book\n2. Search tape\n3. Back\n";
                cout<<"Enter a choice: ";
                cin>>searchChoice;
                if (searchChoice == "1")
                {
                    searchTitle(bookList);
                    break;
                }
                else if (searchChoice == "2")
                {
                    searchTitle(tapeList);
                    break;
                }
                else if (searchChoice == "3")
                {
                    break;
                }
                else
                {
                    cout<<"Enter a valid choice\n";
                }

            }
        }
        else if (choice == "3")
        {
            while(true)
            {
                string displayChoice;
                cout<<"1. Display books\n2. Display tapes\n3. Display All\n4. Back"<<endl;
                cout<<"Enter choice: ";
                cin>>displayChoice;
                if (displayChoice == "1")
                {
                    displayAll(bookList);
                    break;
                }
                else if (displayChoice == "2")
                {
                    displayAll(tapeList);
                    break;
                }
                else if (displayChoice == "3")
                {
                    cout<<"Books\n";
                    displayAll(bookList);
                    cout<<"Tapes\n";
                    displayAll(tapeList);
                    break;
                }
                else if (displayChoice == "4")
                {
                    break;
                }
                else
                {
                    cout<<"Enter a valid choice."<<endl;
                }
            }
        }
        else if (choice == "4")
        {
            string deleteChoice;
            cout << "1. Delete Book\n2. Delete Tape\n3. Back\n";
            cout<<"Enter a choice: ";
            cin >> deleteChoice;

            if (deleteChoice == "1")
            {
                cout << "Enter title of book to delete: ";
                string title;
                cin.ignore();
                getline(cin, title);
                bool isFound = false;
                
                list<book>::iterator it;
                for (it = bookList.begin(); it != bookList.end(); ++it)
                {
                    if (title == it->title)
                    {
                        isFound = true;
                        bookList.erase(it);
                        cout << "Deleted book record\n";
                        break;
                    }
                }
                if (!isFound)
                {
                    cout << "Book not found\n";
                }
            }
            else if (deleteChoice == "2")
            {
                cout << "Enter name of Tape to delete: ";
                string title;
                cin.ignore();
                getline(cin, title);
                bool isFound = false;
                list<tape>::iterator it;
                for (it = tapeList.begin(); it != tapeList.end(); ++it)
                {
                    if (title == it->title)
                    {
                        isFound = true;
                        tapeList.erase(it);
                    }
                }
                if (isFound)
                {
                    cout << "Deleted Tape record\n";
                }
                if (!isFound)
                {
                    cout << "Tape not found\n";
                }
            }
            else if (deleteChoice == "3")
            {
                break;
            }
            else
            {
                cout<<"Enter a valid choice\n";
            }
        }
        else if (choice == "5")
        {
            cout<<"Thank you\n";
            break;
        }
        else
        {
            cout<<"Enter a valid choice\n";
        }

    }
}