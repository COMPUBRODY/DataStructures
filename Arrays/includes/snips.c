#include "snips.h"


//Filter if non Alphabetic char
int containsNonAlpha(const char *str){
    while(*str){
        if (!isalpha(*str)){
            return 1;
        }
        str++;
    }
    return 0;
}


//swaping two strings
void swapStrings(char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// quick sort function
void quickSort(char **arr, int low, int high, int(*cmp_func)(const char* a, const char* b)){
    if(low < high){
        int pi = partition(arr, low, high, cmp_func);

        quickSort(arr, low, pi -1, cmp_func);
        quickSort(arr, pi +1, high, cmp_func);
    }
}


// Partition the array
int partition(char **arr, int low, int high, int (*cmp_func)(const char* a, const char *b)){
    char *pivot = arr[high];
    int i = low -1;

    for ( int j = low; j < high; j++){
        if(cmp_func(arr[j], pivot) <0){
            i++;
            swapStrings(&arr[i], &arr[j]);
        }
    }
    swapStrings(&arr[i + 1], &arr[high]);
    return i + 1;
}



//deletes the string at given index
void deleteStringAtIndex(char *arr[], int *len, int index){
    if(index < 0 || index >= *len) {
        printf("Invalid index, Nothing deleted.\n");
        return;
    }

    //shift all elements after the index one position to the left
    for ( int i= index; i<(*len -1); i++){
        arr[i] = arr[i + 1];
    }
    // update the lenght of the array
    (*len)--;

}