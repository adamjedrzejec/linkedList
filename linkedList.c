#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  char *string;
  struct Node *nextNode;
}Node;

Node init();
int length(Node);
void display(Node);
void push(Node, char *);



int main (int argc, char **argv) {
  Node testNode = init();
  testNode.string = "test";

  push(testNode, "test222");

  display(testNode);

  return 0;
}


Node init() {
  Node initializeLinkedList;
  initializeLinkedList.nextNode = NULL;
  initializeLinkedList.string = "\0";
  return initializeLinkedList;
}

int length(Node linkedList) {

  Node currentNode = linkedList;
  int length = 0;

  if(currentNode.nextNode == NULL && currentNode.string == "\0")
    return length;
  else
    length++;

  while(currentNode.nextNode != NULL) { currentNode = *currentNode.nextNode; length++; }

  return length;
}

void display(Node linkedList) {
  Node currentNode = linkedList;
  int counter;

  if(length(linkedList) == 0)
    printf("There are no elements in the list!");
  else
    for(counter = 0; counter < length(linkedList); counter++) {
      printf("%s, %d\n", currentNode.string, length(currentNode));
      if(currentNode.nextNode != NULL) currentNode = *currentNode.nextNode;
    }
}

void push(Node linkedList, char *string) {
  Node pushNode = init();
  pushNode.string = string;
  pushNode.nextNode = &linkedList;
}
