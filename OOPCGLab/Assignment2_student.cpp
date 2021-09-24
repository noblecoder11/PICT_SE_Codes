//21132_Shreyash Halge
/*
Problem statement:
Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the
database with suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member functions, friend
class, this pointer, inline code and dynamic memory allocation operators-new and delete.
*/
#include<iostream>			//header file used for cin and cout
#include<string.h>			//header file for string class
using namespace std;			//refer cin and cout
#define max 100;

class personal_info								//stud_info is friend class of per_info
{
    string licence, dob, bldgrp;    //personal info variables
    public:
    personal_info()                //DEFINITION AND DECLARATION DEFAULT CONSTRUCTOR//
    {
       licence="ABC00000";
       dob="00/00/0000";
       bldgrp="Bloodgroup";
    }
    personal_info(personal_info &obj)       //DEFINITION AND DECLARATION OF COPY CONSTRUCTOR//
    {
      licence=obj.licence;
      dob=obj.dob;
      bldgrp=obj.bldgrp;
    }
    ~personal_info()                 //DEFINITION AND DECLARATION OF DESTRUCTOR
    {
          cout<<"\nDESTRUCTOR IS CALLED!!!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl;
    }
    friend class student;                     //FRIEND FUNCTION DECLARATION
};

class student   							//DEFINITION OF STUDENT CLASS
{
    string name, address, year;				//OBJECTS OF STRING CLASS
    string div;
    int roll_no;
    long mob;
    static int cnt; 						//    STATIC VARIABLE DECLARATION

    public:

    //TO CREATE THE DATABASE
    //DEFINTION OF CREATE FUNTION
    void create(personal_info &obj)
    {
         
         cout<<"\nEnter the details of the new student.";
         cout<<"\nNAME : ";
         cin>>name;
         cout<<"\nADDRESS : ";
         cin>>address;
         cout<<"\nDATE OF BIRTH : ";
         cin>>obj.dob;
         cout<<"\nYEAR : ";
         cin>>year;
         cout<<"\nDIVISION: ";
         cin>>div;
         cout<<"\nROLL NUMBER : ";
         cin>>roll_no;
         cout<<"\nBLOOD GROUP : ";
         cin>>obj.bldgrp;
         cout<<"\nLICENCE NUMBER : ";
         cin>>obj.licence;
         cout<<"\nPHONE NUMBER : ";
    cin>>mob;
    }
    
        //DEFINTION OF DISPLAY FUNCTION
    //TO DISPLAY DATABASE
    void display(personal_info &obj)
    {
        cout<<"-------------------------"<<endl;
        cout<<"NAME OF STUDENT : "<<name<<endl;
        cout<<"ADDRESS OF STUDENT : "<<address<<endl;
        cout<<"DATE OF BIRTH : "<<obj.dob<<endl;
        cout<<"YEAR : "<<year<<endl;
        cout<<"DIVISION : "<<div<<endl;
        cout<<"ROLL NO : "<<roll_no<<endl;
        cout<<"BLOOD GROUP : "<<obj.bldgrp<<endl;
        cout<<"LICEINCE NUMBER : "<<obj.licence<<endl;
        cout<<"PHONE NUMBER : "<<mob<<endl;
        cout<<"------------------------"<<endl;
    }
 

    inline static void inccnt()                //STATIC FUNCTION//
    {
      cnt++;
    }
    inline static void showcnt()               //STATIC FUNCTION// //INLINE FUNCTION//
    {
      cout<<"\nTOTAL NO OF RECORDS ARE : "<<cnt;
    }

    student()                 //DEFAULT CONSTRUCTOR//
    {
          name="Name";
          address="ABC, XYZ";
          year="year";
          div="div";
          roll_no=0;
          mob=0;
    }                     
    student(student &obj)     //COPY CONSTRUCTOR OF STUDENT CLASS//
    {
      this->name=obj.name;			//this is a pointer points to the object which invokes it
      this->address=obj.address;	      //this-> can be written as name
      this->year=obj.year;
      this->div=obj.div;
      this->roll_no=obj.roll_no;
      this->mob=obj.mob;
    }                  
    ~student()                          //DESTRUCTOR OF STUDENT CLASS//
    {
       cout<<"\nDESTRUCTOR IS CALLED!!!"<<endl<<"RECORD DELETED SUCCESSFULLY"<<endl;
    }

};
 
int student::cnt;

int main()
{
 int n;				//COUNT OF NUMBER OF STUDENTS
 int ch;
 char ans;
 
 cout<<"\nENTER NO OF STUDENTS :"<<endl;
 cin>>n;
 cout<<"\n-----------------------"<<endl;
 student *studentObj=new student[n];				//NEW IS DYNAMIC MEMORY ALLOCATION OPERATOR, studentObj IS POINTER OF TYPE STUDENT AND IT IS A ARRAY OF OBJECT OF SIZE n
 personal_info *pobj=new personal_info[n];		//NEW IS DYNAMIC MEMORY ALLOCATION OPERATOR, pobj IS POINTER OF TYPE STUDENT AND IT IS A ARRAY OF OBJECT OF SIZE n
 
 do
 {
	 cout<<"\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)";
	 cout<<"\n Enter your Choice: ";
	 cin>>ch;
	 switch(ch)
	 {
	 case 1: // create database
	 {
		 for(int i=0;i<n;i++)
		 {
		       studentObj[i].create(pobj[i]);
		       studentObj[i].inccnt();
          
		 }
	 }
		break;
 	 case 2: // Display Database
  		{
			studentObj[0].showcnt(); 	//to display the total count of students
			//we can use any object of student class as it is static member function
			 for(int i=0;i<n;i++)
			 {
				 studentObj[i].display(pobj[i]);
			 }
    	      }
    	 break;
	  case 3: // Copy Constructor
		{
			 student obj1;
			 personal_info obj2;
			 obj1.create(obj2);
			 student obj3(obj1);		//invoking copy constructor of student info to copy contents from object 1 to 3
 
			 personal_info obj4(obj2);		 //invoking copy constructor of personal info to copy contents from object 2 to 4
			 cout<<"\n Copy Constructor is called ";
			 obj3.display(obj4);
 		}
        break;
	 case 4: // Default Constructor
 		{
			 student obj1;	//obj1 is invoking default constructor of class student
			 personal_info obj2;	//obj2 is invoking default constructor of class personal
			 cout<<"\n Default Constructor is called ";
			 obj1.display(obj2);
 		}
 		break;
	 case 5: // destructor is called
            {
			     delete [] studentObj;			//invoking destructor and delete studentObj dynamically
 		       delete [] pobj;		//invoking destructor and delete pobj dynamically
      	}
      }                        //end of switch case
 	cout<<"\n Do you want to continue(y/n): ";
 	cin>>ans;
  }while(ans=='y');
 
 
 return 0;
}
