#include <stdio.h>
#include <stdlib.h>

void reverseArray(int* arr, int num){
    int *start = arr;
    int *end = arr + num -1;
    while(start < end){
        //swaps elements at start and end pointers
        int temp = *start;
        *start = *end;
        *end = temp;
        //move start towards the end and end towards the start
        start++;
        end--;
    }
}

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int)); //Issue here
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    // reverse tha array
    reverseArray(arr,num);


    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

