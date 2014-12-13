typedef struct node
    {
    char *value;
    struct node *next;
    } Node;

/* Node prototypes */

Node *newNode(char *value,Node *next);
Node *newEmptyNode(void);

/* List prototypes */

Node *newEmptyList(void);
char *head(Node *items);
Node *tail(Node *items);
void setHead(Node *items,char *s);
void setTail(Node *items,Node *newList);
Node *join(char *s,Node *rest);
Node *arrayToList(char **items,int size);
void displayList(Node *items);
Node *readList(void);
void freeList(Node *items);
