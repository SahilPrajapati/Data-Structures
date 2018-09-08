#include<iostream>
using namespace std;

int Count=1;

template<class T>

class Node
{
public:
    T data;
    Node<T> *next;
};


template<class T>


class LL
{
public:
    Node<T> *head;

    LL()
    {
        head=NULL;
    }

    Node<T>* createNode(T key)
    {
        Node<T>* temp=new Node<T>;
        temp->data=key;
        temp->next=NULL;

        return temp;
    }

    void createList()
    {
        int n;
        Node<T>* newnode,*ptr;

        cout<<endl<<"Enter how many no. u want to insert in the list "<<Count<<"."<<endl;
        cin>>n;

        cout<<"Now Enter the "<<n<<" elements of the list."<<endl;
        for(int i=0;i<n;i++)
        {
            T key;

            cin>>key;

            newnode=createNode(key);

            if(head==NULL)
            {
                head=newnode;
                ptr=head;
            }

            else
            {
                ptr->next=newnode;
                ptr=newnode;
            }
        }

        cout<<endl<<"Elements are inserted in the list "<<Count<<"."<<endl;
        Count++;
    }

    void forwardTraversal()
    {
        Node<T>* ptr=head;
        if(head==NULL)
            cout<<endl<<"The list is Empty."<<endl;


        while(ptr!=NULL)
        {
            cout<<ptr->data<<"  ";
            ptr=ptr->next;
        }
    }
};

void Concate(LL<int> o1,LL<int> o2)
{
    Node<int> *ptr=o1.head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    ptr->next=o2.head;
}

int main()
{
    LL<int> o1,o2;
    char ch;

    o1.createList();
    o2.createList();

    Concate(o1,o2);

    cout<<endl<<"Given 2 L.L. have been concatenated."<<endl;
    cout<<endl<<"Press y to show the list"<<endl;
    cin>>ch;

    if(ch=='y'||ch=='Y')
    {
        cout<<endl<<"Now the list become : "<<endl;
        o1.forwardTraversal();
    }
}
