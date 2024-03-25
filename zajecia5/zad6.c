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


void add_index(node_t **head, int index, int value) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }
    new_node->val = value;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node_t *current = *head;
    node_t *prev = NULL;
    int iter = 0;

    while (current != NULL && iter < index) {
        prev = current;
        current = current->next;
        iter++;
    }

    if (iter < index) {
        free(new_node);
        return;
    }

    prev->next = new_node;
    new_node->next = current;
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

add_index(&start,1,5);

print_list(start);

return 0;
}