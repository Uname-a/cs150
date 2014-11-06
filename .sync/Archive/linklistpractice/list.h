#ifndef LIST_H
#define LIST_H

typedef struct node
    {
    LIST_TYPE value;
    struct node *next;
    } Node;

Node *newNode(LIST_TYPE v,Node *n);
LIST_TYPE getNodeValue(Node *n);
void setNodeValue(Node *n,LIST_TYPE v);
Node *join(LIST_TYPE value,Node *items);
LIST_TYPE head(Node *items);
void setHead(Node *items,LIST_TYPE v);
LIST_TYPE getListIndex(Node *items,int index);
void setListIndex(Node *items,int index,LIST_TYPE v);

Node *newEmptyNode(void);
Node *getNodeNext(Node *n);
void setNodeNext(Node *n,Node *p);
Node *tail(Node *items);
void setTail(Node *items,Node *t);
void append(Node *listA,Node *listB);
Node *copyList(Node *items);
void freeList(Node *items);
#endif
