#include <stdio.h>

#define len 4

void printArray(int* array, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void permute(int *array, int start, int end){
    if(start == end){
        printArray(array, end + 1); 
        return;
    }

    for(int i = start; i <= end; i++){
        int temp = array[start];
        array[start] = array[i];
        array[i] = temp;

        permute(array, start + 1, end);

        temp = array[start];
        array[start] = array[i];
        array[i] = temp;
    }
}

int main(){
    int array[] = {1, 2, 3, 4}; 
 
    permute(array, 0, len-1); 
    return 0;
}