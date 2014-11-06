/* slist - a module for manipulating linked-lists of strings
 *    - written by John C. Lusth, 2014
 *
 *    - nodes have values hard-wired as strings
 *    - join takes a string as its first argument
 *    - head returns a string
 *    - tail returns the list beyond the first node
 *    - setHead replaces the head value
 *    - setTail replaces the tail
 *    - displayList displays a list of strings
 *    - arrayToList converts an array of strings into a list of strings
 *    - readList reads in a list look like this: (alpha,beta,gamma)
 *    - freeList frees all the nodes in the given list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

#define MAX_SIZE 1024 //size of buffer for readList


/********************* node functions ******************************/

/* newNode
 *     - create a node that holds an integer value
 */

Node *
newNode(char *value,Node *next)
    {
    Node *n = malloc(sizeof(Node));
    if (n == 0)
        {
        fprintf(stderr,"newNode: out of memory!\n");
        exit(1);
        }
    n->value = value;
    n->next = next;
    return n;
    }

Node *
newEmptyNode(void)
    {
    Node *n = malloc(sizeof(Node));
    if (n == 0)
        {
        fprintf(stderr,"newEmptyNode: out of memory!\n");
        exit(1);
        }
    n->value = 0;                       //set to the null pointer
    n->next = 0;                        //set to the null pointer
    return n;
    }


/********************* list functions ******************************/

/* newEmptyList
 *    - uses the null pointer to signify an empty list
 */

Node *
newEmptyList(void)
    {
    return 0;
    }

/* head
 *     - return the first integer value in the list
 */

char *
head(Node *items)
    {
    return items->value;
    }

/* setHead
 *     - replace the first integer value in the list
 */

void
setHead(Node *items,char *s)
    {
    items->value = s;
    }

/* tail
 *    - return the list minus the first node 
 */

Node *
tail(Node *items)
    {
    return items->next;
    }

/* setTail
 *    - replace the tail of a list 
 */

void
setTail(Node *items,Node *newtail)
    {
    items->next = newtail;
    }

/* join
 *     - join an integer value to a list
 */

Node *
join(char *s,Node *rest)
    {
    return newNode(s,rest);
    }

/* arrayToList
 *     - convert an array of strings into a list of string-valued nodes
 */

Node *
arrayToList(char **items,int size)
    {
    if (size == 0)
        return 0;
    else
        return join(items[0],arrayToList(items+1,size-1));
    }

void
displayList(Node *items)
    {
    while (items != 0)
        {
        printf("{%s}",head(items));
        items = tail(items);
        }
    }

Node *
readList(void)
    {
    Node *start,*hook,*result;
    char *token;
    char buffer[MAX_SIZE];

    if (fgets(buffer,sizeof(buffer),stdin) == 0)
        {
        fprintf(stderr,"readList: read failed!\n");
        exit(1);
        }

    start = join(0,0); //dummy head node
    hook = start;
    token = strtok(buffer,"(,) \n\t");
    while (token != 0) /* the read was good */
        {
        hook->next = join(strdup(token),0);
        hook = tail(hook);
        if (head(hook) == 0)
            {
            fprintf(stderr,"readList: out of memory!\n");
            exit(2);
            }
        token = strtok(0,"(,) \n\t");
        }

    result = tail(start);
    free(start); //only frees the first node!

    return result;
    }

void
freeList(Node *items)
    {
    while (items != 0)
        {
        Node *spot = items;
        items = tail(items);
        free(head(spot));    //free the duplicated string
        free(spot);          //free the node
        }
    }

