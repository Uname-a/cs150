#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
//counting functions
int  countDic(char *);
int  countTokens(char *);
//reading to the array functions
char ** readRecord(FILE *fp);
char *** readTable(char *fileName);
char ** readMsg(char *fileName);

//debugging functions
void printTable(char ***table,int size);
void printMsg(char **table,int size);

//translating function
void translate(char **Msg,char ***Dic,int msgcount, int dicount);
//free arrays
void freeArray(char **r,int count);
void freeTable(char ***table,int size);