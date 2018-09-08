#include<iostream>
using namespace std;

#define SIZE 5

class Circular
{
public:
    int arr[SIZE];
    int f,r;

    void createEmpty()
    {
    f=-1;
    r=-1;
    }

    int isEmpty()
    {
        if(f==-1&&r==-1)
        {

        cout<<"Queue is Empty"<<endl;
        return 1;
        }

        else
        {
        cout<<"Queue is not Empty"<<endl;
        return 0;
        }
    }


    int isFull()
    {
        if(f==(r+1)%SIZE)
        {
        cout<<"Queue is Full"<<endl;
        return 1;
        }

        else
        {
        cout<<"Queue is not Full"<<endl;
        return 0;
        }
    }

    void Insert(int item)
    {
        if(f==-1&&r==-1)
        {
        f=0;
        r=0;
        }

        else
        {
        r=(r+1)%SIZE;
        }
        arr[r]=item;
    }

    int Delete()
    {
    int temp=arr[f];

   //  IF ONE ELEMENT IS PRESENT...
   if(f==r)
   {
       f=-1;
       r=-1;
   }


   else
   {
        f=(f+1)%SIZE;
   }
     return temp;
    }

    int Size()
    {
        if(f==-1&&r==-1)
        {
            return 0;
        }

        else if(r>=f)
        {
            return r-f+1;
        }

        else
        {
        return SIZE-(f-r- 1);
        }
    }
};

int main()
{
    Circular s1;
    s1.createEmpty();

    cout<<"Circular Queue size is 5"<<endl;
    cout<<endl<<"Enter 5 elements to insert"<<endl;

    for(int i=0;i<5;i++)
    {
        int n;
        cin>>n;
        s1.Insert(n);
    }

    s1.isEmpty();
    s1.isFull();

   cout<<endl<<"Deleting Following 3 elements."<<endl;
   for(int i=0;i<3;i++)
   {
    cout<<s1.Delete()<<endl;
   }

   cout<<endl<<"Enter 3 elements again to insert"<<endl;
   for(int i=0;i<3;i++)
   {
   int m;
   cin>>m;
    s1.Insert(m);
   }

    cout<<endl<<"Now the New Queue is"<<endl;
    for(int i=0;i<5;i++)
    {
    cout<<s1.Delete()<<endl;
    }
}
