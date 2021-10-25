#include <bits/stdc++.h>

using namespace std;

class Inventory1
{
    int code, item;
    double price;

public:
    Inventory1(int c, int i, double p)
    {
        code = c;
        item = i;
        price = p;
    }
    operator double()
    {
        return price * item;
    }
    int getCode()
    {
        return code;
    }
    int getItem()
    {
        return item;
    }
    double getPrice()
    {
        return price;
    }
};

class Inventory2
{
    int code;
    double value;

public:
    void operator=(Inventory1 obj)
    {
        this->code = obj.getCode();
        this->value= obj.getItem() * obj.getPrice();
    }

    double show()
    {
        return value;
    }
};

int main()
{
    Inventory1 obj(100, 5, 140.8);
    double total_price = obj;
    //first half
    cout << "Using Inventory1 = " << total_price << endl;

    //second half
    Inventory2 o;
    o = obj;
    cout<<"Using Inventory2 = "<<o.show()<<endl;
}
