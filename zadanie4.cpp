#include <iostream>

int main()
{


    for (int i = 1;i <= 200;i++) {

        if (i % 5 == 0 && i % 7 == 0) {
            printf("FooBar\n");
            continue;
        }
        else if (i % 5 == 0) {
            printf("Foo\n");
            continue;
        }
        else if (i % 7 == 0) {
            printf("Bar\n", i);
            continue;
        }
        printf("%d\n", i);
    }


    return 0;
}
