#include<stdio.h>
int MAX=100;
int stack[100],top=-1;
void push(int data)
{
    if(top==MAX-1)
        printf("full");
    else
    {
        top++;
        stack[top]=data;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("empty\n");
        return(0);
    }
    else
    {
        top--;
        return stack[top];
    }
}
int main()
{
    int i=0;
    for(i=1;i<111;i++)
    {
        push(i);
    }
    for(i=1;i<111;i++)
    {
        printf("%d\n",pop());
    }
}
