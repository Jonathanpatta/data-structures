#include<stdio.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node*left,*right;
};
struct node* create_node(int data1)
{
    struct node *nod;
    nod=(struct node*)malloc(sizeof(struct node));
    nod->data=data1;
    nod->left=NULL;
    nod->right=NULL;
    return(nod);
}
struct node* insert_node(struct node *root,int dat)
{
    if(root==NULL)
    {
        root=create_node(dat);
    }
    else if(dat>=root->data)
    {
        root->right=insert_node(root->right,dat);
    }
    else
    {
        root->left=insert_node(root->left,dat);
    }
    //printf("inserted%d\n",root->data);
    return(root);
}
struct node* insert_nodewor(struct node *root,int data)
{
    struct node *temp;
    temp=root;
    if(root==NULL)
    {
        root=create_node(data);
        printf("inserted wor\n");
        return(root);
    }
    else
    {
        while(temp!=NULL)
        {
            if(data>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        temp=create_node(data);
        printf("inserted wor\n");
        return(temp);
    }
    printf("inserted wor\n");
}
bool search(struct node *root,int data)
{
    struct node* temp=root;
    if(temp==NULL)
    {
        printf("not found\n");
        return false;
    }
    if(temp->data==data)
    {
        printf("found\n");
        return true;
    }
    else if(data>temp->data)
    {
        //root=root->right;
        return search(temp->right,data);
    }
    else
    {
        //root=root->left;
        return search(temp->left,data);
    }
}
void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d,",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d,",root->data);
}
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d,",root->data);
    inorder(root->right);
}
struct node* findmin(struct node *root)
{
    struct node *temp=root;

    if(root->left!=NULL)
        return(findmin(root->left));
    if(root->right!=NULL)
        return(findmin(root->right));
    if(root->data<temp->data)
    {
        temp=root;
    }
    return temp;
}
struct node* delete_node(struct node *root,int data)
{
    if(root==NULL)
        return(NULL);
    else if(data > root->data)
    {
        root->right=delete_node(root->right,data);
    }
    else if(data < root->data)
    {
        root->left=delete_node(root->left,data);
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            struct node *temp;
            temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
        return(root);
    }
}
int main()
{
    bool l;
    int t;
    struct node *start=NULL,*p=NULL;
    start=insert_node(start,10);
    start=insert_node(start,5);
    start=insert_node(start,50);
    start=insert_node(start,15);
    l=search(start,30);
    postorder(start);
    p=findmin(start);
    printf("\n%d",p->data);
    t=delete_node(start,10);
    postorder(start);printf("\n");
    preorder(start);printf("\n");
    inorder(start);printf("\n");
    return(0);
}
