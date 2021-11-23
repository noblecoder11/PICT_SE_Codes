#include <bits/stdc++.h>
using namespace std;

template <typename T>
void selectionSort(T arr[])
{
    int n = len(arr);
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

void inputArray()
{
    // input data type
    // no of elements
    // exception handling
}

int main()
{
    // main menu
    while (true)
    {
        cout<<"\n-------- MAIN MENU ---------\n";
        cout<<"1. Input new array\n2. Sort the array\n3. Print the array\n4. Exit\n";
        cout<<"Enter your choice: ";
        string choice;
        cin>>choice;

        if (choice=="1")
        {
            arr = inputArray();
        }
        else if (choice=="2")
        {
            selectionSort(arr);
        }
        else if (choice=="3")
        {

        }
        else if (choice=="4")
        {

        }
        else
        {

        }
    }
    
    
        
return 0;
}