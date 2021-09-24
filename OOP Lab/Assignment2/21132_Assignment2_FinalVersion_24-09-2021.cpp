// 21132_Shreyash Halge
// Code for OOPCG Lab / Assignment 2 / Version 2

#include <bits/stdc++.h>    //Using standard library instead of including many libraries
#include <limits>   //For exception handling
#include <ctime>    //For getting current time and date
using namespace std;    

// exception handling for roll number
int inputRollno(string s)   //string s is used as different output is required in different cases
{
    while (true)
    {
        cout<<"\nEnter the roll number "+s;
        //try and catch is used for exception handling. the statements expected to give errors are written in try block
        try
        {
            string temp;
            cin >> temp;
            // checking if roll number is a digit
            for (char i : temp)
            {
                    if (!isdigit(i))
                    {
                        throw "Roll number must be a digit\n";
                        break;
                    }
            }
            stringstream obj(temp);
            int strnum;
            obj>>strnum;
            cout<<endl;
            return strnum;
            break;
        }
        // message thrown by throw is catched here
        catch (const char *msg)
        {
            cout << msg;
        }
    }

}

//print list of roll numbers of student in database
void printRNList(vector<int>v, int n)
{
    cout<<"List of students already present in database: [";
            for(int rn=0; rn<n; rn++)
            {
                if(v[rn] != 0){cout<<v[rn]<<", ";}  //If the value of roll number is other than 0(which is default value), print the roll number
            }
            cout<<"]"<<endl;
}

// this function is used to get empty spot(where there is no student) in the vector, studentObject array and personalInfoObject array 
int searchEmptySpot(vector<int> v, int n)
{
    for(int i=0; i<n; i++){
        if(v[i]==0){return i;}
    }
    return -1;  //it returns -1 if there is no empty spot
}

// this function gives the index of the roll no passed as argument
int getIndex(vector<int> v, int K)
{
    //using built in function for finding position
    auto it = find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end())
    {
        // calculating the index of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not present in the vector
        return -1;
    }
}

// class personalInfo
class personalInfo
{
    // private members of class personalInfo
private:
    string address;
    string dob;
    string bloodGroup;
    string licence;
public:
    // public members of class personal info
    personalInfo();
    personalInfo(personalInfo &);
    ~personalInfo();
    // Student is made friend class of class personalInfo, so that student can use private members of this class
    friend class Student;
};

// default constructor of class personalInfo is defined here
personalInfo::personalInfo()
{
    address="abc, xyz";
    dob="00/00/0000";
    bloodGroup="X+";
    licence="ABC00000";
}

// copy constructor of class personalInfo is defined here
personalInfo::personalInfo(personalInfo &obj)
{
    //this is a pointer points to the object which invokes it
    this->address=obj.address;
    this->dob=obj.dob;
    this->bloodGroup=obj.bloodGroup;
    this->licence=obj.licence;
}

// destructor of class personalInfo is defined
personalInfo::~personalInfo()
{
    cout<<"Successfully deleted personal information of a student"<<endl;
}

// class student
class Student
{
    //private members of class student
private:
    string name;
    string year;
    string division;
    string mobile;
public:
    int rollno;
    // public members of class student
    Student();
    Student(const Student&);
    ~Student();
    // static class variable and static class functions are declared and defined
    static int count;
    inline static void incrementCount(){Student::count++;}; //to increment count
    inline static void decrementCount(){Student::count--;}; //to decrement count
    inline static void showCount(){cout<<"Total number of students: "<<Student::count;} //to show count

