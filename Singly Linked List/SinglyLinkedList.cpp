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
class LinkedList
{
    public:
    Node<T> *head;

    LinkedList()
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

    Node<T>* backwardTraversal(Node<T>* head)
    {
        //To store the address of first element
        Node<T>* ptr=head;

        if(head==NULL)
        {
            return head;
        }



        else
        {
            backwardTraversal(ptr->next);
            cout<<ptr->data<<"  ";

        }
    }

    int Search(T key)
    {
        int counter=0;
        Node<T>* ptr=head;

        //IF ELEMENT IS ON FIRST POSITION
        if(head->data==key)
        {
            return 1;
        }

        while(ptr!=NULL)
        {
            if(ptr->data!=key)
            {
            counter++;
            ptr=ptr->next;
            }

            else if(ptr->data==key)
            {
                return counter+1;
            }

        }
    //    return 0;

        return counter;
    }

    int countNodes()
    {
        Node<T>* ptr=head;
        int Count=0;

        while(ptr!=NULL)
        {
            Count++;
            ptr=ptr->next;
        }

        return Count;
    }

    void InsertAtBeginning()
    {
        T key;

        cout<<endl<<"Enter element to insert at beginning."<<endl;
        cin>>key;

        //CREATING NEW NODE OF DATA KEY.
        Node<T>* newnode=createNode(key);


         if(head==NULL)
         {
             //BECOMES THE FIRST NODE.
            head=newnode;
         }

         else
         {
             //connecting the node.
             newnode->next=head;
             head=newnode;
         }

         cout<<"Element is inserted at beginning."<<endl;
    }

    void InsertingInBetween()
    {
        T key;
        T pData;
        Node<T> *ptr,*newnode;
        ptr=head;


        cout<<endl<<"Enter Element to be inserted."<<endl;
        cin>>key;
        newnode=createNode(key);

        int ch;

        cout<<endl<<"Enter the reference element"<<endl;
        cin>>pData;

        cout<<endl<<"Enter 1 to insert element before reference element \n and 2 for after."<<endl;
        cin>>ch;


        //element before reference element
        if(ch==1)
        {
            while(ptr!=NULL&&ptr->next->data!=pData)
            {
                ptr=ptr->next;
            }

        newnode->next=ptr->next;

            ptr->next=newnode;

        }

        //element after reference element
        else if(ch==2)
        {
         while(ptr!=NULL&&ptr->data!=pData)
         {
             ptr=ptr->next;
         }

         if(ptr==NULL)
         {
          cout<<"Reference Element not found..."<<endl;
          return;
         }

        newnode->next=ptr->next;
          ptr->next=newnode;
        }

        cout<<endl<<"Inserted..."<<endl;

    }

    void InsertingAtLast()
    {
        Node<T>* ptr,*newnode;
        ptr=head;
        T key;

        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        cout<<endl<<"Enter element to be inserted."<<endl;
        cin>>key;

        newnode=createNode(key);

        ptr->next=newnode;

        cout<<endl<<endl<<"Element inserted at last..."<<endl;
    }


    void  DeleteAtBeginning()
    {
        Node<T>* ptr;

        if(head==NULL)
        {
        cout<<"L.L. is empty."<<endl;
        }

        else
        {
        ptr=head->next;
        head->next=NULL;
        delete head;
        head=ptr;
        }

        cout<<endl<<endl<<"Deleted Element from the beginning..."<<endl;
    }

    void DeleteInBetween()
    {

        T key;
        T pData;
        Node<T> *ptr,*temp,*temp1;
        ptr=head;

        int ch;

        cout<<endl<<"Enter the reference element"<<endl;
        cin>>pData;

        cout<<endl<<"Enter:-\n1) To delete element before reference element."<<endl;
        cout<<"2) To delete element after reference element."<<endl;
        cout<<"3) To delete reference element."<<endl;
        cin>>ch;

        if(ch==3)
        {
            while(ptr!=NULL&&ptr->next->data!=pData)
            {
                ptr=ptr->next;
            }

            temp=ptr->next;
            ptr->next=ptr->next->next;

            delete temp;

        }

        else if(ch==1)
        {
         while(ptr!=NULL&&ptr->next->next->data!=pData)
            {
                ptr=ptr->next;
            }

            temp=ptr->next;
            ptr->next=ptr->next->next;

            delete temp;
        }

        else if(ch==2)
        {
            while(ptr!=NULL&&ptr->data!=pData)
            {
                ptr=ptr->next;
            }

            temp=ptr->next;

            ptr->next=temp->next;
            delete temp;
        }

        cout<<endl<<"Deleted..."<<endl;

    }

