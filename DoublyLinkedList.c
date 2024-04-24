#include<stdio.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} ;

int DisplayElement(struct node *head)
{
    if(head==NULL)
    {
        printf("LinkedList is Empty");
    }
    else
    {
        while(head!=NULL)
        {
            printf("%d----%d----%d\n",head->prev,head->data,head->next);
            head=head->next;
        }
    }
}
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=10;
    head->prev=NULL;
    head->next=NULL;

    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=20;
    head->next=ptr;
    ptr->prev=head;
    ptr->next=NULL;



    while(1)
    {
        printf("What do you want?\n1.Show the elements.\n2.Counting the elements.\n3.Insert an element.\n4.Delete an element\n");
        printf("Enter Option:");
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {
            DisplayElement(head);
        }
        else if(opt==2)
        {

        }
        else if(opt==3)
        {

        }
        else if(opt==4)
        {

        }
        else
        {
            break;
        }

    }
}
