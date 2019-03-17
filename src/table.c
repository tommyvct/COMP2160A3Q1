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
#include <assert.h>


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
int tableSize = 0;


static int insertHere(int toInsert);
static void validateList();


// "destroy" will deallocate all nodes in a linked list object
// and will set "top" to NULL.
void clearTable()
{
    validateList();

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

    validateList();
}

// insert the given int. 
// return true if inserted, false if dulplicate
Boolean insertItem(int toInsert)
{
    validateList();

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

        tableSize++;
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
    
    tableSize++;
    validateList();
    return true;
}

// starts a list traversal by getting the data at top.
// returns false if top == NULL.
Boolean firstItem(int * const item)
{
    validateList();

    Boolean result = false;

    if (top)
    {
        *item = top->number;

        traverseNode = top;//->next;

        result = true;
    }

    validateList();
    return result;
}

// gets the data at the current traversal Node and increments the traversal.
// returns false if we're at the end of the list.
Boolean nextItem(int * const item)
{
    validateList();

    Boolean result = false;

    if (traverseNode->next)
    {
        *item = traverseNode->next->number;

        traverseNode = traverseNode->next;

        result = true;
    }

    validateList();
    return result;
}


// find out where to insert. 
// Return -999 if duplicate.
static int insertHere(int toInsert)
{
    validateList();

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
        validateList();
        return -999;
    }
    else
    {
        validateList();
        return ret;
    }
}

// Search for given item. 
// true if found, false if not found.
Boolean search(int item)
{
    validateList();
    Node * curr = top;

    while (curr != NULL)
    {
        if (item == (curr -> number))
        {
            validateList();
            return true;
        }

        curr = curr -> next;
    }

    validateList();
    return false;
}

// remove the given item. 
// true if given item is found and removed from table.
Boolean removeItem( int item )
{
    validateList();

    Node *prev = top;
    Node *temp = NULL;

    if (!search(item))
    {
        validateList();
        return false;
    }

    if (item == top->number)
    {
        temp = top;
        top = top->next;
        free(temp);

        tableSize--;
        validateList();
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

            tableSize--;
            validateList();
            return true;
        }

        prev = prev->next;
    }

    validateList();
    return false;
}

// print the whole table
void printTable()
{
    validateList();

    Node * curr = top;

    while (curr != NULL)
    {
        printf("%d ", curr->number);
        curr = curr -> next;
    }

    printf("\n");
    validateList();
}

static void validateList()
{
    #ifndef NDEBUG
        Node * curr = top;
        int nodeCount = 0;
        int prevNum;
    #endif

    if (tableSize == 0)
    {
        assert(top == NULL);
    }
    else if (tableSize == 1)
    {
        assert(top -> next == NULL);
    }
    else
    {
        assert (top != NULL && top -> next != NULL);
    }

    #ifndef NDEBUG
        while(curr != NULL)
        {
            nodeCount++;
            prevNum = curr -> next;
            curr = curr -> next;
            if (curr != NULL)
            {
                assert(prevNum >= curr -> number);
                prevNum = curr -> number;
            }
        }
        assert (nodeCount == tableSize);
    #endif
}