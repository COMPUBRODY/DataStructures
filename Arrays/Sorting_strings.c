
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* 
    0x61 = 97 = a
    0x62
    0x63
    0x64
    0x65
    66
    67
    68
    69
    6a
    6b
    6c
    6d
    6e
    6f
    70
    71
    72
    73
    74
    75
    76
    77
    78
    79
    0x7a = 122 =  z
*/

#define NUM_STRINGS 50 // num of strings
#define MAX_LENGTH_TOTAL 2500 //total length of all the strings

// Comparision function pointer type
typedef int(*cmp_func)(const char* a, const char* b);

//swaping two strings
void swapStrings(char **a, char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
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

// quick sort function
void quickSort(char **arr, int low, int high, int(*cmp_func)(const char* a, const char* b)){
    if(low < high){
        int pi = partition(arr, low, high, cmp_func);

        quickSort(arr, low, pi -1, cmp_func);
        quickSort(arr, pi +1, high, cmp_func);
    }
}

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

int countDistinctCharacters(const char* str){
    int count[26] = {0}; //Array to count distinct characters from 'a' to 'z'

    // count distinct characters in the string
    for(int i= 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            count[str[i] - 'a'] = 1; //mark the character as present
        }
    }
    // count the total number of distinct characters
    int distinctCount = 0;
    for(int i=0;i<26; i++){
        distinctCount += count[i];
    }
    return distinctCount;
}

// sort the strings in lexicographically non-decreasing order
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a,b);
}

//sort the strings in lexicographically non-increasing order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b,a);
}

// sort the strings in non-decreasing order of the number of distinct characters present in them.
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int countA = countDistinctCharacters(a);
    int countB = countDistinctCharacters(b);

    //if two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first
    if(countA == countB){
        return strcmp(a,b);
    }

    return countA - countB;
}

// sort the strings in non-decreasing order of their lengths.
int sort_by_length(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    //if two strings have the same length, then the lexicographically smaller string should appear first.
    if(lenA == lenB){
        return strcmp(a, b);
    }
    // Otherwose, sort by length
    return lenA - lenB;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    quickSort(arr, 0, len -1, cmp_func);
}

// 1<= No. Strings <= 50
// 1<= total length of all the stings <= 2500
// not use qsort
// only lower-case english alphabets


int main(){

    char *arr[] = {"4", "wkue", "qoi", "sbv", "fekls"};
    int len = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i<len; i++){
        if (containsNonAlpha(arr[i])){
            deleteStringAtIndex(arr, &len, i);
        }
    }

    string_sort(arr, len, lexicographic_sort);

    for(int i=0; i<len; i++){
        printf(" %s \n", arr[i]);
    }

    printf("\n");

    string_sort(arr, len, lexicographic_sort_reverse);

    for(int i=0; i<len; i++){
        printf(" %s \n", arr[i]);
    }

    printf("\n");

    string_sort(arr, len, sort_by_number_of_distinct_characters);

    for(int i=0; i<len; i++){
        printf(" %s \n", arr[i]);
    }
    printf("\n");

    string_sort(arr, len, sort_by_length);

    for(int i=0; i<len; i++){
        printf(" %s \n", arr[i]);
    }

    return 0;
}