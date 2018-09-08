#include<iostream>
using namespace std;


int Count=1;
class Term
{
    public:
    int coef;
    int exp;
    Term* next;
};

class Polynomial
{
    public:

    Term *head;

    Polynomial()
    {
        head=NULL;
    }

    Term* createTerm(int c,int e)
    {
        Term* temp=new Term;
        temp->coef=c;
        temp->exp=e;
        temp->next=NULL;

        //RETURNING THE ADDRESS OF THE NEW Term.
        return temp;

    }

    void createPoly()
    {
        cout<<endl<<endl<<"         For Polynomial :  "<<Count<<endl;
        Count++;
        char ch;
        int c,e;
        Term* newterm;
        Term* ptr;

        do
        {
            cout<<endl<<"Enter coefficient for new term."<<endl;
            cin>>c;

            cout<<endl<<"Enter exponent for that new term."<<endl;
            cin>>e;

            newterm=createTerm(c,e);


            //When inserting the first element
            if(head==NULL)
            {
                //head will point to the first node
                head=newterm;

                //temporary pointer ptr will also point to the first element so that we can put next element
                ptr=head;
            }

            else
            {
                ptr->next=newterm;
                ptr=newterm;
            }

            cout<<endl<<"Want to continue (Y/N) : "<<endl;
            cin>>ch;
        }while(ch=='y'||ch=='Y');
    }

    void forwardTraversal()
    {
        Term* ptr=head;
        if(head==NULL)
            cout<<endl<<"The list is Empty."<<endl;


        while(ptr!=NULL)
        {
            cout<<"coef : "<<ptr->coef<<"    exp: "<<ptr->exp<<endl;
            ptr=ptr->next;
        }
    }
};

 Polynomial p1,p2,p3;

 Term* Add()
 {

   //TO STORE HEADS OF BOTH LISTS
    Term* ptr1=p1.head;
    Term* ptr2=p2.head;
    Term* head3,*ptr3;

    //FOR MERGED L.L.
    ptr3=NULL;
    head3=NULL;


    //TO STORE FIRST ELEMENT IN THE MERGED LIST.
    if(ptr1->exp>ptr2->exp)
    {
      ptr3=p3.createTerm(ptr1->coef,ptr1->exp);
      head3=ptr3;
      ptr1=ptr1->next;
    }

    else if(ptr1->exp<ptr2->exp)
    {
      ptr3=p3.createTerm(ptr2->coef,ptr2->exp);
      head3=ptr3;
      ptr2=ptr2->next;
    }

    else
    {
     ptr3=p3.createTerm(ptr2->coef+ptr1->coef,ptr2->exp);
      head3=ptr3;
      ptr2=ptr2->next;
      ptr1=ptr1->next;
    }

    //TO STORE NEXT ELEMENTS.

    while(ptr1!=NULL&&ptr2!=NULL)
    {
    if(ptr1->exp>ptr2->exp)
    {
      ptr3->next=p3.createTerm(ptr1->coef,ptr1->exp);
      ptr3=ptr3->next;
      ptr1=ptr1->next;
    }
    else if(ptr1->exp<ptr2->exp)
    {
      ptr3->next=p3.createTerm(ptr2->coef,ptr2->exp);
      ptr3=ptr3->next;
      ptr2=ptr2->next;
    }

    else
    {
     ptr3->next=p3.createTerm(ptr2->coef+ptr1->coef,ptr2->exp);
      ptr3=ptr3->next;
      ptr2=ptr2->next;
      ptr1=ptr1->next;
    }


    }


    //IF SECOND LIST BECOMES EMPTY.
    if(ptr2==NULL)
    {
     while(ptr1!=NULL)
     {
      ptr3->next=p3.createTerm(ptr1->coef,ptr1->exp);
      ptr3=ptr3->next;
      ptr1=ptr1->next;
     }
    }

    //IF FIRST LIST BECOMES EMPTY.
    else if(ptr1==NULL)
    {
        while(ptr2!=NULL)
        {
       ptr3->next=p3.createTerm(ptr2->coef,ptr2->exp);
      ptr3=ptr3->next;
      ptr2=ptr2->next;
        }
    }

    //HEAD OF THE MERGED LIST.
    return head3;

 }

int main()
{

    p1.createPoly();
    p2.createPoly();

        cout<<endl<<endl<<"Terms in the First Polynomial are  :"<<endl;
        p1.forwardTraversal();

        cout<<endl<<endl<<"Terms in the Second Polynomial are  :"<<endl;
        p2.forwardTraversal();

    p3.head=Add();

    cout<<endl<<endl<<"After adding the two polynomial : "<<endl;
    p3.forwardTraversal();
}
