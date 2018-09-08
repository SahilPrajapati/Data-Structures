#include<iostream>
#include <stdlib.h>
using namespace std;

#define SIZE 30

template<class T>

class Queue
{
public:
    T arr[SIZE];
     int top;

void createEmpty()
    {
    top=-1;
    }

    void push(T item)
    {
    top++;
    arr[top]=item;
    }

    int pop()
    {
    return arr[top--];
    }

    int isEmpty()
    {
    if(top==-1)
    {
    return 1;
    }

    else
    {
    return 0;
    }
    }
};

Queue<int>s1,s2;

void Insert(int item)
{
    s1.push(item);
}

int Delete()
{
    if(s2.isEmpty()==1)
    {
        if(s1.isEmpty()==1)
        {
            cout<<"The Queue is Empty"<<endl;
            return NULL;
        }

        else
        {
            while(!s1.isEmpty()==1)
            {
            int x=s1.pop();
            s2.push(x);
            }
        }
     }

   return s2.pop();
}

int main()
{
    s1.createEmpty();
    s2.createEmpty();
    char ch;

    do
    {
    cout<<endl<<endl<<"<-----MENU------>"<<endl;
    cout<<endl<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    int n;
    cin>>n;

    if(n==1)
    {
    int m;
    cout<<"Enter Element to Insert"<<endl;
    cin>>m;
    Insert(m);
    }

    if(n==2)
    {
    cout<<"Deleted Element: "<<Delete()<<endl;
    }

    cout<<"Continue?(y/n)"<<endl;
    cin>>ch;
    }while(ch=='y'||ch=='Y');
}
