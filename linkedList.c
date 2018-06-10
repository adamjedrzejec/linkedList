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



int main (int argc, const char **argv) {
  Node *testNode = init();
  testNode -> string = "test";

  push(&testNode, "test222");
  if(testNode -> nextNode != NULL)
    printf("STR: %s\n", testNode -> nextNode -> string);
  else
    printf("NULLL\n");
  display(testNode);

  free(testNode -> nextNode);
  free(testNode);

  return 0;
}


Node *init() {
  struct Node *linkedList = malloc(sizeof(Node));
  linkedList -> nextNode = NULL;
  linkedList -> string = "\0";
  return linkedList;
}

int length(Node *linkedList) {

  Node *currentNode;
  currentNode = linkedList;
  int length = 0;

  if(currentNode -> nextNode == NULL && currentNode -> string == "\0")
    return length;
  else
    length++;

  while(currentNode -> nextNode != NULL) { currentNode = currentNode -> nextNode; length++; }

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
  Node *pushNode = malloc(sizeof(Node));
  pushNode -> string = string;
  pushNode -> nextNode = *linkedList;
  *linkedList = pushNode;
}
