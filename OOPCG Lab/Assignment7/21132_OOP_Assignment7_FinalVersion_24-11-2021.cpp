/*
Write a C++ program that creates an output file, writes information to it, closes the file 
andopen it again as an input file and read the information from the file.
*/

#include <iostream> // input-output stream for cout and cin
#include <fstream> 
using namespace std;

int main()
{
    // making object of fstream class so it has both functions of ofstream and ifstream class
    fstream myFile;

    // running a while loop till the break statement is called
    while (true)
    {
        // printing main menu
        cout << "\n-------- MAIN MENU --------\n";
        cout << "1. Write\n2. Append\n3. Read\n4. Exit\n";

        string choice;
        cout<<"Enter your choice: ";
        cin >> choice;

        if (choice == "1")  // write in the file
        {
            myFile.open("Assignment7.txt", ios::out);   // opening in output mode
            if (!myFile)
            {
                cout << "File not created!";
            }
            else
            {
                cout << "File created successfully!"<<endl;
                string text;
                cin.ignore();
                cout<<"Enter your text. Enter '`' key to end the text."<<endl;
                // getline is given delimiter '`'. Input is taken till the delimiter is entered
                getline(cin, text, '`');
                myFile<< text;  // appending the text to the file using myFile object
                cout << "Data written in file successfully." << endl;
                myFile.close(); // closing the file
            }
        }
        else if (choice == "2") // append text to the file
        {
            myFile.open("Assignment7.txt", ios::app);   // opening file in append mode
            if (!myFile)
            {
                cout << "File not created!";
            }
            else
            {
                cout << "File created successfully!"<<endl;
                string text;
                cin.ignore();
                // getline is given delimiter '`'. Input is taken till the delimiter is entered
                cout<<"Enter your text. Enter '`' key to end the text."<<endl;
                getline(cin, text, '`');
                myFile<<"\n";   // for starting from new line
                // appending the text to the file using myFile object
                myFile<<text;
                cout << "Data appended in file successfully." << endl;
                myFile.close();
            }
        }
        else if (choice == "3") // reading the contents of the file
        {
            myFile.open("Assignment7.txt", ios::in);    //opening file in input mode
            if (!myFile)
            {
                cout << "No such file"<<endl;
            }
            else
            {
                char ch;
                cout<<"Data in file is: "<<endl;
                while (true)
                {
                    ch = myFile.get();
                    if (myFile.eof())
                        break;

                    cout << ch;
                }
            }
            myFile.close();
        }
        else if (choice == "4") // Exit
        {
            cout<<"Thank you";
            break;
        }
        else    // exception handling if incorrect choice is entered.
        {
            cout<<"Enter a valid choice(1 to 4)."<<endl;
        }
    }
    return 0;
}