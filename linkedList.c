#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  char *string;
  struct Node *nextNode;
}Node;

Node *init();
int length(Node *);
void display(Node *);
void push(Node **, char *);
char *pop(Node *);
void destroy(Node *);
void append(Node *, char *);
//copy
//reverse
//sort


int main (int argc, const char **argv) {
  Node *testNode = init();
  testNode -> string = "test";

  push(&testNode, "test222");
  push(&testNode, "test2352");
  display(testNode);
  destroy(testNode);

  printf("\n\n");

  testNode = init();
  push(&testNode, "test1");
  push(&testNode, "test2");
  push(&testNode, "test3");
  append(testNode, "test4");
  printf("taken: %s\n", pop(testNode));
  display(testNode);
  destroy(testNode);
  return 0;
}






Node *init() {
  struct Node *linkedList = malloc(sizeof(Node));
  linkedList -> nextNode = NULL;
  linkedList -> string = "";
  return linkedList;
}

int length(Node *linkedList) {

  Node *currentNode = linkedList;
  int length = 1;

  while(currentNode -> nextNode != NULL) { currentNode = currentNode -> nextNode; length++; } //good to remember that if left side in (sth && sth) is false, then right side is never checked
  return length;
}

void display(Node *linkedList) {

  Node *currentNode = linkedList;
  int counter;

  printf("\nAll elements of the list:\n");

  if(length(linkedList) == 0)
    printf("There are no elements in the list!\n");
  else
    for(counter = 0; counter < length(linkedList); counter++) {
      printf("%s, %d\n", currentNode -> string, length(currentNode));
      if(currentNode -> nextNode != NULL)
        currentNode = currentNode -> nextNode;
    }
}

void push(Node **linkedList, char *string) {
  if((*linkedList) -> nextNode == NULL && (*linkedList) -> string == ""){
    (*linkedList) -> string = string;
  }
  else{
    Node *pushNode = malloc(sizeof(Node));
    pushNode -> string = string;
    pushNode -> nextNode = *linkedList;
    *linkedList = pushNode;
  }
}

char *pop(Node *linkedList){
  Node *currentNode = linkedList, *temporaryNode;
  char *stringToReturn;
  int i;

  if(currentNode -> nextNode == NULL){ // for list of 1 element
    stringToReturn = currentNode -> string;
    free(currentNode);
    return stringToReturn;
  }

  if(currentNode -> nextNode != NULL)
    while((currentNode -> nextNode) -> nextNode != NULL){ currentNode = currentNode -> nextNode; }

  //if(currentNode -> nextNode != NULL){ // if linkedList is bigger than 1 element long, then currentNode is set on penultimate node
    temporaryNode = currentNode;
    currentNode = currentNode -> nextNode; // setting currentNode on last position
    temporaryNode -> nextNode = NULL;
  //}

  //if(currentNode -> nextNode == NULL){
    stringToReturn = currentNode -> string;
    free(currentNode);
    return stringToReturn;
  //}
}

void destroy(Node *linkedList){
  int counter;
  Node *lastNode = linkedList, *nodeToFree;
  while(lastNode -> nextNode != NULL){
    nodeToFree = lastNode;
    lastNode = lastNode -> nextNode;
    free(nodeToFree);
  }
  free(lastNode);
}

void append(Node *linkedList, char *string){
  Node *currentNode = linkedList, *newNode = malloc(sizeof(Node));

  while(currentNode -> nextNode != NULL) { currentNode = currentNode -> nextNode; }

  newNode -> nextNode = NULL;
  newNode -> string = string;

  currentNode -> nextNode = newNode;
}
