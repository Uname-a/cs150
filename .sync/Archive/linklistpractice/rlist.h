typedef struct node
    {
    double value;
    struct node *next;
    } Node;

Node *newNode(double value,Node *next);
Node *newEmptyList(void);
double head(Node *items);
Node *tail(Node *items);
void setHead(Node *items,char *s);
void setTail(Node *items,Node *newList);
Node *arrayToList(double *items,int size);
Node *join(double r,Node *rest);
Node *readList(void);
void freeList(Node *items);