    //create method is used to create a student in database
    void create(personalInfo &obj, int rolno)
    {
        rollno=rolno;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter the details of the new student:";
        cout<<"\nNAME : ";
        cin.ignore();
        getline(cin, name);     //inline function is used to get full name
        cout<<"YEAR : ";
        cin>>year;
        cout<<"DIVISION: ";
        cin>>division;

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
                mobile = temp;
                break;
            }
            catch (const char *msg)
            {
                cout << msg;
            }
        }

        cout<<"ADDRESS : ";
        cin.ignore();
        getline(cin, obj.address);      //getline is used to get complete address
        
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
                obj.dob = temp;
                break;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
        }
    
        // exception handling for blood group
        while (true)
        {
            cout<<"BLOOD GROUP: ";
            try
            {
                string temp;
                cin >> temp;
                // it only accepts these blood groups
                if (temp=="A+" || temp=="B+" || temp=="O+" || temp=="A-" || temp=="B-" || temp=="O-"  || temp=="AB+" || temp=="AB-")
                {
                    obj.bloodGroup = temp;
                    break;
                }
                else
                {
                    throw "Enter a valid blood group. e.g. A+ or AB-\n";
                }
                break;
            }
            catch (const char *msg)
            {
                cout << msg;
            }
        }

        cout<<"LICENCE NUMBER : ";
        cin>>obj.licence;
        cout<<"---------------------------------"<<endl;
    }

    // display method is used to display the student with given roll number
    void display(personalInfo &obj)
    {
        cout<<"---------------------------------"<<endl;
        cout<<"NAME OF STUDENT : "<<name<<endl;
        cout<<"ROLL NO : "<<rollno<<endl;
        cout<<"YEAR : "<<year<<endl;
        cout<<"DIVISION : "<<division<<endl;
        cout<<"PHONE NUMBER : "<<mobile<<endl;
        cout<<"ADDRESS OF STUDENT : "<<obj.address<<endl;
        cout<<"DATE OF BIRTH : "<<obj.dob<<endl;
        cout<<"BLOOD GROUP : "<<obj.bloodGroup<<endl;
        cout<<"LICENCE NUMBER : "<<obj.licence<<endl;
        cout<<"---------------------------------"<<endl;
    }

    // update method is used to update the data of student already present in database
    void update(personalInfo &obj, int rolno)
    {
        create(obj, rolno);     //code of create function is reused
        cout<<"Student data updated successfully."<<endl;
    }

    // delete method is used to delete a student from the database
    void deleteStudent(personalInfo &obj)
    {
        obj.~personalInfo();    // student is friend class of personalInfo, therefore we can call destructor for personalInfo using the object of student class
        this->~Student();
    }

    // copy function is used to copy a student in database
    void copy(Student& sobj_empty, personalInfo &pobj_i, personalInfo &pobj_empty)
    {
        // new object is created to store the data of this student
        Student *obj1= new Student(*this);
        // new object is created to store personal info of this student
        personalInfo *obj2= new personalInfo(pobj_i);
        
        // assignment operator is used to fill the data of obj1 and obj2 at empty spots in array
        sobj_empty=*obj1;
        pobj_empty=*obj2;
    }
};

// when we write this, the memory is allocated to stati variable count and is set to 0 for default
int Student::count;

// default constructor of class student
// When no parameter is passed while creating object, these values are given to variables inside it
Student::Student()
{
    name="Name";
    rollno=0;
    year="0";
    division="SE0";
    mobile="0000000000";
}

// copy constructor of class student used to copy content from one object to other
Student::Student(const Student &obj)
{
    // this is a pointer points to the object which invokes it
    this->name=obj.name;
    this->year=obj.year;
    this->division=obj.division;
    this->mobile=obj.mobile;
}

// destructor of class student
// destructor is the last set of code running when an object is being deleted
Student::~Student()
{
    cout<<"Succesfully deleted student."<<endl;
}


