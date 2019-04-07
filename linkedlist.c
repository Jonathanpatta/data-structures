#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;
void insert_beg(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
    printf("inserted beg\n");
}
void insert_end(int data)
{
    struct node *temp,*tem;
    tem=(struct node*)malloc(sizeof(struct node));
    tem->data=data;
    tem->next=NULL;
    if(start==NULL)
        start=tem;
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=tem;
        printf("inserted end\n");
    }
}
void traverse()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
int main()
{
    insert_beg(20);
    insert_end(30);
    insert_beg(70);
    traverse();
    return(0);
}
