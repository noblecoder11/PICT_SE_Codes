#include <bits/stdc++.h>
using namespace std;

int main()
{
    int age, income, vehicle;
    string city;

    cout<<"\nEnter age: ";
    cin>>age;
    cout<<"\nEnter income: ";
    cin>>income;
    cout<<"\nEnter no of wheels in vehicle: ";
    cin>>vehicle;
    cout<<"\nEnter city: ";
    cin>>city;

    bool validAge = age>=18 && age<=55;
    bool validIncome = income>=50000 && income<=100000;
    bool validVehicle = vehicle==4;
    bool validCity = (city == "Pune" || city == "Mumbai"||city == "Bangalore" || city == "Chennai");

    try
    {
        if (!validAge || !validIncome || !validVehicle || !validCity)
       {
           throw 10;
       } 
       cout<<"Done"<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';

    }
    
return 0;
}