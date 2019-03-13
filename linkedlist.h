#ifndef _LL_H
#define _LL_H

typedef enum BOOL { false, true } bool;


typedef struct Node node;

struct Node
{
  int   number;
  node  *next;
};

// "destroy" will deallocate all nodes in a linked list object
// and will set "top" to NULL.
void destroy();


// "build" will create an ordered linked list consisting
// of the first "size" even integers.
void build( int size );


// starts a list traversal by getting the data at top.
// returns false if top == NULL.
bool firstNode( int *item );

// gets the data at the current traversal node and increments the traversal.
// returns false if we're at the end of the list.
bool nextNode( int *item );

// "print" will output an object's entire linked list 
// to the standard output device -- one "number" per line.
void print();

#endif