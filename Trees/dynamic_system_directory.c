#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Definition of a file system tree node
typedef struct TreeNode{
    char name[50];
    struct TreeNode *children;
    struct TreeNode *sibling;
} TreeNode;


//Function to create a new tree node 
TreeNode* createNode(const char* name);
//Function to add a child node (subdirectory or file) to a parent node
void addChild(TreeNode* parent, TreeNode* child);
//Function to print the directory structure recursively
void printDirectoryStructure(TreeNode* node, int level);
//Function to free memory allocated for the directory structure
void freeDirectoryStructure(TreeNode* node);

//Main function
int main(){

    TreeNode* root = createNode("root");

    char choice;
    char name[50];

    do{
        printf("Enter 'd' to create a directory, 'f' to create a file, or 'q' to quit");
        scanf(" %c", &choice);
        if(choice == 'd'){
            printf("Enter a directory name: ");
            scanf(" %s", name);
            addChild(root, createNode(name));
        }else if(choice == 'f'){
            printf("Enter a file name: ");
            scanf(" %s", name);
            addChild(root, createNode(name));
        }

    } while (choice != 'q');

    //Print the directory structure
    printf("File system directory structure: \n");
    printDirectoryStructure(root,0);

    // Free memory allocated for the directory structure
    freeDirectoryStructure(root);
    
    return 0;
}



//Function to create a new tree node 
TreeNode* createNode(const char* name){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    newNode->children = NULL;
    newNode->sibling = NULL;
    return newNode;
}

//Function to add a child node (subdirectory or file) to a parent node
void addChild(TreeNode* parent, TreeNode* child){
    if (parent->children == NULL){
        parent->children = child;
    } else{
        TreeNode* current = parent->children;
        while (current->sibling != NULL){
            current = current->sibling;
        }
        current->sibling = child;
    }
}

//Function to print the directory structure recursively
void printDirectoryStructure(TreeNode* node, int level){
    if (node != NULL)
    {
        for (int i = 0; i < level; i++){
            printf("  "); //Indentation for visual clarity
        }
        printf("%s", node->name);
        printDirectoryStructure(node->children, level+1); // Recursively print children
        printDirectoryStructure(node->sibling, level); //Print siblings
    }
}


//Function to free memory allocated for the directory structure
void freeDirectoryStructure(TreeNode* node){
    if (node != NULL)
    {
        freeDirectoryStructure(node->children); //Recursively free children
        freeDirectoryStructure(node->sibling);  //Free siblings
        free(node);                             // free current node
    }
}