#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_
#include <stdlib.h>
#include <stdio.h>

typedef struct NodeObj{
	int data;
	struct NodeObj* prev;
	struct NodeObj* next;
}NodeObj;

typedef NodeObj* Node;

typedef struct ListObj{
	int size;
	Node head;
	Node tail;
}ListObj;

typedef ListObj* List;

//typedef struct NodeObj* Node;
Node newNode(int data);
//void freeNode(Node* pN);

//typedef struct ListObj* List;
List newList(void); // returns a List which points to a new empty list object
void freeList(List* pL); // frees all heap memory associated with its List* argument,
                       // and sets *pL to NULL
// Access functions -----------------------------------------------------------
int length(List L);
int frontValue(List L);
int backValue(List L);
int getValue(Node N);
int equals(List A, List B); 
// Manipulation procedures ----------------------------------------------------
void clear(List L);
Node getFront(List L);
Node getBack(List L);
Node getPrevNode(Node N);
Node getNextNode(Node N);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, Node N, int data);
void insertAfter(List L, Node N, int data);
void deleteFront(List L);
void deleteBack(List L);
void printList(FILE* out, List L);

#endif