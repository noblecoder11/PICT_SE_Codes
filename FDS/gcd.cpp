#include <bits/stdc++.h>
using namespace std;

int egcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return egcd(b, a%b);
}

int main()
{
    int a, b;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;
    cout<<egcd(a,b)<<endl;
return 0;
}


