#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\nv\n", current->val);
        current = current->next;
    }
    printf("\n");
}

void remove_last(node_t * head) {
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    current->next = NULL;
}

int main() {
node_t * start = NULL;
start = (node_t *) malloc(sizeof(node_t));
node_t * head = start;
head->val = 1;
head->next = (node_t *) malloc(sizeof(node_t));
head->next->val = 2;
head->next->next = (node_t *) malloc(sizeof(node_t));
head->next->next->val = 5;
head->next->next->next = NULL;

print_list(start);

remove_last(&start);

print_list(start);

return 0;
}