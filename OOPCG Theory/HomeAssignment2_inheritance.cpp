///////////////////////////////////////////////////////////////////////////////////
// 1. SINGLE INHERITANCE
#include <bits/stdc++.h>
using namespace std;

class math
{
protected:
    int a, b;
public:
    void accept()
    {
        cout<<"Enter two numbers: ";
        cin>>a;
        cin>>b;
    }
};

class addition: public math
{
public:
    int add()
    {
        return a+b;
    }
};
int main()
{
    addition a;
    a.accept();
    cout<<"Sum is"<<a.add()<<endl;
return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// 2. MULTI LEVEL INHERITANCE
class A
{
    int 
}