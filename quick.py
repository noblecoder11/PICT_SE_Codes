def partition(start, end, arr, currArr):
	pivot = arr[end]
	pivotIndex = start
	for i in range(start, end):
		if arr[i] <= pivot:
			arr[pivotIndex], arr[i] = arr[i], arr[pivotIndex]
			pivotIndex += 1
	arr[pivotIndex], arr[end] = arr[end], arr[pivotIndex]
	if currArr == True:
		print(f"Pivot: {pivot}, List: {list(arr)}")
	return pivotIndex

def quickSort(start, end, arr, currArr):
	if start < end:
		p = partition(start, end, arr, currArr)
		quickSort(start, p-1, arr, currArr)
		quickSort(p+1, end, arr, currArr)

def topFive(arr):
	n = len(arr)
	quickSort(0, len(arr)-1, arr, False)
	for i in range(1, 6):
		print(arr[n-i])

def isValid(arr):
	if len(arr) < 5:
		print("Enter more than 5 elements")
		return False
	for i in arr:
		if i < 0 and i > 100:
			print("All elements should be in range 0 to 100")
			return False
	return True

# Main Menu
arr = []
originalArr = list(arr)

while True:
	print("\n---------- Main Menu ----------")
	print("\n1. New List\n2. Quick Sort\n3. Top Five\n4. Exit\n")
	choice = input("Enter your choice: ")
	if choice == "1":
		tempArr = list(map(float, input("Enter list: ").split()))
		if isValid(tempArr):
			arr = list(tempArr)
			originalArr = list(tempArr)
	elif choice == "2":
		quickSort(0, len(arr)-1, arr, True)
		print("You entered: ", originalArr)
		print("Sorted: ", arr)

		arr = list(originalArr)
	elif choice == "3":
		topFive(arr)
	elif choice == "4":
		print("Thank You")
		break
	else:
		print("Enter a valid choice.")	