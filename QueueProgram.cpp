#include<iostream>
using namespace std;

#define MAX 30

class Queue
{
    public:
    int element[MAX];
    // FRONT AND REAR
    int f,r;

    void create_empty_queue()
    {
        f=r=-1;
    }

    int isFull()
    {
        //FULL CONDITION
        if(f==0&&r==MAX-1)
        {
            return 1;
        }
        else
            return 0;
    }

    int isEmpty()
    {
        //EMPTY CONDITION
        if(f==-1&&r==-1)
        {
            return 1;
        }
        else
            return 0;
    }

    void Insert(int item)
    {
        //IF EMPTY
        if(f==-1&&r==-1)
        {
            f=r=0;
        }

        //IF SOME PLACES ARE LEFT IN STARTING
        else if(f!=0&&r==MAX-1)
        {
            //FOR SHIFTING ELEMENT TO THE START
            for(int i=f;i<=r;i++)
            {
               element[i-f]=element[i];
            }
            //REAR IN INSERTING POSTION
            r=r-f+1;

            f=0;
        }

        //NORMAL,PARTIALLY FULL
        else
        {
            r++;
        }

        //INSERTING ELEMENT
        element[r]=item;
    }


    int Delete()
    {
        int temp=element[f];
        //IF ONE ELEMENT IS PRESENT
        if(f==r)
        {
            f=r=-1;
        }

        f++;

        return temp;
    }

    int Size()
    {
        return r-f+1;
    }
};


int main()
{
    Queue q;

    q.create_empty_queue();

    int n;
    char ch;

    do
    {
    cout<<"<------- MENU------->"<<endl;

    cout<<endl<<"1.Check Empty"<<endl;
    cout<<"1. Check Empty"<<endl;
    cout<<"2. Check Full"<<endl;
    cout<<"3. Insert"<<endl;
    cout<<"4. Delete"<<endl;
    cout<<"5. Check Size"<<endl;

    cin>>n;

    if(n==1)
    {
        if(q.isEmpty()==1)
        {
            cout<<"Yes,The queue is empty."<<endl;
        }
        else
            cout<<"No,not empty"<<endl;
    }

   else if(n==2)
    {
        if(q.isFull()==1)
        {
            cout<<"Yes,The queue is Full."<<endl;
        }
        else
            cout<<"No,not Full"<<endl;
    }

    else if(n==3)
    {
        int a;
        cout<<"Enter element to insert."<<endl;
        cin>>a;

        q.Insert(a);
    }

    else if(n==4)
    {
        int b=q.Delete();
        cout<<"Deleted Element :"<<b<<endl;
    }

    else if(n==5)
    {
        cout<<"Your Queue Size is: "<<q.Size()<<endl;
    }

    else
    {
        cout<<"Wrong Choice"<<endl;
    }


    cout<<endl<<"Do you Want to Continue(y/n)."<<endl;
    cin>>ch;
    cout<<endl<<endl;
    }while(ch=='y'||ch=='Y');
}
