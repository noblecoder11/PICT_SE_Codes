#include <iostream>
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
        Inventory1::code=code;
        Inventory1::item=item;
        Inventory1::price=price;
    }
    operator float()
    {
        float temp;
        temp = price*item;
        return temp;
    }

    void show(){
        cout<<"Code: "<<code<<endl;
        cout<<"item: "<<item<<endl;
        cout<<"price: "<<price<<endl;
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
    int getCode()
    {
        return code;
    }
    float getValue()
    {
        return value;
    }
    Inventory2()
    {
        code=0;
        value=0;
    }

    Inventory2(int code, float value)
    {
        Inventory2::code=code;
        Inventory2::value=value;
    }

    void operator=(Inventory1 obj)
    {
        this->code = obj.getCode();
        this->value= obj.getItem() * obj.getPrice();
    }

    void show()
    {
        cout<<"Code: "<<Inventory2::code<<endl;
        cout<<"Value: "<<Inventory2::value<<endl;
    }
};


int main()
{
Inventory1 obj(100, 5, 140.7);
double total_value;
total_value=obj;
obj.show();

Inventory2 o;
o=obj;
o.show();
return 0;
}