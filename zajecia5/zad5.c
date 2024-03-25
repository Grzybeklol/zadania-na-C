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

void remove_index_wih_value(node_t **head, int value) {
    node_t *current = *head;
    node_t *prev = NULL;

    while (current != NULL && current->val != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
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

remove_index_wih_value(&start,2);

print_list(start);

return 0;
}