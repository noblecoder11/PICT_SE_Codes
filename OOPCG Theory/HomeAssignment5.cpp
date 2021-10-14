#include <bits/stdc++.h>
using namespace std;
class Inventory1
{
    int code;
    int item;
    float price;

    public:
    Inventory1()
    {
        code=0; item=0; price=0;
    }
    Inventory1(int code, int item, float price)
    {
        code=code;
        item=item;
        price=price;
    }
    operator float()
    {
        float temp;
        temp= price*item;
        return temp;
    }

    void show(){
        cout<<"Code: "<<code;
        cout<<"item: "<<item;
        cout<<"price: "<<price;
    }
    int getCode(){return code;}
    int getItem(){return item;}
    float getPrice(){return price;}
};

class Inventory2
{
    int code;
    float value;
    public:
    Inventory2()
    {
        code=0;
        value=0;
    }

    Inventory2(int code, float value)
    {
        code=code;
        value=value;
    }

    void show()
    {
        cout<<"Code: "<<code;
        cout<<"Value: "<<value;
    }
};


int main()
{
Inventory1 obj(100, 5, 140.8);
double total_value;
total_value=obj;

Inventory2 o;
o=obj;
o.show();
return 0;
}