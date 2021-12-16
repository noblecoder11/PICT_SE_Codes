// C++ program for implementation of selection sort
#include <bits/stdc++.h>
using namespace std;

template <typename T>  // template is used so that function can be used for any data type
void selectionSort(T arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

		// Swap the found minimum element with the first element        
        T temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
	}
}

/* Function to print an array */
template <typename T>
void printArray(T arr[], int size) {
	for (int i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// function for taking size of array input. exception handling is done in this fuction
int inputSize() {
    int n;
    while (true)
    {
        cout<<"Enter number of elements in array: ";
        // try throw catch is used
        try
        {
            string temp;
            cin >> temp;
            stringstream elem (temp);  // stringstream used to convert string to int
            int intTemp;
            elem >> intTemp;

            // element should be integer value only
            if (to_string(intTemp) != temp) {
                throw "Enter Integer value only.\n";
            }
            if (!(intTemp > 0)) {
                throw "Enter value greater than 0.\n";
            }
            n = intTemp;
            break;
        }
        catch (const char *msg)
        {
            cout << msg;
        }
    }
    return n; // returning size of array
}

void inputIntegerArr(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter element " << i << ": ";
            // try throw catch is used
            try
            {
                string temp;
                cin >> temp;
                stringstream elem (temp);   // stringstream used to convert string to int
                int intTemp;
                elem >> intTemp;

                // element should be integer value only
                if (to_string(intTemp) != temp) {
                    throw "Enter Integer value only.\n";
                }

                arr[i] = intTemp;
                break;
            }
            catch (const char *msg)
            {
                cout << msg;
            }
        }
    }
    
}

void inputFloatArr(float arr[], int n) {

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Enter element " << i << ": ";
            // try throw catch is used
            try {
            
                float temp;
                cin>>temp;
                // if exception is caught while taking input
                if (cin.fail()) {
                    // element should be floating point value only
                    throw "Enter Floating point value only.\n";
                }

                arr[i] = temp; // assigning the value to arr[i]
                break;

            } catch (const char *msg) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << msg;
            }
        }
    }
}

// Driver program / main fuction
int main()
{
    while(true) {
        cout<<"\n-------- MAIN MENU ---------\n";
        cout<<"1. Sort integer array\n2. Sort float array\n3. Exit\n";
        cout<<"Enter your choice: ";
        string choice; // string is used to avoid exceptions
        cin>>choice;

        if (choice == "1") {

            int n = inputSize();  // size of array
            
            int intArr[n];  // array for taking input from user
            
            inputIntegerArr(intArr, n); // function inputs the array and used for exception handling
            
            cout << "\nArray entered successfully." <<endl;
            
            cout << "\nArray you entered is: ";
            printArray<int>(intArr, n);
            
            selectionSort<int>(intArr, n);

            cout << "\nArray after sorting is: ";
            printArray(intArr, n);
            
        } else if (choice == "2") {
            
            int n = inputSize();  // size of array
            
            float floatArr[n];  // array for taking input from user

            inputFloatArr(floatArr, n); // function inputs the array and used for exception handling

            cout << "\nArray entered successfully." <<endl;

            cout << "\nArray you entered is: ";
            printArray<float>(floatArr, n);
            
            selectionSort<float>(floatArr, n);

            cout << "\nArray after sorting is: ";
            printArray<float>(floatArr, n);

        } else if (choice=="3") {
            
            cout<<"\nThank you. Exiting..."<<endl;
            break;

        } else {  // for exception handling
            
            cout<<"\nEnter valid choice (1 to 3).\n"<<endl;
        
        }
    }
}