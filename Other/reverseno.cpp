// #include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a,ra=0;
    int temp;
    // scanf("%d",&a);
    cin>>a;
    while(a>0)
    {
        temp=a%10;
        printf("%f",temp);
        ra=ra*10+temp;  
        a=a/10;
    }
    printf("%d",ra);

    return 0;
}