#include <iostream>
using namespace std;
class Complex       //defining a class complex
{
    double real, imag; //Variables for class complex

    public:
    Complex()  //Default constructor assigns values 0.0 to both parameters
    {
        real=0.0;
        imag=0.0;
    }
    Complex(double x, double y)  //Parametrized constructor assigns the values passed as arguements(parameters)
    {        
        real=x;
        imag=y;
    }
    Complex operator+ (Complex c) //Operator overloading for + operator. So that we can use + operator to add complex numbers 
    {
        Complex temp;
        temp.real=real+c.real;                      //(a1+ib1)+(a2+ib2)=(a1+a2)+i(b1+b2)
        temp.imag=imag+c.imag;
        return temp;
    }
    Complex operator* (Complex c) //Operator overloading for * operator. So that we can use * operator to multiply complex numbers
    {
        Complex temp;
        temp.real=real*(c.real)-imag*(c.imag);      //(a1+ib1)*(a2+ib2)=(a1*a2-b1*b2)+i(a1*b2+b1*a2)
        temp.imag=real*(c.imag)+imag*(c.real);      
        return temp;
    }
   
    friend istream& operator>> (istream&, Complex&);    //declaring friend function for infix operator overloading
    friend ostream& operator<< (ostream&, Complex&);    //declaring friend function for outfix operator overloading
};

istream& operator>> (istream& din, Complex &c)      //defining function for operator overloading for >>(insertion) operator. So that we can use >> operator to input complex numbers
{
    cout<<"Enter real and imaginary part: ";
    din>>c.real;
    // cout<<"Enter imaginary part: ";
    din>>c.imag;
    return din;
}

ostream& operator<< (ostream& dout, Complex &c)     //defining function for operator overloading for <<(extraction) operator. So that we can use << operator to output complex numbers
{
    if(c.imag<0){cout<<c.real<<"-i"<<abs(c.imag);}
    return dout;
}

int main()      //driver code
{
    Complex c1, c2, c3, c4;
    cout<<"Enter two complex numbers\n";
    cin>>c1>>c2;

    cout<<"You entered: ";
    cout<<c1<<" "<<c2<<" and "<<endl;

    cout<<"Addition of complex numbers: ";
    c3=c1+c2;
    cout<<c3<<endl;
    
    cout<<"Multiplication of complex numbers: ";
    c4=c1*c2;
    cout<<c4<<endl;

return 0;
}