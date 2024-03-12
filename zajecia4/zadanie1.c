#include <stdio.h>

int silnia(int n){
    if(n==1){
        return 1;
    }
    else if (n>1)
    {
        return n * silnia(n-1);
    }
    return 1;
}

int main(){
    int n = 6;
    printf("%d",silnia(n));
}