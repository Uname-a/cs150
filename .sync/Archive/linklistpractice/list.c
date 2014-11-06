#include <stdlib.h>
#include "list.h"

static Node *getListIndexedNode(Node *,int);

Node *
newNode(LIST_TYPE v,Node *n)
    {
    Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
    p->value = v;
    p->next = n;
    return p;
    }

LIST_TYPE getNodeValue(Node *n) { return n->value; }
void setNodeValue(Node *n,LIST_TYPE v) { n->value = v; return; }
Node *join(LIST_TYPE value,Node *items) { return newNode(value,items); }
LIST_TYPE head(Node *items) { return getNodeValue(items); }
void setHead(Node *items,LIST_TYPE v) { return setNodeValue(items,v); }

LIST_TYPE
getListIndex(Node *items,int index)
    {
    Node *n = getListIndexedNode(items,index);
    return head(n);
    }

void
setListIndex(Node *items,int index,LIST_TYPE v)
    {
    Node *n = getListIndexedNode(items,index);
    setHead(n,v);
    }

Node *getNodeNext(Node *n) { return n->next; }
void setNodeNext(Node *n,Node *p) { n->next = p; return; }
Node *tail(Node *items) { return getNodeNext(items); }
void setTail(Node *items,Node *t) { return setNodeNext(items,t); }

void
append(Node *listA,Node *listB) //listA length must be > 0
    {
    while (getNodeNext(listA) != 0)
        {
        listA = getNodeNext(listA);
        }
    setNodeNext(listA,listB);
    return;
    }

static Node *
getListIndexedNode(Node *items,int index)
    {
    while (index > 0)
        {
        items = tail(items);
        --index;
        }
    return items;
    }

Node *
copyList(Node *items)
    {
    Node *result = 0;   //resulting list starts out empty
    while (items != 0)           //walk the list
        {
        result = join(head(items),result); //add current value to result
        items = tail(items);                //take a step
        }
    return result;
    }

void
freeList(Node *items)
    {
    while(items != 0)
        {
        Node *next = tail(items);
        free(items);                //free the current node
        items = next;
        }
    }
