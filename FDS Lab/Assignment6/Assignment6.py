# parameter 'currArr' decides whether states of arrays after each step is printed or not
def partition(start, end, arr, currArr):
    pivot = arr[end]
    
    pivotIndex = start

    for i in range(start, end):
        if arr[i] <= pivot:
            arr[pivotIndex], arr[i] = arr[i], arr[pivotIndex]
            pivotIndex += 1

    arr[pivotIndex], arr[end] = arr[end], arr[pivotIndex]

    if currArr:
        print(f"pivot: {pivot}, list: {list(arr)}")
 
    return pivotIndex
     
def quickSort(start, end, array, currArr):
    
    if (start < end):
        # partition returns index of pivot element
        p = partition(start, end, array, currArr)

        quickSort(start, p - 1, array, currArr)
        quickSort(p + 1, end, array, currArr)

def topFive(arr):
    n = len(arr)
    # false is given as parameter as we don't want to print arrays during sorting process
    quickSort(0, len(arr)-1, arr, False)
    print("Top Five Percentages are: ")
    for i in range(1, 6):
        print(f"Rank {i}: ", arr[n-i])

def checkArr(arr):
    # if less than 5 elements are entered
    if (len(arr) < 5):
        print("Number of elements should be greater than 5")
        return False
    # if all percentages are not in range 0 to 100
    for i in arr:
        if not (0 <= i <= 100):
            print("All percentages should be in range 0 to 100")
            return False
    return True


# MAIN MENU
arr = []
originalArr = list(arr)

while True:
    print("\n-------- MAIN MENU --------\n")
    print("1. Enter new List\n2. Quick Sort \n3. Top Five\n4. Exit\n")

    choice = input("Enter your choice: ")
    if choice == "1":
        tempArr = list(map(float, input("Enter a list (SPACE SEPARATED): ").split()))
        if checkArr(tempArr):
            arr = list(tempArr)
            originalArr = list(tempArr)
    elif choice == "2":
        # True is passed as parameter to print the list at each iteration
        print("You entered: ", originalArr)
        quickSort(0, len(arr)-1, arr, True)
        print("Sorted arr: ", arr)
        # Unsorting the list for next function so that it doesn't sort the sorted list again
        arr = list(originalArr)
    elif choice == "3":
        topFive(arr)
    elif choice == "4":
        print("Thank you")
        break
    else:
        print("Enter a valid choice(1 to 4)")