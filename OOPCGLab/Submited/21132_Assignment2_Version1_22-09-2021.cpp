// 21132_Shreyash Halge
// Code for OOPCG Lab / Assignment 2 / Version 1

#include <bits/stdc++.h>
#include <limits>
#include <ctime>
using namespace std;

// exception handling for roll number
int inputRollno()
{
    while (true)
    {
        cout<<"\nEnter the roll number: ";
        try
        {
            string temp;
            cin >> temp;
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
            return strnum;
            break;
        }
        catch (const char *msg)
        {
            cout << msg;
        }
    }

}

//print list of roll numbers of student in database
void printRNList(vector<int>v, int n)
{
    cout<<"List of students already present in list: [";
            for(int rn=0; rn<n; rn++)
            {
                if(v[rn] != 0){cout<<v[rn]<<", ";}
            }
            cout<<"]"<<endl;
}

// this function is used to get empty spot(where there is no student) in the vector 
int searchEmptySpot(vector<int> v, int n)
{
    for(int i=0; i<n; i++){
        if(v[i]==0){return i;}
    }
    return -1;
}

// this function gives the index of the roll no in vector
int getIndex(vector<int> v, int K)
{
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
private:
    string address;
    string dob;
    string bloodGroup;
    string licence;
public:
    personalInfo();
    personalInfo(personalInfo &);
    ~personalInfo();
    // Student is made friend class of class personalInfo, so that student can use private members of this class
    friend class Student;
};

// default constructor of class personalInfo
personalInfo::personalInfo()
{
    address="abc, xyz";
    dob="00/00/0000";
    bloodGroup="X+";
    licence="ABC00000";
}

// copy constructor of class personalInfo
personalInfo::personalInfo(personalInfo &obj)
{
    //this is a pointer points to the object which invokes it
    this->address=obj.address;
    this->dob=obj.dob;
    this->bloodGroup=obj.bloodGroup;
    this->licence=obj.licence;
}

// destructor of class personalInfo
personalInfo::~personalInfo()
{
    cout<<"Successfully deleted personal information of a student"<<endl;
}

// class student
class Student
{
private:
    string name;
    int rollno;
    int year;
    string division;
    string mobile;
public:
    Student();
    Student(Student&);
    ~Student();
    // static class variable and static class functions are declared and defined
    static int count;
    inline static void incrementCount(){Student::count++;};
    inline static void decrementCount(){Student::count--;};
    inline static void showCount(){cout<<"Total number of students: "<<Student::count;}

