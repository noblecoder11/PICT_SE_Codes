#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the number of test cases: ";
    int t;
    cin>>t;
    while(t--){
        int arr[10]={1,2,3,4,5,6,7,8,9,10};
        int* ptr=arr;
        int x;
        int pos=-1;
        cout<<"Enter the element you want to search: ";
        cin>>x;
        for(int i=0; i<10; i++)
        {
            if(*ptr==x){pos =i; break;}
            ptr++;
        }

        if(pos==-1){cout<<"Element dooesn't exists."<<endl;}
        else{cout<<"Element is at position: "<<pos<<endl;}
    }
return 0;
}