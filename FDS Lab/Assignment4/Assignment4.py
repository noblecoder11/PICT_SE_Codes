def linearSearch(arr, k):
    for i in range(len(arr)):
        if arr[i]==k:
            return (f"{k} is present at index {i}.")
    return (f"Roll number not found.")  # We will come here if the element is not found

def sentinelSearch(arr, k):
    n=len(arr)
    last = arr[n - 1]   # Storing last number in 'last'
    arr[n - 1] = k  # Replacing last number with number we are searching
    i = 0

    while (arr[i] != k):
        i += 1
    
    arr[n - 1] = last
 
    if ((i<n-1) or (arr[n-1] == k)):
        return (f"{k} is present at index {i}.")
    else:
        return ("Roll number not found.")
    
def binarySearch(arr, k):
    # initializing left and right
    left=0
    right=len(arr)-1

    while left <= right:
        mid = left + (right - left) // 2;   # this is used instead of "(left+right)//2" to avoid errors for large values of right and left
        if arr[mid] == k:
            return (f"The roll number {k} is present at index {mid}.")
        elif arr[mid] < k:  # If element is in right half
            left = mid + 1
        else:               # If element is in left half
            right = mid - 1
      
    return ("Roll number not found.")   # if number is not found in array

def fibonacciSearch(arr, k):
    n=len(arr)
    fibm2 = 0  # (m-2)'th Fibonacci No.
    fibm1 = 1  # (m-1)'th Fibonacci No.
    fib = fibm2 + fibm1  # m'th Fibonacci No.
 
    # Setting fib to the maximum fibonacci less than n
    while (fib < n):
        fibm2 = fibm1
        fibm1 = fib
        fib = fibm2 + fibm1
 
    # Marks the eliminated range from front
    offset = -1
 
    # when fib<=1, fibm1 adn fib2 becomes 0
    while (fib > 1):
        # Check if fibm2 is a valid location
        i = min(offset+fibm2, n-1)
 
        # if element is present in right part of array
        if (arr[i] < k):
            fib = fibm1
            fibm1 = fibm2
            fibm2 = fib - fibm1
            offset = i
            
        # if element is present in left part of array
        elif (arr[i] > k):
            fib = fibm2
            fibm1 = fibm1 - fibm2
            fibm2 = fib - fibm1

        # if element is found
        else:
            return (f"Roll number {k} found at index {i}.")

    # comparing with last element
    if (fibm1 and arr[n-1] == k):
        return (f"Roll number {k} found at index {n-1}.")
 
    return ("Roll number not found.")   # if number is not found


#MAIN MENU
print("This program searches the roll number in the list of students using:\n1. Linear Search\n2. Sentinial Search\n3. Binary Search\n4. Fibonacci Search\n")

# Input the list for random order search
arr=list((map(int, input("Enter the list of roll number of students in RANDOM order (space separated): ").split())))

#ask user whether he wants to use same list or enter new list 
print("1. Sort the same list\n2. Enter new sorted list")
sortedChoice=int(input("Enter your choice: "))
if sortedChoice==1:
    sortedArr=sorted(arr)
else:
    sortedArr=list((map(int, input("Enter the list of roll number of students in SORTED ORDER (space separated): ").split())))

# while loop till break is called
while True:
    # Print the lists
    print("-"*20)
    print("The list you entered is: ", arr)
    print("Sorted list: ", sortedArr)

    # Taking choice as input
    print("1. Linear Search\n2. Sentinel Search\n3. Binary Search\n4. Fibonacci Search\n5. Exit")
    choice=int(input("Enter a choice: "))

    # Linear search
    if choice==1:
        k=int(input("Enter the roll number you want to search: "))
        print()
        print(linearSearch(arr, k))

    #Sentinel Search
    elif choice==2:
        k=int(input("Enter the roll number you want to search: "))
        print()
        print(sentinelSearch(arr, k))

    # Binary Search
    elif choice==3:
        k=int(input("Enter the roll number you want to search: "))
        print()
        print(binarySearch(sortedArr, k))

    # Fibonacci Search
    elif choice==4:
        k=int(input("Enter the roll number you want to search: "))
        print()
        print(fibonacciSearch(sortedArr, k))

    # Exit
    elif choice==5:
        print("Thank you.")
        break

    # Exception Handling
    else:
        print()
        print("Enter a valid choice(1 to 5).")
    print("-"*20)