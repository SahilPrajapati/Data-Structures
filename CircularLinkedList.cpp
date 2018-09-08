#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;
};


class CCL
{
public:

    Node* last;

    CCL()
    {
        last=NULL;
    }

    //CREATINNG NEW NODE.
    Node* createNode(int key)
    {
        Node* temp=new Node;
        temp->data=key;
        temp->next=NULL;

        //RETURNING THE ADDRESS OF THE NEW NODE.
        return temp;

    }

    void createList()
    {
        char ch;
        int key;
        Node* newnode;
        Node* ptr;

        do
        {
            cout<<endl<<"Enter key value for new node"<<endl;
            cin>>key;

            newnode=createNode(key);


            //When inserting the first element
            if(last==NULL)
            {
                //last will point to the first node
                last=newnode;

                ptr=last;
            }

            else
            {
                last->next=newnode;
                last=newnode;
            }

            cout<<endl<<"Want to continue (Y/N) : "<<endl;
            cin>>ch;
        }while(ch=='y'||ch=='Y');

        //connecting last node to the first.
        last->next=ptr;

        cout<<endl<<endl<<"Elements in the Circular L.L. are  :"<<endl;
        forwardTraversal();
    }


    void forwardTraversal()
    {
        Node* ptr=last;
        if(last==NULL)
            cout<<endl<<"The list is Empty."<<endl;

        ptr=ptr->next;

        while(ptr!=last)
        {
            cout<<ptr->data<<"  ";
            ptr=ptr->next;
        }

        cout<<ptr->data<<endl;
    }

    int countNodes()
    {
        Node* ptr=last->next;
        int Count=1;

        while(ptr!=last)
        {
            Count++;
            ptr=ptr->next;
        }

        return Count;
    }

    void InsertAtBeginning()
    {
        int key;
        Node* head=last->next;
        cout<<endl<<"Enter element to insert at beginning."<<endl;
        cin>>key;

        //CREATING NEW NODE OF DATA KEY.
        Node* newnode=createNode(key);


         if(last==NULL)
         {
             //BECOMES THE FIRST NODE.
            head=newnode;
         }

         else
         {
             //connecting the node.
             newnode->next=head;
             last->next=newnode;
         }
         cout<<endl<<"Element is inserted at beginning."<<endl;
         cout<<endl<<"List is: ";
         forwardTraversal();
    }


    void InsertingInBetween()
    {
        int key;
        int pData;
        Node *ptr,*temp,*newnode;
        ptr=last->next;


        cout<<endl<<"Enter Element to be inserted."<<endl;
        cin>>key;
        newnode=createNode(key);

        int ch;

        cout<<endl<<"Enter the reference element"<<endl;
        cin>>pData;

        cout<<endl<<"Enter 1 to insert element before reference element \n and 2 for after."<<endl;
        cin>>ch;

        if(ch==1)
        {
            while(ptr!=last&&ptr->data!=pData)
            {
                temp=ptr;
                ptr=ptr->next;
            }

            temp->next=newnode;

            newnode->next=ptr;

        }

        else if(ch==2)
        {
         while(ptr!=last&&ptr->data!=pData)
         {
             ptr=ptr->next;
         }
         newnode->next=ptr->next;
          ptr->next=newnode;
        }

        cout<<endl<<"Inserted..."<<endl;
        cout<<endl<<"List is: ";
         forwardTraversal();
    }

    void InsertingAtLast()
    {
        Node* head,*newnode;
        head=last->next;

        int key;
        cout<<endl<<"Enter element to be inserted."<<endl;
        cin>>key;

        newnode=createNode(key);

        last->next=newnode;
        last=newnode;
        last->next=head;

        cout<<endl<<endl<<"Element inserted at last..."<<endl;
        cout<<endl<<"List is: ";
         forwardTraversal();
    }

     void  DeleteAtBeginning()
    {
        Node* head=last->next;

        if(last==NULL)
        {
        cout<<"L.L. is empty."<<endl;
        }

        else
        {
        head=head->next;
        delete last->next;

        last->next=head;
        }

        cout<<endl<<endl<<"Deleted Element from the beginning..."<<endl;
        cout<<endl<<"List is: ";
         forwardTraversal();
    }


     void DeleteInBetween()
    {

        int key;
        int pData;
        Node *ptr,*temp,*temp1;
        ptr=last->next;

        int ch;

        cout<<endl<<"Enter the reference element"<<endl;
        cin>>pData;

        cout<<endl<<"Enter:-\n1) To delete element before reference element."<<endl;
        cout<<"2) To delete element after reference element."<<endl;
        cout<<"3) To delete reference element."<<endl;
        cin>>ch;

        if(ch==3)
        {
            while(ptr!=last&&ptr->data!=pData)
            {

                temp=ptr;
                ptr=ptr->next;
            }

            temp->next=ptr->next;
            delete ptr;

        }

        else if(ch==1)
        {
         while(ptr!=last&&ptr->data!=pData)
            {
                temp1=temp;
                temp=ptr;
                ptr=ptr->next;
            }

            temp1->next=ptr;
            delete temp;
        }

        else if(ch==2)
        {
            while(ptr!=last&&ptr->data!=pData)
            {
                ptr=ptr->next;
            }

            temp=ptr->next;

            ptr->next=temp->next;
            delete temp;
        }

        cout<<endl<<"Deleted..."<<endl;
        cout<<endl<<"List is: ";
         forwardTraversal();
    }


     void DeleteAtLast()
    {
        Node *ptr;
        ptr=last;
        while(ptr->next!=last)
        {
                ptr=ptr->next;
        }

        ptr->next=last->next;

        delete last;

        last=ptr;

        cout<<endl<<endl<<"Deleted Element from the last..."<<endl;
        cout<<endl<<"List is: ";
         forwardTraversal();
    }

    void Reverse()
    {
        Node* ptr=last->next;

        Node* prev=NULL;
        Node* curr=ptr;
        Node* after=ptr->next;

        curr->next=last;

        while(after!=ptr)
        {
            prev=curr;
            curr=after;
            after=after->next;

            curr->next=prev;
        }
        last=after;
    }

};

int main()
{
    CCL o1;

    o1.createList();

    int n;
    char choice;

    do
    {
    cout<<endl<<endl<<"<------MENU------>"<<endl;
    cout<<"1) For Delete."<<endl;
    cout<<"2) For Insert."<<endl;
    cout<<"3) For Size."<<endl;
    cout<<"4) Reverse."<<endl;
    cin>>n;

    //SIZE
    if(n==3)
    {
        int s=o1.countNodes();
        cout<<endl<<"Size of the L.L. is: "<<s<<endl;
    }


    //INSERT
    else if(n==2)
    {
        int c;
        cout<<endl<<"Enter where u want to insert an element "<<endl;
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
    else if(n==1)
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

    else if (n==4)
    {
        o1.Reverse();
        o1.forwardTraversal();
    }



    else
        cout<<endl<<"Wrong Input..."<<endl;

    cout<<endl<<endl<<"Continue(Y/N)..."<<endl;
    cin>>choice;

    }while(choice=='y'||choice=='Y');

}
