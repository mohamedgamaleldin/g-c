#include <stdio.h>
#include <stdlib.h>

/* Linked List Exercise

TO-DO:
- Node struct (DONE)
- Push at beginning of list (DONE)
- Push at end of list (DONE)
- Pop (DONE)
- List All (DONE)
- Removing last item of list
- Removing a specific index in the list
- Create docker container
- Add profiling

*/
    
typedef struct node {
    int val;
    struct node *next;
} node_t;

int pushFirst(node_t **head, int val);
int pushLast(node_t *head, int val);
int pop(node_t **head);
void printAll(node_t * head);

int main() {
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) return 1;
    head->next = NULL;

    while(-1 != pop(&head));
    
    return 0;
}

int pushFirst(node_t **head, int val) {
    node_t *new_node = NULL;
    new_node = malloc(sizeof(node_t));
    if (new_node == NULL) return -1;

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;

    return 0;
}

int pushLast(node_t *head, int val) {
    node_t *curr = head;
    while (curr->next != NULL) curr = curr->next;

    curr->next = malloc(sizeof(node_t));
    if(curr->next == NULL) return -1;
    curr->next->val = val;
    curr->next->next = NULL;

    return 0;
}

int pop(node_t **head) {
    if((*head) == NULL) return -1;
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);

    return 0;
}

void printAll(node_t *head) {
    node_t *curr = head;
    int i = 0;

    while(curr != NULL) {
        printf("node %d:%d\n", i++, curr->val);
        curr = curr->next;
    }
}
