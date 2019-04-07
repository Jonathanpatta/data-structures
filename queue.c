#include<stdio.h>
int MAX=100;
int queue[100],front=-1,rear=-1;
void enqueue(int data)
{
    if(rear==MAX-1)
    {
        printf("full");
    }
    else
    {
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=data;printf("done\n");
    }
}
int dequeue()
{
    int t=0;
    if(front==-1||rear<front)
    {
        printf("empty\n");
        rear=front=-1;
        t=0;
        return(t);
    }
    else
    {
        if(front==rear+1)
        {
            t=queue[front];
            front=rear=-1;
            return(t);
        }
        else
        {
            t=queue[front];
            front++;
            return(t);
        }
    }
}
int main()
{
    int i;
    enqueue(5);printf("%d,%d,%d\n",front,rear,queue[0]);
    enqueue(6);printf("%d,%d,%d\n",front,rear,queue[1]);
    enqueue(9);printf("%d,%d,%d\n",front,rear,queue[2]);
    printf("%d",dequeue());
    printf("%d",dequeue());
    printf("%d",dequeue());
    printf("%d",dequeue());
}
