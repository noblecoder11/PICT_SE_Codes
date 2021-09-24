#include <bits/stdc++.h>
using namespace std;

class calculator
{
    public:
    int addition(int a, int b)
    {
        return a+b;
    }

    int subtraction(int a, int b)
    {
        return a-b;
    }

    int multiplication(int a, int b)
    {
        return a*b;
    }

    int division(int a, int b)
    {
        return a/(double)b;
    }

    int modulus(int a, int b)
    {
        return a%b;
    }
};

int main()
{
  int a,b;
  cout<<"Enter first number: ";
  cin>>a;
  cout<<"Enter second number: ";
  cin>>b;

  calculator c;
  cout<<"Addition of numbers: "<<c.addition(a,b)<<"\n";
  cout<<"Subtraction of numbers: "<<c.subtraction(a,b)<<"\n";
  cout<<"Multiplication of numbers: "<<c.multiplication(a,b)<<"\n";
  cout<<"Division of numbers: "<<c.division(a,b)<<"\n";
  cout<<"Modulus of numbers: "<<c.modulus(a,b)<<"\n";

return 0;
}

