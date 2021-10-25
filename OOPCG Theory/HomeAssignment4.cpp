#include <iostream>
using namespace std;

class vector
{
private:
    int size;
    int currentSize;
    int *arr;

public:
    vector(int);
    ~vector();

    friend istream &operator>>(istream &input, vector &obj)
    {
        input >> *(obj.arr);
        return input;
    }

    friend ostream &operator<<(ostream &output, vector obj)
    {
        output << obj.arr;
        return output;
    }

    int &operator[](int index)
    {
        if (index >= size)
        {
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        return arr[index];
    }

    float operator*(float x1)
    {
        return x1 * (*arr);
    }

    void pushBack(int x)
    {
        if (currentSize == size)
        {
            int temp[size];
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            size++;
            currentSize++;
            delete[] arr;
            arr = new int[size];
            for (size_t i = 0; i < size - 1; i++)
            {
                arr[i] = temp[i];
            }
            arr[size - 1] = x;
        }
        else
        {
            arr[currentSize] = x;
            currentSize++;
        }
    }

    int pop()
    {
        int temp = arr[currentSize - 1];
        arr[currentSize - 1] = 0;
        currentSize--;
        return temp;
    }
};

vector::vector(int size = 0)
{
    this->size = size;
    this->currentSize = size;
    arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

vector::~vector()
{
    delete[] arr;
}

int main()
{
    vector v1(10);
    v1[1] = 10;
    cin >> v1[1] >> v1[2];
    cout << v1[1] << " " << v1[2] << endl;
    v1[2] = 2 * v1[2];
    cout << v1[2] << endl;
    v1.pushBack(10);
    cout << v1[10] << endl;
    cout << v1.pop() << endl;
    v1.pushBack(15);
    cout << v1[10] << endl;
    v1.pushBack(12);
    cout << v1[11] << endl;
    return 0;
}