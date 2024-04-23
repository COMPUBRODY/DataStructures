#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LEN 1000
int numbers[10];

void counting_nums(char* character){

    char temp = *character;

    if( temp >= '0' && temp <= '9' ){
        numbers[temp - '0'] +=1;
    }
    
    return;

}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    

    char* string;
    
    string = (char*)malloc(sizeof(char)*LEN);

    scanf(" %s ", string);


    for(int i=0; i<strlen(string); i++){
        counting_nums(&string[i]);
    }

    for(int k=0; k<sizeof(numbers)/sizeof(numbers[0]) ; k++){
        printf("%d ", numbers[k]);
    }

    free(string);


    return 0;
}
