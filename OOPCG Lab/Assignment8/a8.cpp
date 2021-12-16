// Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array

#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
    void selectionSort();
};

// constructor for class 'Array'
template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

// method to print object of class 'Array'
template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}

// method for selection sort
template <typename T>
void Array<T>::selectionSort()
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (*(ptr + j) < *(ptr + min_idx))
                min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(*(ptr + min_idx), *(ptr + i));
    }
}

void inputIntegerArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    return;
}

void inputFloatArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    return;
}

int main()
{
    while(true) {
        cout<<"\n-------- MAIN MENU ---------\n";
        cout<<"1. Sort integer array\n2. Sort float array\n3. Exit\n";
        cout<<"Enter your choice: ";
        string choice;
        cin>>choice;

        if (choice == "1") {
            int sizeOfArr;  // size of array
            cin>>sizeOfArr;
            int intArr[sizeOfArr];  // array for taking input from user 
            inputIntegerArray(intArr, sizeOfArr); // function inputs the array and used for exception handling
            Array<int> a(intArr,sizeOfArr); // creating a object of class Array using 'int' datatype instead of typename T
            cout << "\nArray entered successfully" <<endl;
            a.selectionSort();
            a.print();
        } else if (choice == "2") {
            int sizeOfArr;
            cin>>sizeOfArr;
            float floatArr[sizeOfArr];
            inputFloatArray(floatArr, sizeOfArr);
            Array<float> a(floatArr,sizeOfArr);
            cout << "\nArray entered successfully" <<endl;
            a.selectionSort();
            a.print();
        } else if (choice=="3") {
            cout<<"Thank you. Exiting..."<<endl;
            break;
        } else {
            cout<<"Enter valid choice (1 to 4)"<<endl;
        }
    }

return 0;
}