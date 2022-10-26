#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int key;
    struct node *ptr;
};

struct node *create(int key)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->ptr = NULL;
    return temp;
}

bool isempty(struct node *head)
{
    return head==NULL;
}

int getMin(struct node *head)
{
    if(isempty(head))
    {
        printf("Empty priority queue\n");
        exit(0);
    }

    return head->key;
}

//Remove the node with maximum priority

struct node *getnewhead(struct node *head)
{
    struct node *temp = head;
    head = head->ptr;
    free(temp);

    return head;

}

struct node *insert(struct node *head, int key)
{
    struct node *temp = create(key);
    if(head->key > key)
    {
       
        temp->ptr = head;
        return temp;
    }

    else
    {
        struct node *start = head;
        struct node *startprev = head;

        while(key > start->key)
        {
            if(start->ptr != NULL)
            {
                startprev = start;
                start = start->ptr;
            }

            else
            {
                start->ptr = temp;
                return head;
            }

        }

        startprev->ptr = temp;
        temp->ptr = start;

        return head;
    }
}

int main()
{
    struct node *head = create(5);
    head->ptr = create(10);

    head->ptr->ptr = create(15);

    // head = getnewhead(head);

    struct node *head1 = head;

    while(head != NULL)
    {
        printf("%d ", head->key);
        head = head->ptr;
    }
    printf("\n");
    // int mini = getMin(head1);

    head1 = insert(head1, 4);

    head = head1;
    while(head != NULL)
    {
        printf("%d ", head->key);
        head = head->ptr;
    }
}