#include<iostream>
using namespace std;

template<class T>

//CLASS CREATING NODE.
class Node
{
    public:
    T data;
    Node<T>* next;
    Node<T>* prev;
};


template<class T>

class DLL
{
public:

    Node<T>* head;
    Node<T>* tail;

    DLL()
    {
        head=NULL;
        tail=NULL;
    }

    Node<T>* createNode(T key)
    {
        Node<T>* temp=new Node<T>;

        temp->data=key;
        temp->next=NULL;
        temp->prev=NULL;

        return temp;
    }

    void createList()
    {
        T key;
        char ch;

        Node<T>* newnode;

        do
        {
            cout<<endl<<"Enter the key value for new node."<<endl;
            cin>>key;

            newnode=createNode(key);

            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }

            else
            {
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }

            cout<<endl<<"Continue(Y/N) : ";
            cin>>ch;
        }while(ch=='y'||ch=='Y');

       cout<<endl<<endl<<"Elements in the D.L.L. are  :"<<endl;

       cout<<endl<<"Forward Traversal : ";
       forwardTraversal();

        cout<<endl<<"Backward Traversal : ";
       backwardTraversal();
        cout<<endl;
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

    void backwardTraversal()
    {
        Node<T>* ptr=tail;

        if(tail==NULL)
            cout<<endl<<"The list is Empty."<<endl;


        while(ptr!=NULL)
        {
            cout<<ptr->data<<"  ";
            ptr=ptr->prev;
        }
    }

    void Insert()
    {
        Node<T>* newnode;

        int n;
        cout<<endl<<"Enter the element to insert"<<endl;
        cin>>n;

        int ch;

        cout<<endl<<"Enter Where u want to insert the element : "<<endl;
        cout<<endl<<"1. In Beginning."<<endl;
        cout<<endl<<"2. In last."<<endl;
        cout<<endl<<"3. In Middle"<<endl;
        cin>>ch;

        switch(ch)
        {
            //INSERT AT BEGINNING.
        case 1:
            newnode=createNode(n);
            newnode->next=head;
            head->prev=newnode;

            head=newnode;
            break;



            //INSERT AT LAST
        case 2:
            newnode=createNode(n);

            tail->next=newnode;
            newnode->prev=tail;

            tail=newnode;
            break;

            //INSERT IN BETWEEN
        case 3:

            int p,c;
            cout<<endl<<"Enter Reference Element : ";
            cin>>p;

            cout<<endl<<endl<<"To insert \n 1. Before Ref. Element \n 2. After Ref. Element. "<<endl;
            cin>>c;

            newnode=createNode(n);

            Node<T>* ptr=head;

            while(ptr->data!=p)
            {
                ptr=ptr->next;
            }

            switch(c)
            {
                // Before Reference Element.
            case 1:

                newnode->next=ptr;
                newnode->prev=ptr->prev;
                ptr->prev->next=newnode;
                ptr->prev=newnode;
                break;

                //After REFERENCE ELEMENT.
            case 2:
                 newnode->next=ptr->next;
                 newnode->prev=ptr;
                 ptr->next=newnode;
                 newnode->next->prev=newnode;
                 break;

            }
            break;
        }
            cout<<endl<<"Element "<<n<<" is inserted..."<<endl;
            cout<<endl<<"List is : ";
            forwardTraversal();
            cout<<endl;
    }



    void Delete()
    {
        int ch;

        cout<<endl<<"Delete the element from : "<<endl;
        cout<<endl<<"1. Beginning."<<endl;
        cout<<endl<<"2. Last."<<endl;
        cout<<endl<<"3. Middle"<<endl;
        cin>>ch;

        Node<T>* ptr;

        switch(ch)
        {
            //DELETING FROM BEGINNING
        case 1:
             ptr=head;
            head=head->next;
            head->prev=NULL;
            delete ptr;

            break;

            //DELETING FROM LAST
        case 2:
            ptr=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete ptr;

            break;


            //DELETE FROM MIDDLE
        case 3:
            int p,c;
            cout<<endl<<"Enter Reference Element : ";
            cin>>p;

            cout<<endl<<"Delete : ";
            cout<<endl<<"1. Before Ref. Element."<<endl;
            cout<<endl<<"2. After Ref. Element."<<endl;
            cout<<endl<<"3. Ref. Element."<<endl;
            cin>>c;

            Node<T>* ptr=head;

            while(ptr->data!=p)
            {
                ptr=ptr->next;
            }

            Node<T>* temp;

            switch(c)
            {
                //Before Ref. Element.
            case 1:

                temp=ptr->prev;
                temp->prev->next=ptr;
                ptr->prev=temp->prev;

                delete temp;
                break;


                //After Ref. Element
            case 2:
                temp=ptr->next;
                ptr->next=temp->next;
                temp->next->prev=ptr;

                delete temp;
                break;


                //Reference Element
            case 3:
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;

                delete ptr;

                break;

            }

            break;

        }

            cout<<endl<<"Element is Deleted..."<<endl;
            cout<<endl<<"List is : ";
            forwardTraversal();
            cout<<endl;
    }
};

int main()
{
    DLL<int> o1;
    char c;


    o1.createList();

   do
  {
    int ch;
    cout<<endl<<"       <------MENU------>"<<endl;
    cout<<endl<<"1. Insert."<<endl;
    cout<<"2. Delete."<<endl;

    cin>>ch;

    switch(ch)
    {
    case 1:
        o1.Insert();
        break;

    case 2:
        o1.Delete();
        break;
    }

  cout<<endl<<endl<<"Continue Again(Y/N) : ";
  cin>>c;
  }while(c=='y'||c=='Y');

}
