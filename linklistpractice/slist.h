typedef struct node
    {
    char *value;
    struct node *next;
    } Node;

Node *newNode(char * value,Node *next);
Node *newEmptyList(void);
char *head(Node *items);
Node *tail(Node *items);
void setHead(Node *items,char *s);
void setTail(Node *items,Node *newList);
void displayList(Node *items);
Node *arrayToList(char **items,int size);
Node *join(char *s,Node *rest);
Node *readList(void);
void freeList(Node *items);
