/*
21132_Shreyash Halge
Code for OOPCG Lab/ Assignment 1/ version 2
*/

#include <iostream>
#include<limits> //for the error handling function
using namespace std;


class Complex   //Declaring class complex
{
    double real, imag;  //Declaring variables for real and imaginary parts

    public:        //Using 'public' as access specifier so other fuctions could use these constructors and functions
    Complex()      //Default constructor to assign the values 0.0 to real and imag
    {
        real=0.0;   //Assigning value 0.0+i0.0 as default value as given in the problem statement
        imag=0.0;   
    }
    Complex(double a, double b) //Parametrized constructor to assign desired values to real and imag
    {
        real=a;
        imag=b;
    }

    Complex operator+ (Complex c)   //Operator overloading for + operator
    {
        Complex temp;   //Creating temporary variable of type complex for storing result of addition
        temp.real=real+c.real;      //(a1+ib1)+(a2+ib2)=(a1+a2)+i(b1+b2)
        temp.imag=imag+c.imag;
        return temp;
    }

    Complex operator* (Complex c)   //Operator overloading for * operator
    {
        Complex temp;   //Creating temporary variable of type complex for storing result of addition
        temp.real=real*c.real-imag*c.imag;      //(a1+ib1)*(a2+ib2)=(a1*a2-b1*b2)+i(a1*b2+a2*b1)
        temp.imag=real*c.imag+imag*c.real;      
        return temp;
    }

    //Declaring friend functions for insersion(>>) and extraction(<<) operators. They are declared inside class and defined outside class
    friend istream& operator>> (istream&, Complex &);
    friend ostream& operator<< (ostream&, Complex &);

};

//We pass reference of istream and Complex type object 
istream& operator>> (istream& input, Complex &c)
{
    cout<<"Enter real and imaginary part of complex number(Space seperated): ";
    cin>>c.real;
    cin>>c.imag;
    return input;   //Insersion operator of return type "istream&" enables us to write multiple insertion operators in single line.
}

// We pass reference of ostream and Complex type object
ostream& operator<< (ostream& output, Complex& c)
{
    // For the proper display/representation of Complex number, the if else statement is used. When the imaginary part is negative, the negative sign is taken infront of 'i' and the absolute value of imaginary part follows it.
    if(c.imag>=0)
    {
        cout<<c.real<<"+i"<<c.imag;
    }
    else
    {
        cout<<c.real<<"-i"<<abs(c.imag); 
    }
    return output;  //Extraction operator of return type "ostream&" enables us to write multiple extraction operators in single line
}

// Driving code
int main()
{
        //INTRO OF THE PROGRAM
        cout<<"WELCOME!\nThis program adds or multiplies two complex numbers for you.\nYou need to enter two complex number and then choose a choice for addition or multiplication.\nYou can also use the default value for complex number i.e. (0+i0).\nLETS BEGIN!\n\n";

        //Declaring 4 Complex type objects
        Complex c1, c2, c3, c4;
        
        //Taking input of complex objects using insertion operator(>>) overloading
        cout<<"First complex number"<<endl;
        // Asks the user if he/she want to use the default value
        cout<<"Do you want to use default value(0+i0)?(y/n): ";
        char def_val;
        cin>>def_val;
        // If the user says 'n' then he/she is asked for input
        if (def_val=='n')
        {
            cin>>c1;
            //Exception handling: If user enters value other than int or double, it asks user to enter again 
            while(true){if(cin.fail()){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');  cout<<"You have entered wrong input. Enter numeric input: "<<endl;cin>>(c1);}if(!cin.fail())     {break;}}
        }
        

        cout<<"Second complex number"<<endl;
        // Asks the user if he/she want to use the default value
        cout<<"Do you want to use default value(0+i0)?(y/n): ";
        char def_val2;
        cin>>def_val2;
        // If the user says 'n' then he/she is asked for input
        if (def_val2=='n')
        {
            cin>>c2;
            //Exception handling: If user enters value other than int or double, it asks user to enter again 
            while(true){if(cin.fail()){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');  cout<<"You have entered wrong input. Enter numeric input: "<<endl;cin>>(c2);}if(!cin.fail())     {break;}}
        }

        //Calculating sum and product using + and * operator overloading
        c3=c1+c2;   //Addition result is stored in c3
        c4=c1*c2;   //Multiplication result is stored in c4

    //Running while loop till the user enters y(yes) as choice:
    char yn='y';
    while(yn='y')
    {
        //Taking input for choice from user to show sum or product
        cout<<"Enter 1 for addition and Enter 2 for multiplication"<<endl;
            
            int choice;
            cin>>choice;
            //Exception handling: If user enters value other than int or double, it asks user to enter again
            while(true){if(cin.fail()){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"You have entered wrong input. Enter numeric input: "<<endl;cin>>choice;}if(!cin.fail()){break;}}
        
        //if else statements to toggle between choices       
        if(choice==1)
        {
            //Display of sum using the extraction operator(implemented using operator overloading)
            cout<<"Sum of two given complex numbers is: "<<c3<<endl;
            // User is asked, if he wants to continue
            cout<<"Do you want to enter other choice(y/n): ";
            cin>>yn;
            //Exception handling: If user enters value other than character, it asks user to enter again
            while(true){if(cin.fail()){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"You have entered wrong input. Enter numeric input: "<<endl;cin>>yn;}if(!cin.fail()){break;}}
            if(yn=='n'){break;} //If the user enters 'n' then control comes out of the while loop
        }
        else if(choice==2)
        {
            //Display of product using the extraction operator(implemented using operator overloading)
            cout<<"Product of two given complex numbers is: "<<c4<<endl;
            // User is asked, if he wants to continue
            cout<<"Do you want to enter other choice(y/n): ";
            cin>>yn;
            //Exception handling: If user enters value other than character, it asks user to enter again
            while(true){if(cin.fail()){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"You have entered wrong input. Enter numeric input: "<<endl;cin>>yn;}if(!cin.fail()){break;}}
            if(yn=='n'){break;} //If the user enters 'n' then control comes out of the while loop
        }
        else //Exception handling: If user enters value other than 1 or 2
        {
            cout<<"Choice entered is invalid. Choose 1(addition) or 2(multiplication): ";
            cout<<"Do you want to enter other choice(y/n): ";
            cin>>yn;
            //Exception handling: If user enters value other than character, it asks user to enter again
            while(true){if(cin.fail()){cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');cout<<"You have entered wrong input. Enter numeric input: "<<endl;cin>>yn;}if(!cin.fail()){break;}}
            if(yn=='n'){break;} //If the user enters 'n' then control comes out of the while loop
        }
    }
    // Whenever the user enters 'n' and comes out of while loop, following message is displayed and program ends
    cout<<"THANK YOU FOR USING THE PROGRAM!"<<endl;
return 0;
}