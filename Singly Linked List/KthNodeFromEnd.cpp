#include<iostream>
using namespace std;

template<class T>

//CLASS CREATING NODE.
class Node
{
    public:
    T data;
    Node<T>* next;
};


template<class T>

//CLASS CREATING LIST.
class List
{
    public:
    Node<T> *head;

    List()
    {
        //initially head null when linked list is empty
        head=NULL;
    }

    //CREATINNG NEW NODE.
    Node<T>* createNode(T key)
    {
        Node<T>* temp=new Node<T>;
        temp->data=key;
        temp->next=NULL;

        //RETURNING THE ADDRESS OF THE NEW NODE.
        return temp;

    }

    void createList()
    {
        char ch;
        T key;
        Node<T>* newnode;
        Node<T>* ptr;

        do
        {
            cout<<endl<<"Enter key value for new node"<<endl;
            cin>>key;

            newnode=createNode(key);


            //When inserting the first element
            if(head==NULL)
            {
                //head will point to the first node
                head=newnode;

                //temporary pointer ptr will also point to the first element so that we can put next element
                ptr=head;
            }

            else
            {
                ptr->next=newnode;
                ptr=newnode;
            }

            cout<<endl<<"Want to continue (Y/N) : "<<endl;
            cin>>ch;
        }while(ch=='y'||ch=='Y');

        cout<<endl<<endl<<"Elements in the L.L. are  :"<<endl;
        forwardTraversal();
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

    void KfromLast()
    {
        int n;
        cout<<endl<<endl<<"Enter the Kth node to access from last."<<endl;
        cin>>n;

        Node<T>* TT=head;
        Node<T>* R=head;

        for(int i=0;i<n;i++)
        {
            R=R->next;
        }

        while(R!=NULL)
        {
            R=R->next;
            TT=TT->next;
        }

        cout<<endl<<"Kth node from last is having data : "<<TT->data<<endl;

    }
};

int main()
{

    List<int> o1;

    o1.createList();

    o1.KfromLast();
}
