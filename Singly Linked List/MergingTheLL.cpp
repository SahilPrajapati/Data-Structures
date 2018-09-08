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

        cout<<endl<<"Enter how many no. u want to insert in the Sorted List "<<Count<<"."<<endl;
        cin>>n;

        cout<<"Now Enter the "<<n<<" elements of the Sorted list."<<endl;
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

//GLOBALLY DECLARED OBJECT FOR MERGED L.L.
LL<int> o3;

template<class T>
Node<T>* Merge(LL<T> o1,LL<T>o2)
{
    Node<T> *ptr1,*ptr2,*ptr3,*head3;

    //TO STORE HEADS OF BOTH LISTS
    ptr1=o1.head;
    ptr2=o2.head;

    //FOR MERGED L.L.
    ptr3=NULL;
    head3=NULL;


    //TO STORE FIRST ELEMENT IN THE MERGED LIST.
    if(ptr1->data<ptr2->data)
    {
      ptr3=o3.createNode(ptr1->data);
      head3=ptr3;
      ptr1=ptr1->next;
    }

    else if(ptr1->data>ptr2->data)
    {
      ptr3=o3.createNode(ptr2->data);
      head3=ptr3;
      ptr2=ptr2->next;
    }

    else
    {
      ptr3=o3.createNode(ptr2->data);
      head3=ptr3;
      ptr2=ptr2->next;
      ptr1=ptr1->next;
    }


    //TO STORE NEXT ELEMENTS.

    while(ptr1!=NULL&&ptr2!=NULL)
    {
    if(ptr1->data<ptr2->data)
    {
      ptr3->next=o3.createNode(ptr1->data);
      ptr1=ptr1->next;
      ptr3=ptr3->next;
    }
    else if(ptr1->data>ptr2->data)
    {
      ptr3->next=o3.createNode(ptr2->data);
      ptr2=ptr2->next;
      ptr3=ptr3->next;
    }
    else
    {
      ptr3->next=o3.createNode(ptr2->data);
      ptr2=ptr2->next;
      ptr3=ptr3->next;
      ptr1=ptr1->next;
    }
    }

            //IF SECOND LIST BECOMES EMPTY.
    if(ptr2==NULL)
    {
     while(ptr1!=NULL)
     {
      ptr3->next=o3.createNode(ptr1->data);
      ptr1=ptr1->next;
      ptr3=ptr3->next;
     }
    }

    //IF FIRST LIST BECOMES EMPTY.
    else if(ptr1==NULL)
    {
        while(ptr2!=NULL)
        {
      ptr3->next=o3.createNode(ptr2->data);
      ptr2=ptr2->next;
      ptr3=ptr3->next;
        }
    }

    //HEAD OF THE MERGED LIST.
    return head3;

}

int main()
{
    //TWO OBJECTS OF TWO LIST.
    LL<int> o1,o2;


    o1.createList();
    o2.createList();

    o3.head=Merge(o1,o2);

    cout<<endl<<"First List is: ";
    o1.forwardTraversal();

    cout<<endl<<"Second List is: ";
    o2.forwardTraversal();

    cout<<endl<<endl<<"After Merging the 2 L.L. : ";
    o3.forwardTraversal();

    cout<<endl<<endl;
}
