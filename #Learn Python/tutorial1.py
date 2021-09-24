class Student:
    def __init__(self, name, batch, rollno):
        self.name=name
        self.batch=batch
        self.rollno=rollno
        self.hobbies=[]

    def add_hobbies(self, hobbies):
        self.hobbies.append(hobbies)

    def data(self):
        print(self.name)
        print(self.batch)
        print(self.rollno)
        print(self.hobbies)


a=[]

for i in range(3):
    n=input("name ")
    b=input("batch ")
    r=int(input("roll no "))
    h=input("hobbies ")
    a.append(Student(n, b, r))
    a[i].add_hobbies(h)


# for i in range(3):
    # print(a[i].data())
print(a[0].name)
print(a[0].batch)
print(a[0].rollno)
print(a[0].hobbies)

