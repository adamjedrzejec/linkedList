#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
Node *copy(Node *);
void reverse(Node **);
void sort(Node **);
char *strlwr(char *);

int main (int argc, const char **argv) {
  // char *str = strlwr("Wojciech Suchodolski");
  // printf("%s\n",str);
  // free(str);
  Node *list = init();
  push(&list, "pan prezydent");
  append(list, "Wojciech Suchodolski");
  Node *duplicate = copy(list);
  append(list, "obiad z MOPSu");
  push(&list, "szkolna 17");
  append(list, "afera płotowa");
  sort(&list);
  reverse(&list);
  display(list);
  destroy(list);

  display(duplicate);
  destroy(duplicate);

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

  temporaryNode = currentNode;
  currentNode = currentNode -> nextNode; // setting currentNode on last position
  temporaryNode -> nextNode = NULL;

  stringToReturn = currentNode -> string;
  free(currentNode);
  return stringToReturn;
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
  if((linkedList) -> nextNode == NULL && (linkedList) -> string == ""){
    (linkedList) -> string = string;
  }
  else{
    Node *currentNode = linkedList, *newNode = malloc(sizeof(Node));
    while(currentNode -> nextNode != NULL) { currentNode = currentNode -> nextNode; }
    newNode -> nextNode = NULL;
    newNode -> string = string;
    currentNode -> nextNode = newNode;
  }
}

Node *copy(Node *linkedList){
  Node *currentNode = linkedList;
  Node *copiedList = init();

  while(currentNode){
    append(copiedList, currentNode -> string);
    currentNode = currentNode -> nextNode;
  }

  return copiedList;
}

void reverse(Node **linkedList){
  Node *currentNode = *linkedList, *previous = NULL, *next = NULL;

  while(currentNode != NULL){
    next = currentNode -> nextNode;
    currentNode -> nextNode = previous;
    previous = currentNode;
    currentNode = next;
  }
  *linkedList = previous;
}

void sort(Node **linkedList){
  Node *currentNode = *linkedList;
  int i, j;

  for(i = 0; i < length(*linkedList) - 1; i++){
    currentNode = *linkedList;

    for(j = 0; j < length(*linkedList) - i - 1; j++){

      char *currentLowerCaseString = strlwr(currentNode -> string);
      char *nextLowerCaseString = strlwr(currentNode -> nextNode -> string);

      if(strcmp(currentLowerCaseString, nextLowerCaseString) == 1){
        char *temporaryString = currentNode -> string;
        currentNode -> string = currentNode -> nextNode -> string;
        currentNode -> nextNode -> string = temporaryString;
      }
      free(nextLowerCaseString);
      free(currentLowerCaseString);
      currentNode = currentNode -> nextNode;
    }
  }
}


char *strlwr(char *str){
  char *output = strdup(str);
  char *actualPosition = output;

  while(*actualPosition){
    if(isupper(*actualPosition))
      *actualPosition += 32; // 32 as the difference between upper and lower case in ASCII
    actualPosition++;
    }

  return output;
}
