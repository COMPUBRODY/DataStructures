#ifndef SNIPS_H
#define SNIPS_H

#include <ctype.h>
#include <stdio.h>

//Filter if non Alphabetic char
int containsNonAlpha(const char *str);

//swaping two strings
void swapStrings(char **a, char **b);

// quick sort function
void quickSort(char **arr, int low, int high, int(*cmp_func)(const char* a, const char* b));

// Partition the array
int partition(char **arr, int low, int high, int (*cmp_func)(const char* a, const char *b));

//deletes the string at given index
void deleteStringAtIndex(char *arr[], int *len, int index);

#endif /*SNIPS_H */