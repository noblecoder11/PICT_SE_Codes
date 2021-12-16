#include <iostream>
#include <string>
using namespace std;

//create a class for appointment
class appointment
{
    public:
        bool status = true; //sets the status of the appointment whether booked or not
        int start_time,end_time,max_dur,min_dur;
        
        //default constructor
        //we will set the default values for minimum and maximum duration for the appointment as 1
        appointment()
        {
            max_dur = 1;
            min_dur = 1;
        }

        //function to get the details of the appointment
        void get_details()
        {
            bool go = true;
            while(go)
            {
                try
                {
                    cout<<"\nPlease enter start time of the appointment: ";
                    if(cin>>start_time){if(start_time<7 || start_time>19) throw 'a';}       //taking input for start time
                    else{throw 0;}
                    cout<<"Please enter the end time of the appointment: ";
                    if(cin>>end_time){if(end_time<7 || end_time>19) throw 'a';}         //taking input for end time
                    else{throw 1;}
                    cout<<"Please enter the minimum duration of the appointment: ";
                    if(cin>>min_dur){if(min_dur>2) throw 'b';}          //taking input for minimum duration of the appointment
                    else{throw 2;}
                    cout<<"Please enter the maximum duration of the appointment: ";
                    if(cin>>max_dur){if(max_dur>2) throw 'c';}          //taking input for maximum duration of the appointment
                    else{throw 3;}
                    go = false;
                }
                catch(int x)
                {
                    //EH for wrong input of time
                    cin.clear();
                    cout<<"\nPlease enter correct inputs for time!";
                }
                catch(char a)
                {
                    cout<<"\nAppointments only from 9:00 to 19:00 hrs. and each appointment must be less than 2 hrs"<<endl;
                }
            }
            
        }

        //function to display the appointment data
        void display()
        {
            cout<<"Appointment time: From "<<start_time<<":00 to "<<end_time<<":00 hrs."<<endl;
            cout<<"Minimum duration: "<<min_dur<<" hr."<<endl;
            cout<<"Maximum duration: "<<max_dur<<" hr."<<endl;
            cout<<"Appointment status: ";
            if(status){cout<<"Available"<<endl;}
            else {cout<<"Booked"<<endl;}
        }

        //default destructor
        ~appointment()
        {}
};

//initializing nodes for the linked list
struct node
{
    appointment data;
    node *next;
};

//function to print all the nodes
void PrintFwd(node* head)
{
    node* temp = head;
    int count = 1;
    while(temp != NULL)
    {
        cout<<"\nAppointment "<<count<<": "<<endl;
        temp->data.display();
        cout<<endl;
        count++;
        temp = temp->next;
    }
}

void book(node* head, int position)
{
    int count =1;
    node* temp = head;
    while(count!=position)
    {
        temp=temp->next;
        count++;
    }
    temp->data.status=false;
    return;
}

void sortLL(node* head, int count)
{
    node *temp = head;
    node *current = head;
    //bubble sort
    while(current!=NULL)
    {
        temp=current->next;
        while(temp!= NULL)
        {
            if(temp->data.start_time < current->data.start_time)
            {
                //swapping the elements
                appointment buffer = temp->data;
                temp->data = current->data;
                current->data = buffer;
            }
            temp= temp->next;
        }
        current=current->next;
    }   
}

void deletenode(node **head, int position, node **tail)
{   
    // If linked list is empty
    if (*head == NULL)
    {
        cout<<"\nThere are no appointments booked yet!";
        return;
    }
      
    // Store head node
    node* temp = *head;
    // If head needs to be removed
    if (position == 1)
    {

        // Change head
        *head=temp->next;          
        return;
    }
    // Find previous node of the node to be deleted
    for(int i = 1; i < position-1; i++)
    {
        temp = temp->next;
    }

    // node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    node *next1 = temp->next->next;
    temp->next = next1;
    
    // Unlink the node from linked list
    free(temp->next); // Free memory
}

//main part of the program
int main()
{
    int choice = 0;
    int total_nodes = 0;
    bool first_node = true;
    node *head;
    node *tail;
    node *newnode;

    while(choice!=-1)
    {
        try
        {
            cout<<"____________________________\n\nWelcome to the Portal!"<<endl;
            cout<<"\nMENU\n1. Make schedule for appointment.\n2. Book an appointment\n3. Display the free slots\n4. Cancel an appointment.\n5. Sort list based on time.\nEnter -1 to exit from the program."<<endl;
            cout<<"\nPlease enter your choice: ";
            if(cin>>choice){}
            else
            {
                throw 0;
            }    
        }
        catch(int x)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 9;
        }

        switch(choice)
        {
            //CASE TO BOOK AN APPOINTMENT 
            case 1:
            {
                if(first_node)
                {
                    newnode = new node;
                    newnode->data.get_details();
                    head = newnode;
                    tail = newnode;
                    tail->next = NULL;
                    first_node = false;
                    total_nodes++;
                }
                else
                {
                    newnode = new node;
                    newnode->data.get_details();
                    tail->next = newnode;
                    tail = newnode;
                    tail->next = NULL;
                    total_nodes++;
                }
                break;
            }
            
            //to book an appointment
            case 2:
            {
                int position=0;
                cout<<"Appointment slots are:"<<endl;
                PrintFwd(head);
                cout<<"\nEnter the appointment slot you would like to book: ";
                cin>>position;
                book(head,position);
                cout<<"\nAppointment Booked!"<<endl;
                break;
            }
            //CASE TO DISPLAY ALL BOOKED SLOTS 
            case 3:
            {
                cout<<"Appointment slots are:"<<endl;
                PrintFwd(head);
                break;
            }
            
            //CASE TO CANCEL AN APPOINTMENT 
            case 4:
            {
                bool go = true;
                int case1;
                cout<<"Displaying all appointments: "<<endl;
                PrintFwd(head);
                //EH needs to be done here for number of the node that has to be deleted
                while(go)
                {
                    try
                    {
                        //taking input for
                        cout<<"\nWhich appointment would you like to delete? - ";
                        if(cin>>case1)
                        {
                            if(case1<=0 || case1>total_nodes)
                            {
                                throw 0;
                            }
                            go = false;
                        }
                        else
                        {
                            throw 1;
                        }
                    }
                    catch(int x)
                    {
                        cin.clear();
                        cout<<"\nPlease enter a valid node to delete."<<endl;
                    }
                }
                deletenode(&head,case1,&tail);
                total_nodes--;
                cout<<"Appointment cancelled successfully."<<endl;
                break;
            }

            //CASE TO SORT
            case 5:
            {
                cout<<"\nInitiating sort..."<<endl;
                sortLL(head,total_nodes);
                break;
            }

            case -1:
            {
                break;
            }

            //default case for wrong choice from user
            default:
            {
                cout<<"Please enter a valid choice from the MENU!"<<endl;
                break;
            }
        }       
    }
    cout<<"\nTHANK YOU FOR USING OUR PORTAL! ";   
    return 0;
}