class matrix:
    def __init__(self, num_row, num_col):
        self.num_row=num_row
        self.num_col=num_col
        self.a=[]
    
    def input_matrix(self):
        print(f"Enter the matrix of {self.num_row} rows and {self.num_col} numbers in each row.")
        for i in range(self.num_row):
            row=list(map(int, input().split()))
            self.a.append(row)

    def display(self):
        matrix=[]
        for i in range(self.num_row):
            new_row=[]
            for j in range(self.num_col):
                new_row.append(self.a[i][j])
            matrix.append(new_row)
        
        for i in range(len(matrix)):
            print(matrix[i])
        print()
    
    def addition(self, A, B):
        if A.num_row==B.num_row and A.num_col==B.num_col:
            for i in range(self.num_row):
                new_row=[]
                for j in range(self.num_col):
                    new_row.append(A.a[i][j]+B.a[i][j])
                self.a.append(new_row)
            C.display()
        else:
            print("You can't add matrices with different number of rows and columns.")

    def subtraction(self, A, B):
        if A.num_row==B.num_row and A.num_col==B.num_col:
            for i in range(self.num_row):
                new_row=[]
                for j in range(self.num_col):
                    new_row.append(A.a[i][j]-B.a[i][j])
                self.a.append(new_row)
            C.display()
        else:
            print("You can't subtract matrices with different number of rows and columns.")

    def multiplication(self, A, B):
        if A.num_col==B.num_row:
            for i in range(A.num_row):
                new_row=[]
                for j in range(B.num_col):
                    result=0
                    for k in range(B.num_row):
                        result += A.a[i][k] * B.a[k][j] 
                    new_row.append(result)
                self.a.append(new_row)
            self.display()
        else:
            print("You can't multiply these matrices. For multiplication you need number of columns in first matrix equal to number of rows in second matrix.")


    def transpose(self, A):
        for j in range(A.num_row):
            new_row=[]
            for i in range(A.num_col):
                new_row.append(A.a[i][j])
            self.a.append(new_row)
        self.display()


#MAIN FUNCTION
#Main Menu
print("Hello! This program allows you to do your homework for matrices within minutes.\nThis program does:\n1. Addition of two matrices\n2. Subtraction of two matrices0\n3. Multiplication of two matrices \n4. Transpose of matrix A\n5. Transpose of matrix B")

# input first matrix
r1=int(input("Enter number of rows in matrix A: "))
c1=int(input("Enter number of columns in matrix A: "))
A=matrix(r1, c1)
A.input_matrix()

# input second matrix
r2=int(input("Enter number of rows in matrix B: "))
c2=int(input("Enter number of columns in matrix B: "))
B=matrix(r2, c2)
B.input_matrix()

#Print matrices
print("---------------")
print("Matrix A")
A.display()
print("---------------")
print("Matrix B")
B.display()
print("---------------")

while(True):
    ch=int(input("Enter a choice: "))
    if ch==1:
        C=matrix(r1, c1)
        C.addition(A, B)
    elif ch==2:
        C=matrix(r1, c1)
        C.subtraction(A, B)
    elif ch==3:
        print("What do you want?: (AB or BA)")
        choice=input()
        if choice=="AB":
            C=matrix(r1, c2)
            C.multiplication(A, B)
        elif choice=="BA":
            C=matrix(r2, c1)
            C.multiplication(B, A)
        else:
            print("The choice you entered is incorrect. Please enter AB or BA.")
    elif ch==4:
        C=matrix(c1, r1)
        C.transpose(A)
    elif ch==5:
        C=matrix(c2, r2)
        C.transpose(B)
    else:
        print("Enter correct choice. (1 to 5)")
    
    print()
    cont= input("Do you want to continue(y/n): ")
    if cont=='n' or cont=='N':
        print("Thank you for using this program.\n")
        break
    else:
        continue