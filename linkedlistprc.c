#include<stdio.h>
int cntee=0;
struct node
{
    int data;
    struct node *link;
};

//COUNTING ELEMENT

int count_element(struct node *head)
{
    if(head==NULL)
        printf("Linked List is Empty\n");
    else
    {
        cntee=0;
        while(head!=NULL)
        {
            cntee++;
            head=head->link;
        }
        printf("Count=%d\n",cntee);
    }
}

//PRINT ALL ELEMENT

int display_element(struct node *head)
{
    if(head==NULL)
        printf("Linked List is Empty\n");
    else
    {
        while(head!=NULL)
        {
            printf("%d---%d\n",head->data,head->link);
            head=head->link;
        }
    }

}

//ADD ELEMENT AT THE END

int add_elemente(struct node *head)
{
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

//ADD ELEMENT AT THE BEGINNING

int add_elementb(struct node *head)
{
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

//ADD ELEMENT AT CERTAIN POSITION

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
    while(n!=pos-1)
    {
        ptr=ptr->link;
        n++;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    printf("%d at %d position added successfully.\n",val,pos);
}

//DELETE ELEMENT OF CERTAIN POSITION

int delete_elementc(struct node *head)
{
    struct node *ptr1,*ptr2,*ptr3;
    ptr1=head;
    // ptr2=head;
    //ptr3=head;
    int pos;
    printf("Which position do you want to remove?\nEnter Position:");
    scanf("%d",&pos);
    int cnt=1;
    while(cnt!=pos-1)
    {
        ptr1=ptr1->link;
        cnt++;
    }
    //printf("%d----%d\n",ptr1->data,ptr1->link);
    ptr2=ptr1->link;
    ptr3=ptr2->link;
    /* cnt=1;
     while(cnt!=pos+1)
     {
         ptr2=ptr2->link;
         cnt++;
     }*/
    //printf("%d----%d",ptr2->data,ptr2->link);
    ptr1->link=ptr3;
    free(ptr2);
    ptr2=NULL;
    printf("position %d deleted successfully\n",pos);
}

//DELENT ELEMENT AT BEGINNING

int delete_elementb(struct node *head)
{
    struct node *temp=head;
    head=head->link;
    free(temp);
    temp=NULL;
    printf("1st position Deleted Successfully\n");
    return head;
}
/*int delete_elemente(struct node *head)
{
    struct node *ptr;
    ptr=head;
    int cnt=1;
    while(cnt!=cntee-1)
    {
        ptr=ptr->link;
        cnt++;
    }
    //printf("%d---%d",ptr->data,ptr->link);
    ptr->link=NULL;
    printf("Last position deleted successfully\n");
}
*/

//DELEMENT ELEMENT AT ELEMENT

int delete_elemente(struct node *head)
{
    struct node *ptr,*ptr2;
    ptr=head;
    while(ptr->link!=NULL)
    {
        ptr2=ptr;
        ptr=ptr->link;
        //cnt++;
    }
    //Another Way Using only one pointer
    /*while(ptr->link->link!=NULL)
    {
        ptr=ptr->link;
    }
    free(ptr->link)
    ptr->link=NULL;*/
    //printf("%d---%d",ptr->data,ptr->link);
    ptr2->link=NULL;
    free(ptr);
    ptr=NULL;
    printf("Last position deleted successfully\n");
}

//DELETE ENTIRE LINKED LIST

int delete_entire(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        free(head);
        head=ptr;
    }
    return head;
    printf("All node Deleted Successfully\n");
}

//REVERSE LINKED LIST

reverse_ll(struct node *head)
{
    struct node *ptr1,*ptr2;
    ptr1=NULL,ptr2=NULL;
    while(head!=NULL)
    {
        ptr2=head->link;
        head->link=ptr1;
        ptr1=head;
        head=ptr2;
    }

    head=ptr1;
    printf("LinkedList Reversed Successfully...\n");
    return head;
}

//MAIN FUNCTION

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
        printf("What do you want:\n1.Show the elements.\n2.Number of element.\n3.Insert an element\n");
        printf("4.Delete an element.\n5.Delete entire list.\n6.Reverse LinkedList.\n");
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
            while(1)
            {
                int opt1;
                printf("1. At end;\n2. At beginning;\n3. At certain position;\n4. Back;\n");
                printf("Enter option:");
                scanf("%d",&opt1);
                if(opt1==1)
                {
                    add_elemente(head);
                }
                else if(opt1==2)
                {
                    head=add_elementb(head);
                }
                else if(opt1==3)
                {
                    add_elementc(head);
                }
                else if(opt1==4)
                {
                    break;
                }
                else
                {
                    printf("Invalid option.\n");
                }
            }

        }
        else if(x==4)
        {
            while(1)
            {
                int opt2;
                printf("1. At end;\n2. At beginning;\n3. At certain position;\n4. Back;\n");
                printf("Enter option:");
                scanf("%d",&opt2);
                if(opt2==1)
                {
                    delete_elemente(head);
                }
                else if(opt2==2)
                {
                    head=delete_elementb(head);

                }
                else if(opt2==3)
                {
                    delete_elementc(head);
                }
                else if(opt2==4)
                {
                    break;
                }
                else
                {
                    printf("Invalid option.\n");
                }
            }

        }
        else if(x==5)
        {
            head=delete_entire(head);
        }
        else if(x==6)
        {
            head=reverse_ll(head);
        }
        else
        {
            printf("Invalid.\n");
        }
    }

}
