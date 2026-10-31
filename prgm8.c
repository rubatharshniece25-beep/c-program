#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *curr, *prev, *temp;

// Prepend operation
void prepend(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }

    printf("data prepended: %d\n", data);
}

// Append operation
void append(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("data appended: %d\n", data);
}

// Display operation
void display()
{
    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Insert operation
void insert(int data, int pos)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if(pos == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        int i = 0;

        curr = head;
        prev = NULL;

        while(curr != NULL && i < pos)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }

        newnode->next = curr;
        prev->next = newnode;
    }

    printf("data inserted: %d at position: %d\n", data, pos);
}

// Search operation
void search(int data)
{
    temp = head;

    int found = 0, pos = 1;

    while(temp != NULL)
    {
        if(temp->data == data)
        {
            found = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }

    if(found == 0)
    {
        printf("data not found");
    }
    else
