
#include<iostream>
#include<cctype>
#include<math.h>
using namespace std;

#define  SIZE 30;

template<class T>
class Stack
{
    T element[30];
    int top=-1;

public:
    void create_empty_stack()
    {
        this->top=-1;
    }

  int isEmpty()
  {
    if(this->top==-1)
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
    this->top++;
    this->element[this->top]=a;
}

T pop()
{
    T temp=this->element[this->top];
    this->top--;
    return temp;
}

int peek()
{
    int temp=this->element[this->top];;
    return temp;
}

int Size()
{

    return (this->top+1);
}
};

int main()
{
    Stack <int>s;
    string str;

    cout<<"Enter the equation u want to solve..."<<endl;
    cin>>str;


    s.create_empty_stack();
    for(int i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            s.push((str[i]-'0'));
        }

        else
        {
            int m=s.pop();
            int n=s.pop();

            switch(str[i])
            {
            case '+':
                s.push(n+m);
                break;
            case '-':
                s.push(n-m);
                break;
            case '*':
                s.push(n*m);
                break;
            case '/':
                s.push(m/n);
                break;

            case '^':
                s.push(pow(n,m));
                break;
            }
        }
    }

    int k=s.pop();
    cout<<k;

}
