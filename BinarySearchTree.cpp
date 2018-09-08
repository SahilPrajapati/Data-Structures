#include<iostream>
#include<stdlib.h>
using namespace std;
int i=0;
template<class T>

class Node
{
public:

    T key;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class Tree
{
    public:
    Node<T>* Root;

    Tree()
    {
        Root=NULL;
    }

    Node<T>* createNode(T data)
    {
        Node<T>* temp=new Node<T>;
        temp->key=data;

        temp->left=NULL;
        temp->right=NULL;
    }

    void Insert(Node<T>* temp,T data)
    {
        //INSERTING THE ROOT...
        if(Root==NULL)
        {
            Root=createNode(data);
        }


        //INSERTING THE AFTER THE ROOT
        else
        {

            //IF THE ELEMENT IS ALREADY PRESENT...
            if(temp->key==data)
            {
                cout<<"Can't Insert the data "<<data<<" as it is already present..."<<endl;
                i--;
                return;
            }


            //IF THE ELEMENT IS NEW...
            else
            {

            // TO THE RIGHT...
                if(temp->key<data)
                {
                    if(temp->right!=NULL)
                    {
                        //RECURSION TO THE RIGHT...
                        Insert(temp->right,data);
                    }

                    else
                    {
                        temp->right=createNode(data);
                    }
                }


            // TO THE LEFT...

                else
                {
                    if(temp->left!=NULL)
                    {
                         //RECURSION TO THE LEFT...
                        Insert(temp->left,data);
                    }

                    else
                    {
                    temp->left=createNode(data);
                    }
                }
            }
        }


    }//INSERT ENDED...

    void InOrder(Node<T>* Root)
    {
        if(Root!=NULL)
        {

            InOrder(Root->left);

            cout<<Root->key<<" ";

            InOrder((Root->right));
        }
    }

    void PostOrder(Node<T>* Root)
    {
        if(Root!=NULL)
        {

            PostOrder(Root->left);

            PostOrder((Root->right));

            cout<<Root->key<<" ";
        }
    }

    void PreOrder(Node<T>* Root)
    {
        if(Root!=NULL)
        {
            cout<<Root->key<<" ";

            PreOrder(Root->left);

            PreOrder((Root->right));
        }
    }

    void LevelOrderTraversal(Node<T>* Root)
    {
        for(int i=0;i<=Height(Root);i++)
            PrintLevel(Root,i);
    }
    void PrintLevel(Node<T>* Root,int level)
    {
        if(Root==NULL)
            return;

        if(level==1)
            cout<<Root->key<<" ";

        else if(level>1)
        {
            PrintLevel(Root->left,level-1);
            PrintLevel(Root->right,level-1);
        }
    }

    Node<T>* Search(Node<T>* Root,T data)
    {
        if(Root==NULL)
            return NULL;

        if(Root->key==data)
            return Root;

        if(Root->key<data)
            Search(Root->right,data);

        else if(Root->key>data)
            Search(Root->left,data);
    }

    Node<T>* MaximumNode(Node<T>* Root)
    {
        Node<T>* temp=Root;

        while(temp->right!=NULL)
            temp=temp->right;

        return temp;
    }

    Node<T>* MinimumNode(Node<T>* Root)
    {
        Node<T>* temp=Root;


        while(temp->left!=NULL)
            temp=temp->left;

        return temp;
    }

    int CountTotalNodes(Node<T>* Root)
    {
        if(Root==NULL)
            return 0;

        return CountTotalNodes(Root->left)+CountTotalNodes(Root->right)+1;
    }

    int CountInternalNodes(Node<T>* Root)
    {
        if(Root==NULL)
            return 0;

        if(Root==NULL||(Root->left==NULL&&Root->right==NULL))
            return 0;

        return CountInternalNodes(Root->left) + CountInternalNodes(Root->right) + 1;
    }

    int CountLeafNodes(Node<T>* Root)
    {
        if(Root==NULL)
            return 0;

        if(Root->left==NULL&&Root->right==NULL)
            return 1;

        return CountLeafNodes(Root->left) + CountLeafNodes(Root->right);
    }

    int CountLeftNodes(Node<T>* Root)
    {
        int Count =0;
        if(Root==NULL)
            return 0;

        if(Root->left!=NULL)
            Count=Count+ CountLeftNodes(Root->left)+1;

        if(Root->right!=NULL)
            Count=Count+ CountLeftNodes(Root->right);


    return Count;
    }

    int CountRightNodes(Node<T>* Root)
    {
        if(Root==NULL)
            return 0;

        if(Root->right==NULL)
           return CountRightNodes(Root->left);

        if(Root->right!=NULL)
           return CountRightNodes(Root->left)+ CountRightNodes(Root->right)+1;


//    return Count;
    }

    int Height(Node<T>* Root)
    {
        if(Root==NULL)
            return 0;

        int h1=Height(Root->left);
        int h2=Height(Root->right);

        if(h1>h2)
            return h1+1;

        else
            return h2+1;
    }

    void MorrisInOrder(Node<T>* Root)
    {
        Node<T> *temp;
        Node<T> *p=Root;

        while(p!=NULL)
        {
            if(p->left==NULL)
            {
                cout<<p->key<<" ";
                p=p->right;
            }


            else
            {
                temp=p->left;

                while(temp->right!=NULL&&temp->right!=p)
                    temp=temp->right;

                if(temp->right==NULL)
                {
                    temp->right=p;
                    p=p->left;
                }

                else
                {
                    cout<<p->key<<" ";
                    temp->right=NULL;

                    p=p->right;
                }
            }
        }

    }


     void MorrisPreOrder(Node<T>* Root)
    {
        Node<T> *temp;
        Node<T> *p=Root;

        while(p!=NULL)
        {
            if(p->left==NULL)
            {
                cout<<p->key<<" ";
                p=p->right;
            }


            else
            {
                temp=p->left;

                while(temp->right!=NULL&&temp->right!=p)
                    temp=temp->right;

                if(temp->right==NULL)
                {
                    cout<<p->key<<" ";
                    temp->right=p;
                    p=p->left;
                }

                else
                {
                    temp->right=NULL;

                    p=p->right;
                }
            }
        }

    }


    Node<T>* InOrderPredecessor(Node<T>* Root,T data)
    {

        Node<T>* temp1;
        temp1=Search(Root,data);

        if(temp1==NULL)
            return NULL;

        if(temp1->left!=NULL)
        {
            Node<T>* temp2=temp1->left;

            return MaximumNode(temp2);
        }

        else
        {
            Node<T>* parent=Root;
            Node<T>* pred=NULL;

            while(parent!=temp1)
            {
                if(temp1->key<parent->key)
                    parent=parent->left;

                else
                    {
                        pred=parent;
                        parent=parent->right;
                    }
            }

            if(pred)
                return pred;

            else
                {
                    cout<<endl<<"Predecessor is not present."<<endl;
                   return NULL;
                }

        }
    }

   Node<T>* InOrderSuccessor(Node<T>* Root, T data)
    {
        Node<T>* temp1=Search(Root, data);

        if(temp1==NULL)
            return 0;

        if(temp1->right!=NULL)
        {
            Node<T>* temp2=temp1->right;

            return MinimumNode(temp2);
        }

        else
        {
            Node<T> *suc=NULL;
            Node<T> *parent=Root;

            while(parent!=temp1)
            {
                if(temp1->key<parent->key)
                {
                    suc=parent;
                    parent=parent->left;
                }

                else
                    parent=parent->right;
            }

            if(suc)
                return suc;

            else
                {
                    cout<<endl<<"Successor is not present."<<endl;
                    return NULL;
                }
        }
    }


    void Delete(Node<T>* Root1, T data)
    {
        Node<T>* temp=Search(Root1,data);

        Node<T>* parent=Root1;

        if(temp==NULL)
        {
            cout<<"Element is not present "<<endl;
            return;
        }


        if(parent->key!=temp->key)
        {
            //Finding the parent of the node which has to be deleted
            while((parent->left!=temp)&&(parent->right!=temp))
            {
                if(temp->key>parent->key)
                    parent=parent->right;

                else
                    parent=parent->left;
            }
        }


        //Leaf Node to Be Deleted
        if((temp->left==NULL)&&(temp->right==NULL))
        {

            //The node to be deleted is on parent's left
            if(parent->left==temp)
                parent->left=NULL;

            //The node to be deleted is on parent's right
            else if(parent->right==temp)
                parent->right=NULL;


            //Node to be deleted is parent
            //i.e. Root having no child
            else if(parent->key==temp->key)
                 Root=NULL;
        }



        //If Node to Be deleted has only one child
       else if((temp->left==NULL)||(temp->right==NULL))
        {
            //The node to be deleted is on parent's left
            if(parent->left==temp)
            {
                //Node to be deleted have left child
                if(temp->left!=NULL)
                    parent->left=temp->left;


                  //Node to be deleted have right child
                else if(temp->right!=NULL)
                    parent->left=temp->right;
            }

            //The node to be deleted is on parent's right
            else if(parent->right==temp)
            {
                 //Node to be deleted have left child
                if(temp->left!=NULL)
                    parent->right=temp->left;


                  //Node to be deleted have right child
                else if(temp->right!=NULL)
                    parent->right=temp->right;
            }



            //Node to be deleted is parent
            //i.e. Root having one child
            else if(parent->key==temp->key)
            {
                //Root have Child on Left
                if(parent->left!=NULL)
                    Root=Root->left;


                //Root have Child on Left
                else
                    Root=Root->right;

            }
        }


        //Node to be deleted has two children
        else if((temp->left!=NULL)&&(temp->right!=NULL))
        {
            int ch;
            cout<<endl<<"The node has two child."<<endl;
            cout<<"1.) Merging"<<endl<<"2.) Copying"<<endl;
            cout<<endl<<"How u want to delete ? : ";
            cin>>ch;

            switch(ch)
            {
            case 1:
                 //If the node to be deleted is not just before the leaf node
                 InOrderPredecessor(Root,temp->key)->right=temp->right;

                //The node to be deleted is on parent's left
                   if(parent->left==temp)
                      parent->left=temp->left;


            //The node to be deleted is on parent's right
                   else if(parent->right==temp)
                      parent->right=temp->left;



                 //If the Node to be deleted is Root node
                if(parent->key==temp->key)
                    Root=temp->left;//Making Root's left as Root


                break;



            //Deletion By Copying
            case 2:

                Node<T>* temp1=InOrderPredecessor(Root,temp->key);

                int n=temp1->key;

                Delete(Root,temp1->key);

                temp->key=n;

                return;

                break;

            }
        }

          delete temp;
          cout<<"Deleted..."<<endl;
    }


    void MirrorImage(Node<T>* Root)
    {
        if(Root==NULL)
            return ;

        MirrorImage(Root->left);
        MirrorImage(Root->right);

        Node<T>*temp=Root->left;

        Root->left=Root->right;

        Root->right=temp;
    }

};


int main()
{
    Tree<int> obj;
    char ch;
    char ch1;
    Node<int>* temp;

    do
    {
        int n;
        i++;
        cout<<endl<<endl<<"Enter the Element No."<<i<<"  :  ";
        cin>>n;
        obj.Insert(obj.Root,n);

        cout<<endl<<"Insert Again(Y/N)?  :  ";
        cin>>ch;

    }while(ch=='y'||ch=='Y');

    do
    {
        int choice;
        cout<<endl<<endl<<"        MENU"<<endl<<endl;
        cout<<"0.) Insert"<<endl;
        cout<<"1.) Traversal By Recursion"<<endl;
        cout<<"2.) Traversal By Morris"<<endl;
        cout<<"3.) Search"<<endl;
        cout<<"4.) Maximum Node"<<endl;
        cout<<"5.) Minimum Node"<<endl;
        cout<<"6.) Counting Nodes"<<endl;
        cout<<"7.) Height"<<endl;
        cout<<"8.) Delete"<<endl;
        cout<<"9.) Mirror Image"<<endl;
        cout<<"9.) InOrder Predecessor & Successor."<<endl;
        cout<<endl<<"Enter Choice : ";
        cin>>choice;

        switch(choice)
        {

            //INSERTING...
           case 0:
               int t;
                    cout<<endl<<"Enter the Element to insert "<<endl;
                    cin>>t;
                    obj.Insert(obj.Root,t);

                    break;

           case 1:

                if(obj.Root)
                {
                cout<<endl<<"In Order    :   ";
                obj.InOrder(obj.Root);

                cout<<endl<<"Pre Order   :   ";
                obj.PreOrder(obj.Root);

                cout<<endl<<"Post Order  :   ";
                obj.PostOrder(obj.Root);

                cout<<endl<<"Level Order :   ";
                obj.LevelOrderTraversal(obj.Root);
                }

                else
                    cout<<endl<<"Tree is Empty..."<<endl;


            break;


            case 2:

                if(obj.Root)
                {
                cout<<endl<<"In Order   :   ";
                obj.MorrisInOrder(obj.Root);

                cout<<endl<<"Pre Order  :   ";
                obj.MorrisPreOrder(obj.Root);
                }


                else
                    cout<<endl<<"Tree is Empty..."<<endl;
            break;

            case 3:
                int ele;
                cout<<endl<<"Enter Element to be Search : ";
                cin>>ele;

                 temp=obj.Search(obj.Root,ele);

                if(temp)
                    cout<<endl<<"Element "<<temp->key<<" is present."<<endl;

                else if(temp==NULL)
                    cout<<endl<<"Element is not present "<<endl;

                break;

            case 4:
                temp=obj.MaximumNode(obj.Root);
                cout<<"Maximum Node have the data : "<<temp->key<<endl;

                break;

            case 5:
                temp=obj.MinimumNode(obj.Root);
                cout<<"Minimum Node have the data : "<<temp->key<<endl;

                break;


            case 6:
                cout<<endl<<"a.) Total Nodes : "<<obj.CountTotalNodes(obj.Root);
                cout<<endl<<"b.) Leaf Nodes : "<<obj.CountLeafNodes(obj.Root);
                cout<<endl<<"c.) Internal Nodes : "<<obj.CountInternalNodes(obj.Root);
                cout<<endl<<"d.) Left Nodes : "<<obj.CountLeftNodes(obj.Root);
                cout<<endl<<"e.) Right Nodes : "<<obj.CountRightNodes(obj.Root);

               break;


            case 7:
                cout<<endl<<"Height is : "<<obj.Height(obj.Root);

                break;


            case 8:
                int del;
                cout<<endl<<"Enter the element to be Deleted : ";
                cin>>del;


                obj.Delete(obj.Root,del);

                break;

            case 9:
                obj.MirrorImage(obj.Root);
                cout<<endl<<"Done.."<<endl;
                break;

            case 10:
                int no;
                cout<<endl<<"Enter the no. whose Predecessor & Successor u want to find. : ";
                cin>>no;

                temp=obj.InOrderPredecessor(obj.Root,no);
                cout<<endl<<"Predecessor :  "<<temp->key;

                temp=obj.InOrderSuccessor(obj.Root,no);
                cout<<endl<<"Successor   :  "<<temp->key;

                break;

            default:
                cout<<endl<<"Wrong Input try again"<<endl;

        }

        cout<<endl<<endl<<"Do Again(Y/N)?  :  ";
        cin>>ch;

    }while(ch=='y'||ch=='Y');
}
