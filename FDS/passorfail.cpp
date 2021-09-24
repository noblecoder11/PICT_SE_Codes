#include <iostream>
using namespace std;

class student
{
    public:
    string name;
    int rollno;
    int marks[5];

    
    void read()
    {
        cin>>name;
        cin>>rollno;
        for (int i = 0; i < 5; i++)
        {
            cin>>marks[i];
        }
        
    }

    int average()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += marks[i];
        }
        return sum/(5.0);
        
    }

    bool isSuccess()
    {
        for (int i = 0; i < 5; i++)
        {
            if (marks[i]<35)
            {
                return false;
            }

        }
        
        if(average()<40)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    student a[2];
    for (int i = 0; i < 2; i++)
    {
        a[i].read();
    }

    for (int i = 0; i < 30; i++)
    {
        if(a[i].isSuccess())
        {
            cout<<a[i].name<<" "<<a[i].rollno<<endl;
        }
    }
    
    
    
return 0;
}