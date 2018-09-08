
#include<iostream>
using namespace std;

#define  SIZE 30

template<class T>
class Stack
{
    T element[SIZE];
    int top=-1;

public:
    void create_empty_stack()
    {
        top=-1;
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

  int isFull()
  {
    if(top==SIZE-1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
  }


  void push(T a)
{

    if(this->isFull()==1)
    {
        cout<<endl<<"OVERFLOW..."<<endl;
    }

    else
    {
    top++;
    element[top]=a;
    }

}

T pop()
{

  if(this->isEmpty()==1)
    {
        cout<<endl<<"UNDERFLOW..."<<endl;
        return 0;
    }

    else
    {
    T temp=element[top];
    top--;
    return temp;
    }
}

int peek()
{
    int temp=element[top];
    return temp;
}

int Size()
{

    return (top+1);
}
};


int main()
{
    Stack <int>s;

    s.create_empty_stack();


       /* char ch;
        do
        {
            int n;
            cout<<endl<<endl<<"<---Choose--->"<<endl;
            cout<<"1. Push"<<endl;
            cout<<"2. Pop"<<endl;
            cin>>n;

            if(n==1)
            {
                int item;
                cout<<endl<<"Enter Element to push"<<endl;
                cin>>item;
                s.push(item);
            }
            if(n==2)
            {
                int temp=s.pop();
              cout<<"Popped element:"<<temp<<endl;
            }


            cout<<endl<<"Do again(Y/N)"<<endl;
            cin>>ch;
        }while(ch=='y'||ch=='Y');
*/
    string str;
    cout<<"Enter the string to check palindrome.."<<endl;
    cin>>str;

    s.create_empty_stack();
    int half=str.length()/2;

    for(int i=0;i<half;i++)
    {
        s.push(str[i]);
    }

    int c=0;
    for(int i=half+1;i<str.length();i++)
    {
       char ch=s.pop();
       if(ch==str[i])
       {
           c++;
       }
       else
        break;
    }

    if(c==half)
        cout<<endl<<"Yes it is a palindrome..."<<endl;

    else
        cout<<endl<<"NO it is not palindrome..."<<endl;
}
