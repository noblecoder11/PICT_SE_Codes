#include <iostream>
using namespace std;

template <typename T>
class vector {
    T arr[100] = {0};
    int count = 0;

    public:
    void pushBack(T data) {
        arr[count] = data;
        count++;
    }

    void pop() {
        arr[count] = 0;
        count--;
    }
    

};

int main()
{
    
return 0;
}