// driver code 
int main()
{
    //Welcome message for the user
    cout<<"Welcome to the student database portal!\nNow you can easily store and manage data of all your students.\n";

    // taking input for maximum number of students in database
    cout<<"Enter the maximum number of students in your database: ";
    int n;
    cin>>n;

    // new is dynamic memory allocation operator, studentObject is pointer of type student and it is a array of object of size n
    Student *studentObject=new Student[n];
    // new is dynamic memory allocation operator, personalInfoObject is pointer of type student and it is a array of object of size n
    personalInfo *personalInfoObject=new personalInfo[n];
    // vector rollNoList stores the roll numbers of students in the database
    vector <int> rollNoList(n);
        
    // while loop is used to perform operations till the user enters 'n'
    while(true)
    {
        // information of program
        cout<<"This program allows you to:\n1. Create a student\n2. Read the data previously stored.\n3. Show all students in database.\n4. Update data of existing student.\n5. Delete an existing student.\n6. Copy constructor.\n";

        cout<<"\nEnter the choice for respective operation which you want to perform(1 to 6): ";

        //error handling for choice
        string temp;
        cin>>temp;
        stringstream obj(temp); //used to convert string to int
        int choice;
        obj>>choice;
        
        //choice for creating student
        if(choice==1)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);

            // Taking roll number of student as input
            int rollno = inputRollno("of the student you want to add: ");
            
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            if(getIndex(rollNoList, rollno) !=-1)
            {
                cout<<"This roll number is already present. Try other roll number of update the student."<<endl;
            }
            else
            {
                // Search empty spot returns the index in array such that there is no student on that index. It returns -1 if there is no empty spot
                int i = searchEmptySpot(rollNoList, n);
                
                if(i==-1){cout<<"Database is Full."<<endl;}
                else{
                    rollNoList[i]=rollno;
                    studentObject[i].create(personalInfoObject[i], rollno);
                    Student::incrementCount();  //inline static function is used to increment count of number of students in database
                }
            }
            
        }
        // choice for displaying student with given roll numbrer
        else if(choice==2)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);
            
            // Taking roll number of student as input
            int rollno = inputRollno("of the student you want to dispay: ");
                        
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            int i=getIndex(rollNoList, rollno);
        
            if(i==-1)
            {
                cout<<"Student with the given roll number do not exist in database. Enter another roll number or add a new student with given roll number."<<endl;
            }
            else
            {
                studentObject[i].display(personalInfoObject[i]);
            }            
            
        }
        // choice to show all students in database
        else if(choice==3)
        {
            Student::showCount();       // use of inline static function of class student to show the total count of students in database
            cout<<endl;
            for(int i=0; i<n; i++)
            {
                //if the roll number of student is not zero then data of that student is printed
                if(rollNoList[i]!=0)
                {
                    // call display function
                    studentObject[i].display(personalInfoObject[i]);
                }
            }
        }
        // choice for updating the student information
        else if(choice==4)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);
            
            // Taking roll number of student as input
            int rollno= inputRollno("of student you want to update: ");
                        
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            int i=getIndex(rollNoList, rollno);

            if(i ==-1)
            // if roll number is not present in the list
            {
                cout<<"Student with the given roll number do not exist in database. Enter another roll number or add a new student with given roll number."<<endl;
            }
            else
            {
                // display the previous details
                cout<<"Here are the details you entered previously for this roll number:"<<endl;
                studentObject[i].display(personalInfoObject[i]);

                // input new roll number to be given
                int rollNo=inputRollno("you want to give to the student: ");
                
                // updating student
                studentObject[i].update(personalInfoObject[i], rollNo);
                rollNoList[i]=rollNo;
            }
            
        }
        // choice for deleting the student
        else if(choice==5)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);

            // Taking roll number of student as input
            int rollno= inputRollno("of student you want to delete: ");
            
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            int i=getIndex(rollNoList, rollno);
            
            if(i ==-1)
            // if student is not present in database
            {
                cout<<"Student with the given roll number do not exist in database. Enter another roll number or add a new student with given roll number."<<endl;
            }
            else
            {
                // call delete student function for that index
                studentObject[i].deleteStudent(personalInfoObject[i]);
                rollNoList[i]=0;
                Student::decrementCount();      //inline static function is used to decrement count
            }
        }
        // choice for copying a student
        // Copy Constructor
        else if(choice==6) 
		{
            // printing the roll numbers in database
            printRNList(rollNoList, n);
            // read roll number of the student who you want to copy
            int rollno=inputRollno("of student you want to copy: ");
            // get the index of given roll number
            int i= getIndex(rollNoList, rollno);
            // find an empty spot in all three arrays
            int empty=searchEmptySpot(rollNoList, n);
            if (i==-1)
            // if student is not present in database
            {
                cout<<"Roll number you entered is not present in the database."<<endl;
            }
            else
            {
                // read the new roll number for copied student
                int roln= inputRollno("you want to give to the copied student: "); 
                if (getIndex(rollNoList, roln)!=-1)
                // if roll number is already in use by other student
                {
                    cout<<"The roll number must be different from previous roll number and not the same as any other roll number in database."<<endl;
                }
                else
                {   studentObject[i].copy(studentObject[empty],personalInfoObject[i], personalInfoObject[empty]);

                    // set the new roll number to copied student
                    studentObject[empty].rollno=roln;
                    // insert roll number in roll number list
                    rollNoList[empty]=roln;
                    // increase the count of students in database by 1
                    Student::incrementCount();

			        cout<<"Copy Constructor is called. The student is copied.\n";
                }

            }
            
        }
        // exception handling for choice
        // that is if he enters the value apart from 1 to 6
        else
        {
            cout<<"The choice you entered is invalid. Enter a choice 1 to 6."<<endl;
        }

            // Ask the user if he wants to continue
            cout<<"\n---------------------------------";
            cout<<"\nDo you want to continue?(y/n): ";
            string contin;
            cin>>contin;
            cout<<"---------------------------------\n";
            // if user enters 'n' the while loop is broken
            if (contin=="n" || contin=="N")
            {
                // delete is used to delete arrays personalInfoObject and studentObject
                // that is delete the database
                delete [] studentObject;
                delete [] personalInfoObject;
                break;
            }
            // else continue in the while loop
            else
            {
                continue;
            }
    }

    // Thank you is printed at the end of program and program ends
    cout<<"\nThank You for using the program.\n";
return 0;
}