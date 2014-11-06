#ifndef NODE_H
#define NODE_H
#include "stdio.h"

typedef struct node
    {
    int value;
    struct node *next;
    } Node;

Node *newEmptyNode(void);
Node *newNode(int v,Node *n);
int getNodeValue(Node *n);
Node *getNodeNext(Node *n);
void setNodeValue(Node *n,int v);
void setNodeNext(Node *n,Node *p);
Node * readIntegers(FILE *fp);
void displayList(Node *items);
#endif
