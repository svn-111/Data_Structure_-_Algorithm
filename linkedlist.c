#include<stdio.h>
#include<stdlib.h>
//using namespace std;

struct node
{
    int data;
    struct node *link;
};


void element_of_nodes(struct node *head){
    int cnt=0;
    if(head==NULL)
    {
        printf("LinkedLIst is empty");
    }
    else
    {
        struct node *ptr=NULL;
        //ptr=head;
        while(head!=NULL)
        {
            cnt++;
            printf("%d\n",head->data);
            head=head->link;
        }
        //printf("Number of Nodes=%d",cnt);
    }

}
void count_of_nodes(struct node *head){
    int cnt=0;
    if(head==NULL)
    {
        printf("LinkedLIst is empty");
    }
    else
    {
        struct node *ptr=NULL;
        //ptr=head;
        while(head!=NULL)
        {
            cnt++;
            //printf("%d\n",head->data);
            head=head->link;
        }
        printf("Number of Nodes=%d\n",cnt);
    }

}
/*void insertnode(struct node *head,int val)
{
    cout<<"IM here"<<endl;
    struct node *ptr=NULL;
    ptr=head;
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->link=NULL;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=newnode;
    printf("Added Succesfully");
}*/

void insertnode(struct node *head,int val)
{
    struct node *ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
    printf("Added Successfully");
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    current = malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;

    head->link->link=current;

    while(1)
    {
        printf("What do you want:\n1.Show the elements.\n2.Number of element.\n3.Insert an element\n");
        int n;
        scanf("%d",&n);
        if(n==1)
        {
            element_of_nodes(head);
        }
        else if(n==2)
        {
            count_of_nodes(head);
        }
        else
        {
            printf("Enter the data:");
            int x;
            scanf("%d",&x);

            insertnode(head,x);
        }
    }

}
