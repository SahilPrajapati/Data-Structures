#include<iostream>
using namespace std;


class Node
{
public:
    int row;
    int col;
    int value;
    Node* next;
};

class Matrix
{
    public:

    Node* head;

    Matrix()
    {
       head=NULL;
    }

    void createNode(int r,int c, int v)
    {
       Node* temp=new Node;
       temp->row=r;
       temp->col=c;
       temp->value=v;
       temp->next=NULL;

       Node* ptr;


      if(head==NULL)
      {
       head=temp;
       ptr=head;
      }

      else
      {
      ptr->next=temp;
      ptr=temp;
      }
    }

    void Traversal()
    {
    Node *ptr=head->next;

    cout<<endl<<endl<<"Total rows : "<<head->row<<endl;
    cout<<"Total columns : "<<head->col<<endl;
    cout<<"Total Non-Zero Elements : "<<head->value<<endl<<endl<<endl;

    while(ptr!=NULL)
    {
        cout<<endl<<endl<<"Row No. : "<<ptr->row<<endl;
        cout<<"Column No. : "<<ptr->col<<endl;
        cout<<"Value : "<<ptr->value<<endl;

        ptr=ptr->next;
    }
    }
};


int main()
{
    Matrix o1;

    int m,n;

    cout<<"Enter rows and columns of Sparse Matrix respectively."<<endl;
    cin>>m>>n;

    cout<<endl<<"Enter the Sparse Matrix."<<endl;

    int a[m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }

    int Count=0;
    cout<<endl<<"The Matrix is :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"  ";

            if(a[i][j]!=0)
            {
                Count++;
            }
        }

    cout<<endl;
    }

      o1.createNode(m,n,Count);


     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(a[i][j]!=0)
            {

                o1.createNode(i,j,a[i][j]);
            }
        }

    }

    o1.Traversal();

}
