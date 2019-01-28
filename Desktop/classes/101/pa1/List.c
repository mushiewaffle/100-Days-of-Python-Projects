//Kevin Wu
//kwu30

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

 //FILE *in, *out;

Node newNode(int data){
	Node N = malloc(sizeof(NodeObj));
	N->data = data;
	N->prev=NULL;
	N->next=NULL;
	return(N);
}
void freeNode(Node* pN){
	if(pN!=NULL && *pN!=NULL){
		free(*pN);
		*pN=NULL;
	}
}

// Constructors-Destructors ---------------------------------------------------
List newList(void){ // returns a List which points to a new empty list object
	List L = NULL;
	L =  malloc(sizeof(ListObj));
	L->size = 0;
	L->head = NULL;
	L->tail = NULL;
	return(L);
}
void freeList(List* pL){ // frees all heap memory associated with its List* argument,
                       // and sets *pL to NULL
	while(pL!=NULL && *pL!=NULL){
		//while(!isEmpty(*pL)){
		deleteFront(*pL); 
	}
	free(*pL);
    *pL = NULL;
} //?

// Access functions -----------------------------------------------------------
int length(List L){ // Returns the number of nodes in this List.
	return L->size;
}
int frontValue(List L){// Returns the integer in the front Node.
// Precondition: L has at least one Node on it.
	return L->head->data;
}
int backValue(List L){ // Returns the integer in the back Node.
// Precondition: L has at least one Node on it.
	return L->tail->data;
}
int getValue(Node N){ // Returns the integer in Node N. // Precondition: N is not NULL
	return N->data;
}
int equals(List A, List B){ // Returns 1 if if List A and List B are the same integer
                       // sequence, otherwise returns 0.
	Node currA = A->head;
	Node currB = B->head;
	while(currA!=A->tail && currB!=B->tail){
		if(currA->data != currB->data){
			return 0;
		}
		currA=currA->next;
		currB=currB->next;
	}
	if(A->tail!=B->tail){
		return 0;
	}
	if(currA!=A->tail || currB!=B->tail){ //if same elements but one list bigger than other return 0 too
		return 0;
	}
	return 1;
}

// Manipulation procedures ----------------------------------------------------
void clear(List L){ // Resets this List to the empty state.
	if(L==NULL){ //case 1: empty list
		//do nothing
	} else if(L->head == L->tail){ //case 2: one element
		free(L); 
		L->head=NULL;
		L->tail=NULL;
	} else{ //case 3 : multiple elements
		Node nodeCurr = L->head;
		while(nodeCurr!=L->tail){
			nodeCurr=nodeCurr->next;
			free(nodeCurr->prev);
			nodeCurr->prev=NULL;
		} 
		free(L);
		L->tail = NULL;
	}
}
Node getFront(List L){ // If List is non-empty, returns the front Node, without changing the List.  Otherwise, does nothing.
	if(L!=NULL){
		//do nothing
	}return L->head;
}
Node getBack(List L){ // If List is non-empty, returns the back Node, without changing the List.  Otherwise, does nothing.
	if(L!=NULL){
		//do nothing
	}return L->tail;
}
Node getPrevNode(Node N){ // Without changing the List that N is on, returns the
// Node that is previous to Node N on its List.  If there is no previous Node, returns NULL.
	if(N->prev == NULL){ //if no previous Node
		return NULL;
	} return N->prev;
}
Node getNextNode(Node N){ // Without changing the List that N is on, returns the
// Node that is next after Node N on its List.  If there is no next Node, returns NULL.
	if(N->next == NULL ){ //if no next Node
		return NULL;
		//printf("expected");
	}else{
		return N->next;
	}

}
void prepend(List L, int data){ // Inserts a new Node into List L before the front
                             // Node that has data as its value. If List is empty,
                             // makes that new Node the only Node on the list.
	if(L->head== NULL && L->tail == NULL){ //case 1: no elements
		L->head= L->tail=newNode(data);
	}else { //case 2: multiple elements
		Node temp = L->head;
		L->head = newNode(data);
		L->head->next = temp;
		temp->prev = L->head;
		L->head->prev = NULL;
	}
	L->size++;
}
void append(List L, int data){  // Inserts a new Node into List L after the back
                             // Node that has data as its value. If List is empty,
                             // makes that new Node the only Node on the list.
	if(L->head ==NULL && L->tail == NULL){ //case 1: no elements
		L->head = L->tail = newNode(data);
		//L->tail=newNode(data);
	}else {
	    L->tail->next = newNode(data);
		L->tail->next->prev = L->tail;
		L->tail = L->tail->next;
	}
	L->size++;
}
void insertBefore(List L, Node N, int data){ // Insert a new Node into Node N’s list // before Node N that has data as its value.
                             // Assume that Node N is on List L.  If Node N is
                             // the front of List L, then N becomes the new front.
                             // Precondition:  Node N is not NULL
	if(N==NULL){ // Precondition:  Node N is not NULL
		//do nothing
	} else if(N==L->head){ //if front of list put in new head
		Node temp=L->head;
		L->head=newNode(data);
		L->head->next=temp;
		L->head->next->prev=L->head;
		L->size++;
	} else{
		Node temp = N->prev;
		N->prev = newNode(data);
		temp->next=N->prev;
		N->prev->prev=temp;
		N->prev->next = N;
		L->size++;
	}
}
//(List L, Node N, int data)?
void insertAfter(List L, Node N, int data){ // Insert a new Node into Node N’s list // after Node N that has data as its value.
// Assume that Node N is on List L.  If Node N is the back of List L, then N becomes the new back.
// Precondition:  Node N is not NULL
	if(N==NULL){
		//do nothing
	}else if(N==L->tail){
		N->next = newNode(data);
		L->tail = N->next;
		L->size++;
	} else{
		Node temp = N->next;
		N->next = newNode(data);
		N->next->next = temp;
		temp->prev = N->next;
		N->next->prev=N;
		L->size++;
	}
}
void deleteFront(List L){ // Assume that Node N is on List L.  If Node N is the back of List L, then N becomes the new back.
// Precondition:  Node N is not NULL
// Deletes the front Node in List L.
// Precondition:  L has at least one Node on it.
	if(L==NULL){
		//do nothing
	}else if(L->head == L->tail){ //1 element
		free(L->head);
		free(L->tail);
		L->head = NULL;
		L->tail = NULL;
		L->size--;
	}else{
		Node temp = L->head;
		L->head = L->head->next;

		free(temp);
		temp = NULL;
		
		L->head->prev = NULL;
		L->size--;
	}
}
void deleteBack(List L){ // Deletes the back Node in List L.
// Precondition:  L has at least one Node on it.
	if(L==NULL){
		//do nothing
	}else if(L->head == L->tail){ //1 element
		free(L->head);
		free(L->tail);
		L->head = NULL;
		L->tail = NULL;
		L->size--;
	}else{
		Node temp = L->tail;
		L->tail = L->tail->prev;

		free(temp);
		temp = NULL;

		L->tail->next=NULL;
		L->size--;
	}
}



// Other operations -----------------------------------------------------------
void printList(FILE* out, List L){ // Prints the values in List L from front to back
                                   // to the file pointed to by out, formatted as a
                                   // space-separated string.
                                   // For those familiar with Java, this is similar
                                   // to toString()in Java.
	Node curr = L->head;
	if(L==NULL){
		fprintf(stderr, "List error: print called on empty List");
		exit(1);
	}
	while(curr != NULL){
		fprintf(out, "%d", curr->data);
        fprintf(out, " ");
		curr = curr -> next;
	}

	
}