    //create method is used to create a student in database
    void create(personalInfo &obj, int rolno)
    {
        rollno=rolno;
        cout<<"\nEnter the details of the new student:";
        cout<<"\nNAME : ";
        cin.ignore();
        getline(cin, name);
        cout<<"\nYEAR : ";
        cin>>year;
        cout<<"\nDIVISION: ";
        cin>>division;

        // exception handling for mobile number
        while (true)
        {
            cout<<"\nPHONE NUMBER: ";
            try
            {
                string temp;
                cin >> temp;
                if (temp.length() != 10)
                {
                    throw "Telephone number must be 10 characters long\n";
                }
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
        cout<<"\nADDRESS : ";
        cin.ignore();
        getline(cin, obj.address);
        
        
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
            try
            {
                cout << "\nDATE OF BIRTH: (dd/mm/yyyy): ";
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
            cout<<"\nBLOOD GROUP: ";
            try
            {
                string temp;
                cin >> temp;
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

        cout<<"\nLICENCE NUMBER : ";
        cin>>obj.licence;
        incrementCount();
    }

    // display method is used to display the student with given roll number
    void display(personalInfo &obj)
    {
        cout<<"-------------------------"<<endl;
        cout<<"NAME OF STUDENT : "<<name<<endl;
        cout<<"ROLL NO : "<<rollno<<endl;
        cout<<"YEAR : "<<year<<endl;
        cout<<"DIVISION : "<<division<<endl;
        cout<<"PHONE NUMBER : "<<mobile<<endl;
        cout<<"ADDRESS OF STUDENT : "<<obj.address<<endl;
        cout<<"DATE OF BIRTH : "<<obj.dob<<endl;
        cout<<"BLOOD GROUP : "<<obj.bloodGroup<<endl;
        cout<<"LICENCE NUMBER : "<<obj.licence<<endl;
        cout<<"------------------------"<<endl;
    }

    // update method is used to update the data of student already present in database
    void update(personalInfo &obj, int rolno)
    {
        create(obj, rolno);
        cout<<"Student data updated successfully."<<endl;
    }

    // delete method is used to delete a student from the database
    void deleteStudent(personalInfo &obj)
    {
        obj.~personalInfo();
        this->~Student();
    }
};

// when we write this, the memory is allocated to stati variable count and is set to 0 for default
int Student::count;

// default constructor of class student
Student::Student()
{
    name="Name";
    rollno=0;
    year=0;
    division="SE0";
    mobile="0000000000";
}

// copy constructor of class student
Student::Student(Student &obj)
{
    // this is a pointer points to the object which invokes it
    this->name=obj.name;
    this->year=obj.year;
    this->division=obj.division;
    this->rollno=obj.rollno;
    this->mobile=obj.mobile;
}

// destructor of class student
Student::~Student()
{
    cout<<"Succesfully deleted student."<<endl;
}


// driver code 
int main()
{
    // taking input for maximum number of students in database
    cout<<"Enter the maximum number of students in your database: ";
    int n;
    cin>>n;

    // new is dynamic memory allocation operator, sobj is pointer of type student and it is a array of object of size n
    Student *sobj=new Student[n];
    // new is dynamic memory allocation operator, pobj is pointer of type student and it is a array of object of size n
    personalInfo *pobj=new personalInfo[n];
    // vector rollNoList stores the roll numbers of students in the database
    vector <int> rollNoList(n);
        

    while(true)
    {
        // information of program
        cout<<"Welcome to the student database portal!\nNow you can easily store and manage data of all your students.\n";
        cout<<"This program allows you to:\n1. Create a student\n2. Read the data previously stored.\n3. Update data of existing student.\n4. Delete an existing student.\n";

        cout<<"\nEnter the choice for respective operation which you want to perform(1 to 4): ";
        int choice;
        cin>>choice;
        
        if(choice==1)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);

            // Taking roll number of student as input
            cout<<"Enter the roll number of student you want to add: ";
            int rollno = inputRollno();
            
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
                    sobj[i].create(pobj[i], rollno);
                    Student::incrementCount();
                }
            }
            
        }
        else if(choice==2)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);
            
            // Taking roll number of student as input
            cout<<"Enter the roll number of student you want to dispay: ";
            int rollno = inputRollno();
                        
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            int i=getIndex(rollNoList, rollno);
        
            if(i==-1)
            {
                cout<<"Student with the given roll number do not exist in database. Enter another roll number or add a new student with given roll number."<<endl;
            }
            else
            {
                sobj[i].display(pobj[i]);
            }            
            
        }
        else if(choice==3)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);
            
            // Taking roll number of student as input
            cout<<"Enter the roll number of student you want to update: ";
            int rollno= inputRollno();
                        
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            int i=getIndex(rollNoList, rollno);

            if(i ==-1)
            {
                cout<<"Student with the given roll number do not exist in database. Enter another roll number or add a new student with given roll number."<<endl;
            }
            else
            {
                // display the previous details
                cout<<"Here are the details you entered previously for this roll number:"<<endl;
                sobj[i].display(pobj[i]);

                // input new roll number to be given
                cout<<"Enter the roll number you want to give to the student: ";
                int rollNo=inputRollno();
                
                // updating student
                sobj[i].update(pobj[i], rollNo);
                rollNoList[i]=rollNo;
            }
            
        }
        else if(choice==4)
        {
            // Printing the list of students already present in database
            printRNList(rollNoList, n);

            // Taking roll number of student as input
            cout<<"Enter the roll number of student you want to delete: ";
            int rollno= inputRollno();
            
            // When getIndex returns -1, it means that the roll number is not present. So when getIndex!=-1, it means that roll number is already present in list
            int i=getIndex(rollNoList, rollno);
            
            if(i ==-1)
            {
                cout<<"Student with the given roll number do not exist in database. Enter another roll number or add a new student with given roll number."<<endl;
            }
            else
            {
                sobj[i].deleteStudent(pobj[i]);
                rollNoList[i]=0;
                Student::decrementCount();      //inline static function is used
            }
        }
        else
        {
            cout<<"The choice you entered is invalid. Enter a choice 1 to 4."<<endl;
        }

            cout<<"\nDo you want to continue?(y/n): ";
            string contin;
            cin>>contin;
            if(contin=="n" || contin=="N")
            {
                // delete is used to delete arrays pobj and sobj
                delete pobj;
                delete sobj;
                break;
            }
            else{continue;}
    }
    
    cout<<"\nThank You for using the program.";
return 0;
}