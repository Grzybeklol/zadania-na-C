#include <stdio.h>
#include <stdlib.h>

struct Point{
    int x;
    int y;
};

struct Rectangle{
    struct Point *top_left;
    struct Point *top_right;
    struct Point *bottom_left;
    struct Point *bottom_right;
};

void funkcja1(struct Point * p) {
    p->x++;
    p->y++;
}

void funckcja2(struct Rectangle * r){
    int width = abs(r->top_right->x - r->top_left->x);
    int height = abs(r->top_right->y - r->bottom_right->y);
    int pole = width * height;
    int obwud = 2 * (width + height);
    printf("pole prostokatu: %d\nobwud prostokatu: %d", pole, obwud);
}

int main() {
    struct Point p1 = {-1, 4};
    funkcja1(&p1);
    printf("punkt x: %d y: %d \n", p1.x, p1.y);

    struct Point p2 = {5, 5};
    struct Point p3 = {0, 0}; 
    struct Point p4 = {5, 0}; 

    struct Rectangle r1;
    r1.top_left = &p1;
    r1.top_right = &p2;
    r1.bottom_left = &p3;
    r1.bottom_right = &p4;

    funckcja2(&r1);

    return 0;
}
