/* ilist - a module for manipulating linked-lists of integers
 *    - written by John C. Lusth, 2014
 *
 */

typedef struct node
    {
    int value;
    struct node *next;
    } Node;

/* Node prototypes */

Node *newNode(int value,Node *next);
Node *newEmptyNode(void);

/* List prototypes */

Node *newEmptyList(void);
int  head(Node *items);
Node *tail(Node *items);
void setHead(Node *items,int v);
void setTail(Node *items,Node *newtail);
Node *join(int r,Node *rest);
Node *arrayToList(int *items,int size);
void displayList(Node *items);
Node *readList(void);
void freeList(Node *items);
