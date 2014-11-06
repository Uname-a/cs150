#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "nodes.h"

Node *
newEmptyNode(void)
    {
    Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
    p->value = 0;                       //set to empty
    p->next = 0;                        //set to the null pointer
    return p;
    }

Node *
newNode(int v,Node *n)
    {
    Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
    p->value = v;
    p->next = n;
    return p;
    }

int getNodeValue(Node *n) { return n->value; }
Node *getNodeNext(Node *n) { return n->next; }
void setNodeValue(Node *n,int v) { n->value = v; return; }
void setNodeNext(Node *n,Node *p) { n->next = p; return; }

Node *
readIntegers(FILE *fp)
    {
    int x;
    Node *items;

    items = 0; //items starts out as null

    //employ the standard reading pattern
    x = readInt(fp);
    while (!feof(fp))
        {
        items = newNode(x,items);
        x = readInt(fp);
        }
    return items;
    }

void
displayList(Node *items)
    {
    while (items != 0)
        {
        printf("{%d}",getNodeValue(items));
        items = getNodeNext(items);
        }
    printf("\n");
    }
