// Write C++ program using STL for sorting and searching 
// user defined records such as personal records (Name, 
// DOB, Telephone number etc) using vector container. 

#include <bits/stdc++.h>
using namespace std;

class details {
    string name;
    string dob;
    string mobile;

public:
    void createRecord(vector <details> &database);
    // using static functions as the functions below are not object specific
    static void searchRecord(vector <details> database, string query);
    static bool sortbyname(details a, details b);
    static auto sortRecord(vector <details> &database);
    static void displayAll(vector <details> database);

};

void details::createRecord(vector <details> &database) {
    
    // input name
    string Name;
    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, Name);
    this->name = Name;

    // input DOB
    // Code to find today's date
    time_t ttime = time(nullptr);
    tm *local_time = localtime(&ttime);
    int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    int day = local_time->tm_mday;
    string todayDate = to_string(day) + '/' + to_string(month) + '/' + to_string(year);

    // exception handling for date of birth
    while (true)
    {
        // try throw catch is used for error handling
        try
        {
            cout << "DATE OF BIRTH: (dd/mm/yyyy): ";
            string temp;
            cin >> temp;
            int dayInt;
            int monthInt;
            int yearInt;
            stringstream dayStream, monthStream, yearStream; // used to convert string into an int
            dayStream << temp.substr(0, 2);
            dayStream >> dayInt;
            monthStream << temp.substr(3, 2);
            monthStream >> monthInt;
            yearStream << temp.substr(6, 4);
            yearStream >> yearInt;
            // throw statements in various situations
            if (temp[2] != '/' || temp[5] != '/')
            {
                throw "Invalid birth date format";
            }
            else if (yearInt > year)
            {
                throw "The date you entered has not came yet. ;p";
            }
            else if (yearInt == year && monthInt > month)
            {
                throw "The date you entered has not came yet. ;p";
            }
            else if (monthInt == month && dayInt > day && yearInt == year)
            {
                throw "The date you entered has not came yet. ;p";
            }
            this->dob = temp;
            break;
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }


    // input mobile number
    // exception handling for mobile number
    while (true)
    {
        cout<<"PHONE NUMBER: ";
        // try throw catch is used
        try
        {
            string temp;
            cin >> temp;
            // telephone number should be 10 digits long
            if (temp.length() != 10)
            {
                throw "Telephone number must be 10 characters long\n";
            }
            // it should be numeric
            for (char i : temp)
            {
                if (!isdigit(i))
                {
                    throw "Telephone no must be a digit\n";
                    break;
                }
            }
            this->mobile = temp;
            break;
        }
        catch (const char *msg)
        {
            cout << msg;
        }
    }

    // pushing the entree(object of class details) in database(vector)
    database.push_back(*this);
}

void details::searchRecord(vector <details> database, string query) {
    int repeated = 0; // counts the number of times query appears in map
    vector <details> :: iterator result; // iterator of map to store the found result

    auto itr = database.begin(); // iterator to iterate through map
    for (itr = database.begin(); itr != database.end(); ++itr) {
        int found = itr->name.find(query); // find returns position of 'query' is found else return string::npos
        // if found
        if (found != string::npos) {
            result = itr; // store the value in state
            repeated++; // increment the count
        }
    }
    if (repeated > 1) { // if query present in more than one pair
        cout << "\n\x1B[33mYour query appears multiple times. Please enter more specific query.\033[0m\t\t\n";   // escape characters used for coloured output (Yellow)
        return;
    } else if (repeated == 1) { // if unique query is found
        // cout << "\n\x1B[32mPopulation of " << result->name << " is " << state->second<<".\033[0m\t\t\n"; // Green
        cout << "\n\x1B[32m----------- Record Found -----------"<< endl;
        cout << "Name: " << result->name << endl;
        cout << "DOB: " << result->dob << endl;
        cout << "Mobile: " << result->mobile << endl;
        cout << "-------------------------------------\033[0m\t\t" << endl;
        return;
    } else if (repeated == 0) { // if query not found
        cout << "\x1B[31mThe name you entered not found. Please try again.\033[0m\t\n"; // Red
    }

}

// Driver function to sort the vector elements by second element of pairs
bool details::sortbyname(details a, details b)
{
    return (a.name < b.name);
}

// function to sort database
auto details::sortRecord(vector <details> &database) {
    sort(database.begin(), database.end(), sortbyname); // comparison functor is used for sorting
    cout << "\n\n\x1B[32mDatabase sorted successfully.\033[0m\t\t"<<endl;
    return database;
}

// function to display complete database
void details::displayAll(vector <details> database) {
    if (database.size() == 0)
    {
        cout<<"\nThere are no records\n"<<endl;
    }
    else
    {
        cout << "------------------------------\n";
        cout << "Total Records: " << database.size() << endl;
        // setw sets the width of cell to create a table
        cout<<setw(20)<<left<<"Name"<<setw(20)<<left<<"DOB"<<setw(20)<<"Mobile Number"<<endl;
        for (auto it : database)
        {
            cout<<setw(20)<<left<<it.name<<setw(20)<<left<<it.dob<<setw(20)<<left<<it.mobile<<endl;
        }
        cout << "------------------------------\n";
    }
}

int main()
{
    vector <details> database;

    while (true)
    {
        cout << "\n----------- MAIN MENU -----------\n";
        cout << "1. Create record\n2. Search record\n3. Sort records\n4. Diplay database\n5. Exit\n";

        string choice;  // using string to avoid exceptions
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") { // create record
            details entree = *(new details);    // creating new object of class details
            entree.createRecord(database);      
        } else if (choice == "2") { //search record
            cout << "Enter the name: " <<endl;
            string query;
            cin.ignore();
            getline(cin, query); //input query
            details::searchRecord(database, query);
        } else if (choice == "3") { // sort records
            details::sortRecord(database);
        } else if (choice == "4") { // display database
            details::displayAll(database);
        } else if (choice == "5") { //exit
            cout << "Thank You. Exiting..."<<endl;
            break;
        } else { // invalid choice
            cout << "Enter a valid choice (1 to 4)." << endl;
        }
    }
    
    
return 0;
}