#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *link;
};


struct node* add_at_end(struct node *ptr , int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}



int reverse(struct node *head)
{
    struct node * prev,*current,*next;
    prev=NULL;
    current=next=head;
    while(next != NULL)
    {
        next=next->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
};

void print(struct node *head)
{
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
    printf("\n");
}

int main()
{
    struct node *head= (struct node *)malloc(sizeof(struct node));
    head->i=14;
    head->link=NULL;
    struct node  *ptr=head;
    ptr=add_at_end(ptr,28);
    ptr=add_at_end(ptr,42);
    ptr=add_at_end(ptr,90);

    printf("Before Reversing: ");
    print(head);
    head=reverse(head);
    printf("After Reversing: ");
    print(head);
}
