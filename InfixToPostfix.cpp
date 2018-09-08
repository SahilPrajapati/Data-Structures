
#include<iostream>
#include<string.h>
using namespace std;

template<class T>

class Stack
{
    public:
    char container[20];
     int top=-1;
void push(T element)
{
    this->top++;
    this->container[this->top] = element;
}

char pop()
{
    return this->container[this->top--];
}
};
int precedence(char s)
{
    if(s == '+'|| s=='-')
    return 1;
    else if(s == '*'|| s=='/')
    return 2;
    else if(s == '^')
    return 3;
    else
    return -1;
}
int main(void)
{
    Stack<char>result;
    int n,counter = 0;

    string expression;
    cout<<endl<<"Enter expression: "<<endl;
    cin>>expression;

    char result_expression[expression.length()];

    result.top = -1;

    for(int i = 0;i<expression.length();i++)
    {
        if(expression[i] == '+'||expression[i] == '-'||expression[i] == '/'||expression[i] == '*'||expression[i] == '^')
        {
            if(result.top == -1)
            {
                result.push(expression[i]);
            }
            else if(precedence(expression[i]) > precedence(result.container[result.top]))
            {
                result.push(expression[i]);
            }
            else
            {


               while(precedence(expression[i]) <= precedence(result.container[result.top]))
                {

                    result_expression[counter] = result.pop();

                    counter++;
                    }


                result.push(expression[i]);
                }
            }


        else
        {
            result_expression[counter] = expression[i];
            counter++;
        }

    }

    while(result.top>=0)
    {
        result_expression[counter] = result.pop();
        counter++;
    }

    cout<<endl<<"Postfix is: "<<result_expression;
}

