#include <stdio.h>
#include <stdlib.h>

// TO-DO:
// 1- Create hashmap with no-logic hashcode
// 2- Mock data
// 3- Implement open addressing with linear probing for the hash
// 4- Implement a hashcode function

typedef enum { false, true } bool;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* head; // global variable - pointer to head of the DLL.
Node* tail; // global variable - pointer to tail of the DLL.

// GetNewNode creates a new node initialized with data and NULL for prev, next
Node* GetNewNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return NULL; // out of memory

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// isEmpty returns whether the DLL is empty
bool isEmpty() {
    if(head == NULL) return true;
    return false;
}

// AddFirst adds a new node to the start of the list
int AddFirst(int data) {
    // create new node with err check if out of memory
    Node *node;
    if((node = GetNewNode(data)) == NULL) return -1; 

    // if DLL is empty, add new node as head and tail
    if(isEmpty()) {
        head = tail = node;
    } else { // add new node to start of list
        node->next = head;
        head->prev = node;
        head = node;
    }

    return 0;
}

// AddLast adds a new node to the end of the list
int AddLast(int data) {
    // create new node with err check if out of memory
    Node *node;
    if((node = GetNewNode(data)) == NULL) return -1; 

    // if DLL is empty, add new node as head and tail
    if(isEmpty()) {
        head = tail = node;
    } else { // add new node to end of list
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    return 0;
}

// DeleteFirst removes the first node from the list
int DeleteFirst() {
    // no nodes in list (list is empty)
    if(isEmpty()) return -1;

    // one node in list
    if(head->next == NULL) {
        free(head);
        head = tail = NULL;
    } else { // remove first node from list and update head
        Node *node = head->next;
        free(head);
        node->prev = NULL;
        head = node;
    }

    return 0;
}


// DeleteLast removes the last node from the list
int DeleteLast() {
    // no nodes in list (list is empty)
    if(isEmpty()) return -1;

    // one node in list
    if(tail->prev == NULL) {
        free(tail);
        head = tail = NULL;
    } else { // remove last node from list and update tail
        Node *node = tail->prev;
        free(tail);
        node->next = NULL;
        tail = node;
    }
 
    return 0;
}


// Print displays for each node in the list: data, memory address of current, prev and next nodes
void Print() {
    // check if list is empty
    if(isEmpty()) {
        printf("Empty list.\n");
        return;
    }

    Node *node = head;
    int n = 0;

    printf("\n\n---------- printing nodes in list ----------\n");
    while(node != NULL) {
        printf("Node %d:\n\tdata: %d\n\taddress: %p\n\tprev: %p\n\tnext: %p\n\n", n++, node->data, node, node->prev, node->next);
        node = node ->next;
    }

    printf("---------- end of list ----------\n");
}

// DeleteList pops all nodes starting from the head until the list is empty
void DeleteList() {
    while (-1 != DeleteFirst());
}

int main() {
    // driver code to test the DLL
    head = tail = NULL;

    return 0;
}


