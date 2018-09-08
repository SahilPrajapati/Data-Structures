#include<iostream>
#include<string.h>
using namespace std;

struct Stack
{
    char container[20];
    int top;
};

void push(Stack *s,char element)
{
    s->top++;
    s->container[s->top] = element;
}

char pop(Stack *s)
{
    return s->container[s->top--];
}

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
    int n,counter = 0;
    string expression;
    cout<<endl<<"Enter expression: "<<endl;
    cin>>expression;
    char result_expression[expression.length()];

    Stack result;
    result.top = -1;

    for(int i = 0;i<expression.length();i++)
    {
        if(expression[i] == '+'||expression[i] == '-'||expression[i] == '/'||expression[i] == '*'||expression[i] == '^')
        {
            if(result.top == -1)
            {
                push(&result,expression[i]);
            }
            else if(precedence(expression[i]) > precedence(result.container[result.top]))
            {
                push(&result,expression[i]);
            }
            else
            {


               while(precedence(expression[i]) <= precedence(result.container[result.top]))
                {

                    result_expression[counter] = pop(&result);

                    counter++;
                    }


                push(&result,expression[i]);
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
        result_expression[counter] = pop(&result);
        counter++;
    }

    cout<<endl<<"Postfix is: "<<result_expression;
}

