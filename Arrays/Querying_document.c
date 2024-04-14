/*
    A document is represented as a collection paragraphs, 
    a paragraph is represented as a collection of sentences, 
    a sentence is represented as a collection of words and 
    a word is represented as a collection of lower-case ([a-z]) and upper-case ([A-Z]) English characters.

    You will convert a raw text document into its component paragraphs, sentences and words. 
    To test your results, queries will ask you to return a specific paragraph, sentence or word as described below.
    Alicia is studying the C programming language at the University of Dunkirk and she represents the words, sentences, paragraphs, and documents using pointers:

    A word is described by char*.
    A sentence is described by char**. The words in the sentence are separated by one space (" "). The last word does not end with a space(" ").
    A paragraph is described by char***. The sentences in the paragraph are separated by one period (".").
    A document is described by char****. The paragraphs in the document are separated by one newline("\n"). The last paragraph does not end with a newline.

    ------
    Alicia has sent a document to her friend Teodora as a string of characters, i.e. represented by char* not char****. Help her convert the document to char**** form by completing the following functions:

    - char**** get_document(char* text) to return the document represented by char****
    - char*** kth_paragraph(char**** document, int k) to return the kth paragraph
    - char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) to return the kth sentence in the mth paragraph
    - char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n)  to return the kth word in the mth sentence of the nth paragraph

    ------

    Input Format
    The first line contains the integer "paragraph_count".
    Each of the next "paragraph _count" lines contains a paragraph as a single string.
    The next line contains the integer "q" , the number of queries.
    Each of the next "q" lines or groups of lines contains a query in one of the following formats:
    1. the first line contains 1 k:
        - The next line contains an integer "x", the number of sentences in the kth paragraph.
        - Each of the next "x" lines contains an integer "a[i]", the number of words in the ith sentence.
        - This query corresponds to calling the function kth_paragraph.

    2. the first line contains 2 k m:
        - The next line contains an integer "x", the number of words in the kth sentence of the mth paragraph.
        - This query corresponds to calling the function kth_sentence_in_mth_paragraph.

    3. the onlyline contains 3 k m n:
        - this query correcpons to calling the function kth_word_in_mth_sentence_of_nth_paragraph.

    -----

    Constraints

    - The text which is passed to the get_document has words separated by a space (" "), sentences separated by a period (".") and paragraphs separated by a newline("\n").
    - The last word in a sentence does not end with a space.
    - The last paragraph does not end with a newline.
    - The words contain only upper-case and lower-case English letters.
    1 <= number of characters in the entire document  <= 1000
    1 <= number of paragraphs in the entire document  <= 5

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "includes/snips.h"

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

// char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {

// }

// char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 

// }

// char*** kth_paragraph(char**** document, int k) {

// }

char**** get_document(char* text) {
    char**** document = NULL;
    int paragraph_index = 0;
    int sentence_index = 0;
    int word_index = 0;

    // Allocate memory for the document
    document = (char****)malloc(sizeof(char***)*MAX_PARAGRAPHS);
    assert(document != NULL); // check if memory allocation succeeds

    // Initialize document
    for(int i=0; i< MAX_PARAGRAPHS; i++){
        document[i] = NULL;
    }

    // Split text into paragraphs
    char* paragraph = strtok(text, "\n");
    while(paragraph != NULL){
        document[paragraph_index] = (char***)malloc(sizeof(char**) * MAX_PARAGRAPHS);
        assert(document[paragraph_index] != NULL); //Check if memory allocation succeeds

        char* sentence = strtok(paragraph, ".");
        while(sentence != NULL){
            document[paragraph_index][sentence_index] = (char**)malloc(sizeof(char*)*MAX_PARAGRAPHS);
            assert(document[paragraph_index][sentence_index] != NULL);

            char* word = strtok(sentence, " ");
            while (word != NULL) {
                document[paragraph_index][sentence_index][word_index] = strdup(word);
                assert(document[paragraph_index][sentence_index][word_index] != NULL);
                word_index++;
                word = strtok(NULL, " ");
            }
            sentence_index++;
            word_index = 0;
            sentence = strtok(NULL, ".");
        }
        paragraph_index++;
        sentence_index = 0;
        paragraph = strtok(NULL, "\n");

    }
    return document;

}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

void print_document(char**** document){
    for(int i=0; document[i] != NULL; i++){
        for(int j=0; document[i][j] != NULL; j++){
            for(int k=0; document[i][j][k] != NULL; k++){
                printf("%s ", document[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    print_document(document);
    // int q;
    // scanf("%d", &q);

    // while (q--) {
    //     int type;
    //     scanf("%d", &type);

    //     if (type == 3){
    //         int k, m, n;
    //         scanf("%d %d %d", &k, &m, &n);
    //         char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
    //         print_word(word);
    //     }

    //     else if (type == 2){
    //         int k, m;
    //         scanf("%d %d", &k, &m);
    //         char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
    //         print_sentence(sentence);
    //     }

    //     else{
    //         int k;
    //         scanf("%d", &k);
    //         char*** paragraph = kth_paragraph(document, k);
    //         print_paragraph(paragraph);
    //     }
    //     printf("\n");
    // }     
    // Free memory
    free(text);
    for(int i = 0; i<MAX_PARAGRAPHS; i++){
        if(document[i] != NULL){
            for(int j = 0; j < MAX_PARAGRAPHS; j++){
                if(document[i][j] != NULL){
                    for(int k=0; document[i][j][k] != NULL; k++){
                        free(document[i][j][k]);
                    }
                    free(document[i][j]);
                }
            }

            free(document[i]);
        }

    }
    free(document);
    return 0;
}