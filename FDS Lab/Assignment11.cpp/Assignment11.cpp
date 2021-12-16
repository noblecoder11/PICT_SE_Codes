/*11.		Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue. 


*/
#include<iostream>
using namespace std;
#define size 10

class Queue
{

	private:
		struct queue
		{
			int que[size];
			int front;
			int rear;
		};
        queue Q;
	public:
		Queue();				//Constructor
		int Qfull();
		int insert(int);
		int Qempty();
		int Delete();
		void display();
};

Queue::Queue()					//Initializing the Job Queue
{
	Q.front=-1;
	Q.rear=-1;
}

int Queue::Qfull()
{

	if(Q.rear>=size-1)
		return 1;
	else
		return 0;
}

int Queue::insert(int item)
{

	if(Q.front==-1)
		Q.front++;
	Q.que[++Q.rear]=item;
		return Q.rear;
}

int Queue::Qempty()
{

	if((Q.front==-1)||(Q.front>Q.rear))
		return 1;
		
	else
		return 0;
}

int Queue::Delete()
{
	int item;
	item=Q.que[Q.front];
	Q.front++;
	
		cout<<"\n The deleted job is:"<<item;
			return Q.front;
}

void Queue::display()
{
	int i;
	for(i=Q.front;i<=Q.rear;i++)
	cout<<" "<<Q.que[i];
}

int main()
{
	int ch,item;
	char ans;
	Queue J;

	do
	{
		cout<<"\nMain Menu:";
		cout<<"\n1.ADD Job\n2.Delete Job\n3.Display Job Queue";
		cout<<"\nEnter your choice:";
		cin>>ch;

		switch(ch)
		{

			case 1:	
				if(J.Qfull())		//Queue Overflow
					cout<<"\nQueue is full. Can not insert the job.";					
				
				else
				{
					cout<<"\nEnter the Job ID: ";
					cin>>item;
					J.insert(item);
				}
				break;
						
			case 2:	
				if(J.Qempty())		//Queue Underflow
					cout<<"\nQueue is empty.";
					
				else 
					J.Delete();
				break;
						
			case 3:	
				if(J.Qempty())
					cout<<"\nJob Queue is Empty";
				else
					J.display();
				break;
					
			default: 
				cout<<"\nWrong Choice";
					break;

		}
        cout<<"\n Do you want to continue?:";
        cin>>ans;
				
	}while(ans=='Y'||ans=='y');
	
	return 0;
}