#include<stdio.h>

struct node
{
    int data;
    struct node *link;
};
int count_element(struct node *head){
    int cnt=0;
    while(head!=NULL)
    {
       cnt++;
       head=head->link;
    }
    printf("Count=%d\n",cnt);
}
int display_element(struct node *head){
    while(head!=NULL)
    {
        printf("%d---%d\n",head->data,head->link);
        head=head->link;
    }
}
int add_elemente(struct node *head){
    int elem;
    printf("Insert the value:\n");
    scanf("%d",&elem);

    struct node *newelement=malloc(sizeof(struct node));
    newelement->data=elem;
    newelement->link=NULL;
    while(head->link!=NULL)
    {
        head=head->link;
    }
    head->link=newelement;
    printf("%d added Succesfully\n",elem);
}
int add_elementb(struct node *head){
    int elem;
    printf("Insert the value:\n");
    scanf("%d", &elem);
    struct node *temp=malloc(sizeof(struct node));
    temp->data=elem;
    temp->link=NULL;

    temp->link=head;
    head=temp;
    printf("%d Added Successfully\n",elem);
    return head;
}

int add_elementc(struct node *head)
{
    struct node *ptr;
    ptr=head;
    int pos,val;
    printf("Enter the position and value:");
    scanf("%d %d", &pos,&val);

    struct node *temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->link=NULL;

    int n=1;
    while(n!=pos-1){
        ptr=ptr->link;
        n++;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    printf("%d at %d position added successfully",val,pos);
}
int main()
{
    //Manually Inserting two Elements;;;;
    struct node *head=malloc(sizeof(struct node));
    head->data=11;
    head->link=NULL;

    struct node *second=malloc(sizeof(struct node));
    second->data=21;
    second->link=NULL;

    head->link=second;

    while(1)
    {
        printf("What do you want:\n1.Show the elements.\n2.Number of element.\n3.Insert an element at end\n4.Insert an element at beginning\n5.Insert an element at certain position\n");
        int x;
        scanf("%d",&x);
        if(x==1)
        {
            display_element(head);
        }
        else if(x==2)
        {
            count_element(head);
        }
        else if(x==3)
        {
            add_elemente(head);
        }
        else if(x==4)
        {
            head=add_elementb(head);
        }
        else{
            add_elementc(head);
        }
    }

}
