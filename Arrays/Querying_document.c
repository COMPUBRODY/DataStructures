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

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    // Check if the document is not NULL
    if (document == NULL) {
        fprintf(stderr, "Error: Document is NULL\n");
        return NULL;
    }

    // Check if n is within the valid range of paragraphs
    if (n < 0 || n >= MAX_PARAGRAPHS) {
        fprintf(stderr, "Error: Invalid paragraph index\n");
        return NULL;
    }

    // Retrieve the n-th paragraph from the document
    char*** paragraph = document[n];

    // Check if the retrieved paragraph is not NULL
    if (paragraph == NULL) {
        fprintf(stderr, "Error: Paragraph %d is NULL\n", n);
        return NULL;
    }

    // Check if m is within the valid range of sentences in the n-th paragraph
    int sentence_count = 0;
    while (paragraph[sentence_count] != NULL) {
        sentence_count++;
    }
    if (m < 0 || m >= sentence_count) {
        fprintf(stderr, "Error: Invalid sentence index in paragraph %d\n", n);
        return NULL;
    }

    // Retrieve the m-th sentence from the n-th paragraph
    char** sentence = paragraph[m];

    // Check if the retrieved sentence is not NULL
    if (sentence == NULL) {
        fprintf(stderr, "Error: Sentence %d in paragraph %d is NULL\n", m, n);
        return NULL;
    }

    // Check if k is within the valid range of words in the m-th sentence
    int word_count = 0;
    while (sentence[word_count] != NULL) {
        word_count++;
    }
    if (k < 0 || k >= word_count) {
        fprintf(stderr, "Error: Invalid word index in sentence %d of paragraph %d\n", m, n);
        return NULL;
    }

    // Retrieve the k-th word from the m-th sentence
    char* word = sentence[k];

    // Return the pointer to the k-th word
    return word;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    // Check if the document is not NULL
    if (document == NULL) {
        fprintf(stderr, "Error: Document is NULL\n");
        return NULL;
    }

    // Check if m is within the valid range of paragraphs
    if (m < 0 || m >= MAX_PARAGRAPHS) {
        fprintf(stderr, "Error: Invalid paragraph index\n");
        return NULL;
    }

    // Retrieve the m-th paragraph from the document
    char*** paragraph = document[m];

    // Check if the retrieved paragraph is not NULL
    if (paragraph == NULL) {
        fprintf(stderr, "Error: Paragraph %d is NULL\n", m);
        return NULL;
    }

    // Check if k is within the valid range of sentences in the m-th paragraph
    int sentence_count = 0;
    while (paragraph[sentence_count] != NULL) {
        sentence_count++;
    }
    if (k < 0 || k >= sentence_count) {
        fprintf(stderr, "Error: Invalid sentence index in paragraph %d\n", m);
        return NULL;
    }

    // Retrieve the k-th sentence from the m-th paragraph
    char** sentence = paragraph[k];

    // Return the pointer to the k-th sentence
    return sentence;
}


char*** kth_paragraph(char**** document, int k) {
    // Check if the document is not NULL
    if (document == NULL) {
        fprintf(stderr, "Error: Document is NULL\n");
        return NULL;
    }

    // Check if k is within the valid range of paragraphs
    if (k < 0 || k >= MAX_PARAGRAPHS) {
        fprintf(stderr, "Error: Invalid paragraph index\n");
        return NULL;
    }

    // Retrieve the k-th paragraph from the document
    char*** paragraph = document[k];

    // Return the pointer to the k-th paragraph
    return paragraph;

}

char**** get_document(char* text) {
    char**** document = (char****)malloc(sizeof(char***)*MAX_PARAGRAPHS);
    if (document == NULL) {
        perror("Failed to allocate memory for document");
        exit(EXIT_FAILURE);
    }
    int paragraph_index = 0;

    // Split text into paragraphs
    char* paragraph_start = text;
    char* paragraph_end = strstr(paragraph_start, "\n");

    while (paragraph_end != NULL) {
        // Allocate memory for the paragraph
        document[paragraph_index] = (char***)malloc(sizeof(char**) * MAX_PARAGRAPHS);
        if (document[paragraph_index] == NULL) {
            perror("Failed to allocate memory for sentences in paragraph");
            exit(EXIT_FAILURE);
        }

        // Copy the paragraph into the document
        size_t paragraph_length = paragraph_end - paragraph_start;
        document[paragraph_index][0] = (char**)malloc(sizeof(char*) * (paragraph_length + 1));
        if (document[paragraph_index][0] == NULL) {
            perror("Failed to allocate memory for sentences in paragraph");
            exit(EXIT_FAILURE);
        }
        strncpy(document[paragraph_index][0], paragraph_start, paragraph_length);
        document[paragraph_index][0][paragraph_length] = '\0'; // Null-terminate the string

        // Move to the next paragraph
        paragraph_start = paragraph_end + 1;
        paragraph_end = strstr(paragraph_start, "\n");
        paragraph_index++;
    }

    // Handle the last paragraph
    size_t last_paragraph_length = strlen(paragraph_start);
    document[paragraph_index] = (char***)malloc(sizeof(char**) * MAX_PARAGRAPHS);
    if (document[paragraph_index] == NULL) {
        perror("Failed to allocate memory for sentences in paragraph");
        exit(EXIT_FAILURE);
    }
    document[paragraph_index][0] = (char**)malloc(sizeof(char*) * (last_paragraph_length + 1));
    if (document[paragraph_index][0] == NULL) {
        perror("Failed to allocate memory for sentences in paragraph");
        exit(EXIT_FAILURE);
    }
    strcpy(document[paragraph_index][0], paragraph_start);

    // Increment the paragraph index
    paragraph_index++;
    
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
        printf("line 169\n");
        for(int j=0; document[i][j] != NULL; j++){
            printf("line 171\n");
            for(int k=0; document[i][j][k] != NULL; k++){
                printf(" %s", document[i][j][k]);
                printf("line 174\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    //char* text = get_input_text();
    char* text = "This is the first paragraph. This is the second paragraph.\nThis is the third paragraph.";

    char**** document = get_document(text);
    print_document(document);
    //print_paragraph(document[2]);
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