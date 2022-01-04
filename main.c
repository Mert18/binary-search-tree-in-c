#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining our node.
struct node {
  struct node *left;
  int data;
  struct node *right;
};

// Defining the root node. Globally by choice.
struct node *root = NULL;


// Inserting a value into to tree.
void insertNode(int value){

  // Creating newNode to insert, parentPointer for traversing by node, temp for checking parentNode's left and right values.
  struct node *newNode;
  struct node *parentPointer;
  struct node *temp;

  // Filling in the new node.
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode -> data = value;
  newNode -> left = NULL;
  newNode -> right = NULL;

  // If the root is empty, the new root is newNode.
  if(root == NULL){
    root = newNode;
    root -> left = NULL;
    root -> right = NULL;
  }else {
    // If the root is not empty, traverse the tree to find a suitable location. 
    parentPointer = NULL;
    temp = root;
    
    while(temp != NULL){
      parentPointer = temp;
      // If the value is smaller than temp, we need to insert the node in somewhere left. ( So we go to left side )
      if(value < temp -> data){
        temp = temp -> left;
      }else {
        // If the value is greater than the current location's data, go to right side.
        temp = temp -> right;
      }
    }
    // After finding a suitable location, check the value is smaller or greater, if it is smaller, insert the node to left, otherwise to right.
    if(value < parentPointer -> data){
      parentPointer -> left = newNode;
    }else {
      parentPointer -> right = newNode;
    }
  }
}


// Preorder traversal, First print root's data, then go to left, finish there, then go to right side.
void preorder(struct node *root){
  if (root == NULL) return ;
  printf ("%d ", root -> data);
  preorder(root -> left);
  preorder(root -> right);
}

// Inorder traversal, First finish the left side, print root's data, then go to right side.
void inorder(struct node *root){
  if(root == NULL) return ;
  inorder(root ->left);
  printf ("%d ", root -> data);
  inorder(root ->right);
}

// Postorder traversal, First go to left side, then right side and finally print root's data.
void postorder(struct node *root){
  if (root == NULL) return ;
  postorder(root -> left);
  postorder(root -> right);
  printf ("%d ", root -> data);
}


int main(){

  // C uses a single reference for creating random elements with rand() function. So we change this reference by giving it our current time. Otherwise it always produces the same numbers.
  srand(time(0));

  // Array that I hold the random values.
  int values[10];

  // Creating random elements.
  for(int i=0; i<10; i++){
    // To provide uniqueness, every time I generate an integer, I check if it is already in the array.
    int isElementPresent = 0;
    int num = (rand() % 25) + 1;
    for (int i = 0; i < 10; i++) {
        if (values[i] == num) {
            isElementPresent = 1;
            break;
        }
    }

    // If the element is in the array, than reduce i (to make that step again).
    if(isElementPresent){
      i--;
    }else{
    // Value is unique go ahead. 
      values[i] = num;
    }
  }

  // Printing the randomly generated numbers.
  printf("Values to be inserted: ");
  for(int i=0; i<10; i++){
    printf("%d ", values[i]);
    insertNode(values[i]);
  }

  printf("\n");

  printf("Inorder Traversal: ");
  inorder(root);
  printf("\n");

  printf("Preorder Traversal: ");
  preorder(root);
  printf("\n");

  printf("Postorder Traversal: ");
  postorder(root);

  printf("\n");

  return 0;
}


