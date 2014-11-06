typedef struct node
    {
    int value;
    struct node *next;
    } Node;

Node *newNode(int value,Node *next);
Node *newEmptyList(void);
int head(Node *items);
Node *tail(Node *items);
void setHead(Node *items,int v);
void setTail(Node *items,Node *newtail);
void displayList(Node *);
Node *arrayToList(int *items,int size);
Node *join(int r,Node *rest);
Node *readList(void);
void freeList(Node *items);
