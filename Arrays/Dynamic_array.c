#include <stdio.h>
#include <stdlib.h>


#define PAGES_PER_BOOK 1100
/*
 * This stores the total number of books in each shelf.
 */
 int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
 int** total_number_of_pages;





int main()
{
    int total_number_of_shelves = 5;
    //scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries = 5;
    //scanf("%d", &total_number_of_queries);
    

    // // Initialize global pointers
    total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));
    if(total_number_of_books==NULL){
        perror("FAiled to allocate number of books");
        exit(EXIT_FAILURE);
    }


    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    if(total_number_of_pages==NULL){
        perror("FAiled to allocate number of books");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<total_number_of_shelves; i++){
         total_number_of_pages[i] = (int*)calloc(PAGES_PER_BOOK, sizeof(int)); //Assuming each shelf can hold up 1100 books
        if(total_number_of_pages==NULL){
            perror("FAiled to allocate number of books");
            exit(EXIT_FAILURE);
        }
         
    }

    while (total_number_of_queries--) {
        int type_of_query;
        printf("Select the query: \n");
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            printf("Insert Shelve & Pages: \n");
            scanf("%d %d", &x, &y);
           
            int shelf_index;
            shelf_index = x % total_number_of_shelves;
    
            int book_index = total_number_of_books[shelf_index];
            total_number_of_pages[shelf_index][book_index] = y; // Update total number of pages
            total_number_of_books[shelf_index]++; 
        }
         else if (type_of_query == 2) {
            int x, y;
            printf("Insert Shelve & Book to find #of pages: \n");
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            printf("Insert # of books in Shelve: \n");
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    
    }


    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
