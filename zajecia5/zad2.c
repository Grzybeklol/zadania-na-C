#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;



void pop(node_t** head){
    node_t *temp = *head;
    *head = (*head)->next;
    
}

int main() {
node_t * start = NULL;
start = (node_t *) malloc(sizeof(node_t));
node_t * head = start;
head->val = 1;
head->next = (node_t *) malloc(sizeof(node_t));
head->next->val = 2;
head->next->next = NULL;

printf("%d\n", start->val);

pop(&start);

printf("%d",start->val);

return 0;
}