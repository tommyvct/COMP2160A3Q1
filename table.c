#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef enum BOOL { false, true } bool;

// Linked list node definition
typedef struct Node node;

struct Node
{
    int number;
    node *next;
};

static node *top = NULL;
int size = 0;

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

bool insert(int toInsert)
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
bool firstNode(int *item)
{
    bool result = false;

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
bool nextNode(int *item)
{
    bool result = false;

    if (traverseNode)
    {
        *item = traverseNode->number;

        traverseNode = traverseNode->next;

        result = true;
    }

    return result;
}

// "print" will output an object's entire linked list
// to the standard output device -- one "number" per line.
void print()
{
    int value;

    if (firstNode(&value))
    {
        do
        {
            printf("%d\n", value);
        } while (nextNode(&value));
    }
}

int insertHere(int toInsert)
{
    node * curr = top;
    int ret = 0;
    
    while(toInsert >= (curr -> number))
    {
        if (toInsert = (curr -> number))
        {
            return -999;
        }
        ret++;
        curr = curr -> next;
    }

    return ret;
}
