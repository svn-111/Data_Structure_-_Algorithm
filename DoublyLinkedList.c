#include<stdio.h>

int CntNode=0;
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

int InsertElementEnd(struct node *head,int data)
{

    struct node *curr=malloc(sizeof(struct node));
    curr->data=data;
    curr->next=NULL;
    curr->prev=NULL;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    curr->prev=head;
    head->next=curr;
    printf("Element added Successfully...\n");
}

int InsertElementBeg(struct node *head,int data)
{
    struct node *curr=malloc(sizeof(struct node));
    curr->data=data;
    curr->prev=NULL;
    curr->next=NULL;
    head->prev=curr;
    curr->next=head;
    head=curr;
    return head;
}

int CountElement(struct node *head)
{
    if(head==NULL)
        printf("LinkedList is empty...\n");
    else
    {
        CntNode=0;
        while(head!=NULL)
        {
            CntNode++;
            head=head->next;
        }
        printf("Number of Elemenet : %d\n",CntNode);
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
        else if(opt==3)
        {
            while(1)
            {
                printf("Where do you want to insert Element?\n");
                printf("1.At End;\n2.At Beginning;\n3.At Certain Position;\n4.Back\n");
                int opt1;
                scanf("%d",&opt1);
                if(opt1==4)
                {
                    break;
                }
                else
                {
                    int data;
                    printf("Enter Data:");
                    scanf("%d",&data);
                    if(opt1==1)
                    {
                        InsertElementEnd(head,data);
                    }
                    else if(opt1==2)
                    {
                        head=InsertElementBeg(head,data);
                    }
                    else if(opt1==3)
                    {
                        //InsertElmentCer(head);
                    }
                }

            }

        }
        else if(opt==2)
        {
            CountElement(head);
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
