#FUNCTIONS
def intersec(l1, l2):
    inter_li=[item for item in l1 if item in l2]
    return inter_li

def union(l1, l2):
    union_li=l1+l2
    for i in l1:
        if i in l2:
            union_li.remove(i)
    return union_li

def diff(l1, l2):
    diff_li=[item for item in l1 if item not in l2]
    return diff_li

    
#INPUT
c=int(input("Enter the number of students who play Cricket: "))
clist=[]
for i in range(c):
    temp=input("Enter name of Student: ")
    if temp not in clist:
        clist.append(temp)
    
b=int(input("Enter the number of students who play Badminton: "))
blist=[]
for i in range(b):
    temp=input("Enter name of Student: ")
    if temp not in blist:
        blist.append(temp)

f=int(input("Enter the number of students who play Football: "))
flist=[]
for i in range(f):
    temp=input("Enter name of Student: ")
    if temp not in flist:
        flist.append(temp)

#PRINTING GROUPS
print()
print("Cricket group:", clist)
print("Badminton group:", blist)
print("Football group:", flist)
    
#CALCULATING LISTS
a1=intersec(clist, blist)
a2=diff(union(blist, clist),intersec(blist, clist)) 
a3=diff(flist, union(clist, blist))
a4=diff(union(clist, flist), blist)

# UNDERSTANDING (PRINT ALL)
print()
print("This is for analyzing output: ")
print("1. Students playing cricket and badminton: ",set(a1))
print("2. Student playing cricket or badminton but not both: ", set(a2))
print("3. Students playing neither cricket nor badminton: ", set(a3))
print("4. Students playing cricket and football but not badminton: ", set(a4))
print()

# MAIN MENU
print("MAIN MENU")
print("1. Students playing cricket and badminton")
print("2. Student playing cricket or badminton but not both")
print("3. Number of students playing neither cricket nor badminton")
print("4. Number of students  playing cricket and football but not badminton")
print()

#PRINTING
while input("Do you want to continue(y/n): ")=='y':
    #CHOICE
    choice= int(input("Enter choice: "))
    if 1<=choice<=4 :
        if choice==1:
            print("Students playing cricket and badminton: ",set(a1))
        elif choice==2:
            print("Student playing cricket or badminton but not both: ", set(a2))
        elif choice==3:
            print("Number of students playing neither cricket nor badminton: ", len(a3))
            # print(set(a3))
        else:
            print("Number of students playing cricket and football but not badminton: ", len(a4))
            # print(set(a4))

    else:
        print("Enter a valid choice")
        print()
        continue

    #BLANK LINE
    print()

print("THANK YOU!")