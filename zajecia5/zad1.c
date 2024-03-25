#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;



void add_first(node_t** head, int liczba){
    node_t * newlist = NULL;
    newlist = (node_t *) malloc(sizeof(node_t));
    newlist->val= liczba;
    newlist->next = *head;
    *head = newlist;
    
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

add_first(&start,7);

printf("%d",start->val);

return 0;
}