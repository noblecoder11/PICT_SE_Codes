# Code for insertion sort
# optional parameter iterations is used to give a choice of printing the list at each iteration
def insertionSort(arr, iterations=None):
    iterLists = []      # to store the list at each iteration

    for i in range(1, len(arr)):

        key = arr[i]    # key is the current element under consideration

        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

        # appending the list at each iteration. 'list(arr)' is used to pass the list not referrence
        iterLists.append(list(arr))

    if iterations == True:      # printing the list at all iterations
        print("Number of iterations: ", len(iterLists))
        for lists in iterLists:
            print(lists)



# Code for Shell Sort
def shellSort(arr, passes=None):
    passLists = []      # to store the list at each pass

    n = len(arr)
    interval = n // 2   # initializing interval
    while interval > 0:
        # sorting elements at 'interval' using insertion sort
        for i in range(interval, n):
            key = arr[i]
            j = i
            while j >= interval and key < arr[j - interval]:
                arr[j] = arr[j - interval]
                j -= interval
            arr[j] = key
        interval //= 2  # halving interval

        # appending the list at each iteration. 'list(arr)' is used to pass the list not referrence
        passLists.append(list(arr))

    if passes == True:      # printing the list at all iterations
        print("Number of passes: ", len(passLists))
        for lists in passLists:
            print(lists)



# Code for getting top 5
def topFive(arr):
    n = len(arr)
    # sorting the arrau without printing the list at each pass
    shellSort(arr)
    for i in range(1, 6):
        print(arr[n-i])



# Function to check if all the elements in list are in correct format
def checkArr(arr):
    # check for length of array
    if (len(arr) < 5):
        print("Number of elements should be greater than 5")
        return False
    # check for range of elements
    for i in range(len(arr)):
        if 0 <= arr[i] <= 100:
            pass
        else:
            print("All percentages should be in range 0 to 100")
            return False
    return True


# MAIN MENU
print("Hi. This program allows you to sort the list using insertion and shell sort.")

arr = []
originalArr = list(arr)

while True:
    print("-" * 30)
    print("1. Insertion sort\n2. Shell Sort\n3. Print top 5\n4. Enter new list\n5. Exit\n")

    choice = input("Enter your choice: ")
    if choice == "1":
        # True is passed as parameter to print the list at each iteration
        insertionSort(arr, True)
        print("You entered: ", originalArr)
        print("Sorted arr: ", arr)
        # Unsorting the list for next function so that it doesn't sort the sorted list again
        arr = list(originalArr)
    elif choice == "2":
        shellSort(arr, True)
        print("You entered: ", originalArr)
        print("Sorted arr: ", arr)
        arr = list(originalArr)
    elif choice == "3":
        topFive(arr)
    elif choice == "4":
        tempArr = list(
            map(float, input("Enter a list (SPACE SEPARATED): ").split()))
        if checkArr(tempArr):
            arr = list(tempArr)
            originalArr = list(tempArr)
    elif choice == "5":
        print("Thank you")
        break
    else:
        print("Enter a valid choice(1 to 5).")