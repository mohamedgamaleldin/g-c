#include <stdio.h>
#include <stdlib.h>

// TO-DO:
// + Mock data file
// + Create cache struct
// + Add cache buffer
// + Add meta data (hit ratio, latency)
// + Add hashmap
// + Add get/set functions
// + Write unit tests

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* head; // global variable - pointer to head of the DLL.

// GetNewNode creates a new node initialized with data and NULL for prev, next
Node* GetNewNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL) return NULL; // out of memory

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Push adds a new node to the beginning of the list
int Push(int data) {
    Node *node;
    // create new node with err check if out of memory
    if((node = GetNewNode(data)) == NULL) return -1; 

    // if DLL was not empty, add new node to beginning of list, else skip and initialize head to new node
    if(head != NULL) {
        head->prev = node;
        node->next = head;
    }

    head = node;

    return 0;
}

// Pop removes the top most node from the list
int Pop() {
    // no nodes in list (list is empty)
    if(head == NULL) return -1;

    // one node in list
    if(head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Node *node = head->next;
        free(head);
        node->prev = NULL;
        head = node;
    }

    return 0;
}

// Print displays for each node in the list: data, memory address of current, prev and next nodes
void Print() {
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
    while (-1 != Pop());
}

int main() {
    // driver code to test the DLL
    head = NULL;

    printf("Push returned: %d\n", Push(1));
    printf("Push returned: %d\n", Push(2));
    printf("Push returned: %d\n", Push(3));

    Print();
    Pop();
    Print();
    DeleteList();
    Print();

    return 0;
}