    void DeleteAtLast()
    {
        Node<T> *ptr,*temp;
        ptr=head;
        while(ptr->next!=NULL)
        {
                temp=ptr;
                ptr=ptr->next;
        }
        temp->next=NULL;
        delete ptr;

        cout<<endl<<endl<<"Deleted Element from the last..."<<endl;
    }

    void Reverse()
    {

        //USING THREE POINTERS APPROACH...

        /*Node<T> *prev,*curr,*after ;

        prev=NULL;
        curr=head;
        after=head->next;

        curr->next=NULL;

        while(after!=NULL)
        {
            prev=curr;
            curr=after;
            after=after->next;

             curr->next=prev;
        }

        head=curr;

        cout<<endl<<endl<<"L.L. is reversed..."<<endl;*/



        //USING TWO POINTERS APPROACH...

        Node<T> *prev,*after ;

        prev=NULL;
        after=head->next;

        head->next=NULL;

        while(after!=NULL)
        {
            prev=head;
            head=after;
            after=after->next;

            head->next=prev;
        }
          cout<<endl<<endl<<"L.L. is reversed..."<<endl;

    }

    int ReverseByRecursion(Node<T> *ptr)
    {
        if(ptr==NULL)
            return 0;

        if(ptr->next==NULL)
        {
            head=ptr;
            return 0;
        }

        ReverseByRecursion(ptr->next);

        ptr->next->next=ptr;
        ptr->next=NULL;

    }

};

int main()
{
    LinkedList<int>o1;

    o1.createList();

    int n;
    char choice;

    do
    {
    cout<<endl<<endl<<"<------MENU------>"<<endl;
    cout<<"1) For Traversal."<<endl;
    cout<<"2) For Search an Element."<<endl;
    cout<<"3) For Size."<<endl;
    cout<<"4) For Insert."<<endl;
    cout<<"5) To delete."<<endl;
    cout<<"6) To Reverse."<<endl;
    cin>>n;

    //Traversal
    if(n==1)
    {
        cout<<endl<<"Elements through Forward Traversal are: ";
        o1.forwardTraversal();

        cout<<endl<<"Elements through backward Traversal are: ";
        o1.backwardTraversal(o1.head);
    }


    //SEARCH
    else if(n==2)
    {
        int Find;
        cout<<endl<<"Enter Element to be search"<<endl;
        cin>>Find;

       int f=o1.Search(Find);

       if(f==0)
       {
           cout<<endl<<"Element is not present in the list.";
       }
       else
        cout<<endl<<"Element is found at position: "<<f;
    }

    //SIZE
    else if(n==3)
    {
        int s=o1.countNodes();
        cout<<endl<<"Size of the L.L. is: "<<s<<endl;
    }


    //INSERT
    else if(n==4)
    {
        int c;
        cout<<"Enter where u want to insert an element "<<endl;
        cout<<"1. In the Beginning "<<endl;
        cout<<"2. In the Middle "<<endl;
        cout<<"3. In the Last "<<endl;
        cin>>c;

        //Beginning
        if(c==1)
           o1.InsertAtBeginning();

        //Middle
        else if(c==2)
            o1.InsertingInBetween();

        //End
        else if(c==3)
            o1.InsertingAtLast();

        else
            cout<<"Wrong choice"<<endl;

    }

    //DELETE
    else if(n==5)
    {
        int c;
        cout<<endl<<"Enter where u want to delete an element "<<endl;
        cout<<"1. From the Beginning "<<endl;
        cout<<"2. From the Middle "<<endl;
        cout<<"3. From the Last "<<endl;
        cin>>c;

        //Beginning
        if(c==1)
           o1.DeleteAtBeginning();

        //Middle
        else if(c==2)
            o1.DeleteInBetween();

        //End
       else if(c==3)
            o1.DeleteAtLast();

        else
            cout<<"Wrong choice"<<endl;
    }


    //REVERSE
    else if(n==6)
    {
        o1.ReverseByRecursion(o1.head);
    }

    else
        cout<<endl<<"Wrong Input..."<<endl;

    cout<<endl<<endl<<"Continue(Y/N)..."<<endl;
    cin>>choice;

    }while(choice=='y'||choice=='Y');

}
