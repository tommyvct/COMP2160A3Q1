//--------------------------------------------------------------
// Name: Shang Wu
// Student Number: 7852291
// Course: COMP2160, Section A01
// Instructor: Mehdi Niknam
// Assignment 3, Question 1
// 
// Implementation of Table ADT
// Values inserted are unique, and internally sorted within a linked list. 
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// Boolean defenition
typedef enum BOOL {false, true} bool;
typedef bool Boolean;

// Linked list Node definition
typedef struct Node Node;
struct Node
{
    int number;
    Node *next; 
};


// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;
static Node *top = NULL;
int size = 0;


static int insertHere(int toInsert);


// "destroy" will deallocate all nodes in a linked list object
// and will set "top" to NULL.
void clearTable()
{
    Node *curr = top;
    Node *temp = NULL;

    while (curr != NULL)
    {
        // flip order to see it blow up...
        temp = curr;
        curr = curr->next;

        free(temp);
    }

    top = NULL;
}

// insert the given int. 
// return true if inserted, false if dulplicate
Boolean insertItem(int toInsert)
{
    Node *newNode = NULL;
    int whereToInsert = insertHere(toInsert);
    Node * insertAfterNode = top;
    Node * insertBeforeNode = NULL;

    // dulplicate
    if (whereToInsert == -999)
    {
        return false;
    }
    // insert at top
    else if (whereToInsert == 0)
    {
        newNode = malloc(sizeof(Node));
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

    newNode = malloc(sizeof(Node));
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

        traverseNode = top;//->next;

        result = true;
    }

    return result;
}

// gets the data at the current traversal Node and increments the traversal.
// returns false if we're at the end of the list.
Boolean nextItem(int * const item)
{
    Boolean result = false;

    if (traverseNode->next)
    {
        *item = traverseNode->next->number;

        traverseNode = traverseNode->next;

        result = true;
    }

    return result;
}


// find out where to insert. 
// Return -999 if duplicate.
static int insertHere(int toInsert)
{
    Node * curr = top;
    Boolean duplicate = false;
    int ret = 0;

    // for every element in list
    while (curr != NULL)
    {
        // check for duplicates
        if (toInsert == (curr -> number))
        {
            duplicate = true;
        }
        
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

// Search for given item. 
// true if found, false if not found.
Boolean search(int item)
{
    Node * curr = top;

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

// remove the given item. 
// true if given item is found and removed from table.
Boolean removeItem( int item )
{
    Node *prev = top;
    Node *temp = NULL;

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
            // Node to delete
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

// print the whole table
void printTable()
{
    Node * curr = top;

    while (curr != NULL)
    {
        printf("%d ", curr->number);
        curr = curr -> next;
    }

    printf("\n");
}