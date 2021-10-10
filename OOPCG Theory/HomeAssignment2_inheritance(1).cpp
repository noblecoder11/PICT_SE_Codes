#include <iostream>
using namespace std;
// Single level inheritance 
class mathematics
{
 int a, b;
public:
 void accept(int x, int y)
 {
 a = x;
 b = y;
 }
 int getdata1()
 {
 return a;
 }
 int getdata2()
 {
 return b;
 }
};
class addition : public mathematics
{
public:
 void add()
 {
 cout << "Addition of two numbers is " << getdata1() + getdata2() << endl;
 }
};

//multilevel inheritance
class A{
int a;
public:
void accept1(int x){
 a=x;
}
void display(){
 cout<<"a = "<<a<<endl;
}
};
class B:public A{
 int b;
 public:
 void accept2(int y){
 b=y;
 }
 void display2(){
 cout<<"b = "<<b<<endl;
}
};
class C:public B{
int c;
public:
 void accept3(int z){
 c=z;
 }
 void display3(){
 cout<<"c = "<<c<<endl;
}
};
//hierarchical inheritance
class person{
 string name;
 int age;
 public:
 void setData(string n,int a){
 name=n;
 age=a;
 }
 string name_ret(){
 return name;
 }
 int age_ret(){
 return age;
 }
};
class student:public person{
 int marks;
 public:
 void setmarks(int m){
 marks=m;
 }
 int getmarks(){
 return marks;
 }
 void getdata_stud(){
 cout<<"The person named "<<name_ret()<<"and having age "<<age_ret()<<"has scored "<<marks<<endl;
 }
};
class employee:public person{
 int salary;
 public:
 void setsalary(int s){
 salary=s;
 }
 int getsalary(){
 return salary;
 }
 void getdata_empl(){
 cout<<"The person named "<<name_ret()<<"and having age "<<age_ret()<<"has a salary of "<<salary<<endl;
 }
};
//multiple inheriance
class general_info{
 string name,address;
 int age;
 public:
 void accept1(string n,string add,int a){
 name=n;
 address=add;
 age=a;
 }
 void display1(){
 cout<<"name: "<<name<<endl;
 cout<<"address: "<<address<<endl;
 cout<<"age: "<<age<<endl;
 }
};
class academic_info{
 int marks;
 char grade;
 public:
 void accept2(int m,char g){
 marks=m;
 grade=g;
 }
 void display2(){
 cout<<"marks: "<<marks<<endl;
 cout<<"grades: "<<grade<<endl;
 }
};
class employee_info:public general_info,public academic_info{
 string empid;
 int salary;
 public:
 void accept3(string e,int s){
 empid=e;
 salary=s;
 }
 void display3(){
 cout<<"Employee id is "<<empid<<endl;
 cout<<"salary: "<<salary<<endl;
 }
};
int main(){
 C obj;
 obj.accept1(1);
 obj.display();
 obj.accept2(2);
 obj.display2();
 obj.accept3(3);
 obj.display3();
 student s1;
 s1.setData("BJHX",19);
 s1.setmarks(96);
 s1.getdata_stud();
 employee e1;
 e1.setData("SUSHAl",37);
 e1.setsalary(45000);
 e1.getdata_empl();
 
 addition a;
 a.accept(48,84);
 a.add();
 employee_info emp;
 emp.accept1("ABC","Maharashtra",19);
 emp.display1();
 emp.accept2(96,'A');
 emp.display2();
 emp.accept3("KLJDFSKFDS3234",96000);
 emp.display3();
 return 0;
}