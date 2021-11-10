# This Function handles sorting part of quick sort start and end points to first and last element of an array respectively
def partition(start, end, array):
    
    pivot = array[end]

  # pointer for greater element
    pivotIndex = start - 1

  # traverse through all elements
  # compare each element with pivot
    for j in range(start, end):
        if array[j] <= pivot:
      # if element smaller than pivot is found
      # swap it with the greater element pointed by i
            pivotIndex = pivotIndex + 1

      # swapping element at i with element at j
        (array[pivotIndex], array[j]) = (array[j], array[pivotIndex])

  # swap the pivot element with the greater element specified by i
    (array[pivotIndex + 1], array[end]) = (array[end], array[pivotIndex + 1])

  # return the position from where partition is done
    return pivotIndex + 1

    # Initializing pivot's index to start
    # pivot_index = start
    # pivot = array[pivot_index]
      
    # # This loop runs till start pointer crosses end pointer, and when it does we swap the pivot with element on end pointer
    # while start < end:
          
    #     # Increment the start pointer till it finds an element greater than  pivot 
    #     while start < len(array) and array[start] <= pivot:
    #         start += 1
              
    #     # Decrement the end pointer till it finds an element less than pivot
    #     while array[end] > pivot:
    #         end -= 1
    #     # If start and end have not crossed each other, swap the numbers on start and end
    #     if(start < end):
    #         array[start], array[end] = array[end], array[start]
    # # print("List after iteration is: ", arr)  
    # # Swap pivot element with element on end pointer.This puts pivot on its correct sorted place.
    # array[end], array[pivot_index] = array[pivot_index], array[end]
     
    # # Returning end pointer to divide the array
    # return end
      
# The main function that implements QuickSort 
def quickSort(start, end, array, iterations = None):
    
    if (start < end):
          
        # p is partitioning index, array[p] is at right place

        p = partition(start, end, array)
        # if iterations == True:
            # print("Pivot: ", arr[p])
            # print("Current array: ", arr)

        # Sort elements before partition and after partition
        quickSort(start, p - 1, array)
        quickSort(p + 1, end, array)


# Code for getting top 5
def topFive(arr):
    n = len(arr)
    # sorting the arrau without printing the list at each pass
    quickSort(0, len(arr)-1, arr)
    print("Top Five Percentages are: ")
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
print("Hi. This program allows you to sort the list using Quick Sort.")

arr = []
originalArr = list(arr)

while True:
    print("-" * 30)
    print("1. Quick sort\n2. Print top 5\n3. Enter new list\n4. Exit\n")

    choice = input("Enter your choice: ")
    if choice == "1":
        # True is passed as parameter to print the list at each iteration
        quickSort(0, len(arr)-1, arr, True)
        print("You entered: ", originalArr)
        print("Sorted arr: ", arr)
        # Unsorting the list for next function so that it doesn't sort the sorted list again
        arr = list(originalArr)
    elif choice == "2":
        topFive(arr)
    elif choice == "3":
        tempArr = list(
            map(float, input("Enter a list (SPACE SEPARATED): ").split()))
        if checkArr(tempArr):
            arr = list(tempArr)
            originalArr = list(tempArr)
    elif choice == "4":
        print("Thank you")
        break
    else:
        print("Enter a valid choice(1 to 5).")