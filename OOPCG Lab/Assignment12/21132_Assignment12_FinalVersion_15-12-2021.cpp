/*Write a program in C++ to use map associative container. The 
keys will be the names of states and the values will be the 
populations of the states. When the program runs, the user is 
prompted to type the name of a state. The program then looks in 
the map, using the state name as an index and returns the 
population of the state*/
#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;
# define ll long long int

// function to capitalize the input string
string capitalize(string str)
{
  for (int i = 0;
           i < str.length(); i++)
  {
    // If first character of a word is found
    if (i == 0 && str[i] != ' ' ||
        str[i] != ' ' && str[i - 1] == ' ')
    {
      // If it is in lower-case
      if (str[i] >= 'a' && str[i] <= 'z')
      {
        // Convert into Upper-case
        str[i] = (char)(str[i] - 'a' + 'A');
      }
    }
 
    // If apart from first character Any one is in Upper-case
    else if (str[i] >= 'A' &&
             str[i] <= 'Z')
 
      // Convert into Lower-Case
      str[i] = (char)(str[i] + 'a' - 'A');
  }
 
  return str;
}

// function for searching and displaying the population of state entered
void search(map<string, ll> statePopulation, string query) {
    string queryCapitalized = capitalize(query); // capitalizing the query allows us searching even if user enters all small letters
    int repeated = 0; // counts the number of times query appears in map
    map <string, ll> :: iterator state; // iterator of map to store the found result

    auto itr = statePopulation.begin(); // iterator to iterate through map
    for (itr = statePopulation.begin(); itr != statePopulation.end(); ++itr) {
        int found = itr->first.find(query); // find returns position of 'query' is found else return string::npos
        int foundCapitalized = itr->first.find(queryCapitalized);
        // if found
        if (found != string::npos) {
            state = itr; // store the value in state
            repeated++; // increment the count
        } else if (foundCapitalized != string::npos) {
            state = itr;
            repeated++;
        }
    }

    
    if (repeated > 1) { // if query present in more than one pair
        cout << "\n\x1B[33mYour query appears multiple times. Please enter more specific query.\033[0m\t\t\n";   // escape characters used for coloured output (Yellow)
        return;
    } else if (repeated == 1) { // if unique query is found
        cout << "\n\x1B[32mPopulation of " << state->first << " is " << state->second<<".\033[0m\t\t\n"; // Green
        return;
    } else if (repeated == 0) { // if query not found
        cout << "\x1B[31mThe state you entered not found. Please try again.\033[0m\t\n"; // Red
    }

}

// Main function
int main()
{
    // map containing states and their population
    map <string, ll> statePopulation = 
    {
        make_pair("Uttar Pradesh", 199812341 ),
        make_pair("Maharashtra", 112374333 ),
        make_pair("Bihar", 104099452 ),
        make_pair("West Bengal", 91276115 ),
        make_pair("Madhya Pradesh", 72626809 ),
        make_pair("Tamil Nadu", 72147030 ),
        make_pair("Rajasthan", 68548437 ),
        make_pair("Karnataka", 61095297 ),
        make_pair("Gujarat", 60439692 ),
        make_pair("Andhra Pradesh", 49386799 ),
        make_pair("Odisha", 41974218 ),
        make_pair("Telangana", 35193978),
        make_pair("Kerala", 33406061 ),
        make_pair("Jharkhand", 32988134 ),
        make_pair("Assam", 31205576 ),
        make_pair("Punjab", 27743338 ),
        make_pair("Chhattisgarh", 25545198 ),
        make_pair("Haryana", 25351462 ),
        make_pair("Delhi", 16787941 ),
        make_pair("Jammu & Kashmir", 12258433 ),
        make_pair("Uttarakhand", 10086292 ),
        make_pair("Himachal Pradesh", 6864602 ),
        make_pair("Tripura", 3673917 ),
        make_pair("Meghalaya", 2966889 ),
        make_pair("Manipur", 2855794 ),
        make_pair("Nagaland", 1978502 ),
        make_pair("Goa", 1458545 ),
        make_pair("Arunachal Pradesh", 1383727 ),
        make_pair("Puducherry", 1247953 ),
        make_pair("Mizoram", 1097206 ),
        make_pair("Chandigarh", 1055450 ),
        make_pair("Sikkim", 610577 ),
        make_pair("Dadra & Nagar Haveli and Daman & Diu", 586956 ),
        make_pair("Andaman & Nicobar", 380581 ),
        make_pair("Ladakh", 274289 ),
        make_pair("Lakshadweep", 64473 ),
    };

    // information about program
    cout<<"Welcome. This program tells you the population of Indian states. Enjoy exploring them...\n";
    while (true) { // while loop till the break is called

        // main menu and choices are displayed
        cout<<"\n----------- MAIN MENU -----------\n";
        cout<<"1. Search\n2. Exit\n";
        cout<<"Enter your choice: ";
        string choice;
        cin>>choice;

        if (choice == "1") {
            string query;
            cout<<"Enter the name of State or UT: ";
            cin.ignore(); 
            getline(cin, query); // getline is used to get multi-worded input
            search(statePopulation, query);
        } else if (choice == "2") {
            cout<<"Thank you. Exiting..."<<endl; // exiting
            break;
        } else { // exception handling
            cout<<"Please enter a valid choice.(1 or 2)\n";
        }
    }
return 0;
}