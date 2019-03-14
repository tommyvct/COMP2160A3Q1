#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef enum BOOL { false, true } bool;

// Linked list node definition
typedef struct Node node;
typedef bool Boolean;


struct Node
{
    int number;
    node *next;
};

static node *top = NULL;
int size = 0;

static int insertHere(int toInsert);

// used to track where we are for the list traversal methods
static node *traverseNode = NULL;

// "destroy" will deallocate all nodes in a linked list object
// and will set "top" to NULL.
void clearTable()
{
    node *curr = top;
    node *temp = NULL;

    while (curr != NULL)
    {
        // flip order to see it blow up...
        temp = curr;
        curr = curr->next;

        free(temp);
    }

    top = NULL;
}

Boolean insertItem(int toInsert)
{
    node *newNode = NULL;
    int whereToInsert = insertHere(toInsert);
    node * insertAfterNode = top;
    node * insertBeforeNode = NULL;

    // dulplicate
    if (whereToInsert == -999)
    {
        return false;
    }
    // insert at top
    else if (whereToInsert == 0)
    {
        newNode = malloc(sizeof(node));
        newNode->number = toInsert;
        newNode->next = top;
        top = newNode;

        size++;
        return true;
    }
    
    for(int i = 0; i < whereToInsert - 1; i++)
    {
        insertAfterNode = insertAfterNode -> next;
    }

    insertBeforeNode = insertAfterNode -> next;

    newNode = malloc(sizeof(node));
    newNode->number = toInsert;
    insertAfterNode->next = newNode;
    newNode->next = insertBeforeNode;
    
    size++;
    return true;
}

// starts a list traversal by getting the data at top.
// returns false if top == NULL.
Boolean firstItem(int * const item)
{
    Boolean result = false;

    if (top)
    {
        *item = top->number;

        traverseNode = top->next;

        result = true;
    }

    return result;
}

// gets the data at the current traversal node and increments the traversal.
// returns false if we're at the end of the list.
Boolean nextItem(int * const item)
{
    Boolean result = false;

    if (traverseNode)
    {
        *item = traverseNode->number;

        traverseNode = traverseNode->next;

        result = true;
    }

    return result;
}


static int insertHere(int toInsert)
{
    node * curr = top;
    Boolean duplicate = false;
    int ret = 0;

    // for every element in list
    while (curr != NULL)
    {
        if (toInsert == (curr -> number))
        {
            duplicate = true;
        }
        
        //
        if (toInsert > (curr -> number))
        {
            ret++;
        }

        curr = curr -> next;
    }

    if (duplicate)
    {
        return -999;
    }
    else
    {
        return ret;
    }
}

Boolean search(int item)
{
    node * curr = top;

    while (curr != NULL)
    {
        if (item == (curr -> number))
        {
            return true;
        }

        curr = curr -> next;
    }

    return false;
}

Boolean removeItem( int item )
{
    node *prev = top;
    node *temp = NULL;

    if (!search(item))
    {
        return false;
    }

    if (item == top->number)
    {
        temp = top;
        top = top->next;
        free(temp);

        size--;
        return true;
    }

    while (prev != NULL)
    {
        // if reached the last item, nothing after it
        if (prev->next == NULL)
        {
            break;
        }
        // if found item
        if (prev->next->number == item)
        {
            // node to delete
            temp = prev->next;
            // skip it
            prev->next = temp->next;
            // delete from memory
            free(temp);

            size--;
            return true;
        }

        prev = prev->next;
    }

    return false;
}

void printTable()
{
    node * curr = top;

    while (curr != NULL)
    {
        printf("%d ", curr->number);
        curr = curr -> next;
    }

    printf("\n");
}