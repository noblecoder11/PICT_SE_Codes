#include <bits/stdc++.h>
using namespace std;

class student
{
    string name;
    int rollno;
    float marks[5];
    public:
    float percentage(){
        float percent;
        for (int i = 0; i < 5; i++)
        {
            percent+=marks[i];
        }
        percent = percent*20;
        return percent;
    }
};
int main()
{
    student 
return 0;
}