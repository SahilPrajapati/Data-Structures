#include<iostream>
#include<cctype>
#include<math.h>
using namespace std;

#define SIZE 30

struct Stack
{
    char element[SIZE];
    int top=-1;
}s1;


void create_empty_stack(Stack *s)
{
    (*s).top=-1;
}

int isEmpty(Stack *s)
{
    if((*s).top==-1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}


int isFull(Stack *s)
{
    if((*s).top==SIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Stack *s,char a)
{
    (*s).top++;
    (*s).element[(*s).top]=a;
}

char pop(Stack *s)
{
    char temp=(*s).element[(*s).top];
    (*s).top--;
    return temp;
}

int peek(Stack *s)
{
    int temp=(*s).element[(*s).top];;
    return temp;
}

int Size(Stack *s)
{

    return ((*s).top+1);
}

int main()
{
    string str;

    cout<<"Enter the equation u want to solve..."<<endl;
    cin>>str;

    create_empty_stack(&s1);
    for(int i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            push(&s1,(str[i]-'0'));
        }

        else
        {
            int m=pop(&s1);
            int n=pop(&s1);

            switch(str[i])
            {
            case '+':
                push(&s1,n+m);
                break;
            case '-':
                push(&s1,n-m);
                break;
            case '*':
                push(&s1,n*m);
                break;
            case '/':
                push(&s1,m/n);
                break;

            case '^':
                push(&s1,pow(n,m));
                break;
            }
        }
    }

    int k=pop(&s1);
    cout<<k;

}
