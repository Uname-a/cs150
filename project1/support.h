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
//translating function

char * translate(char *Msg,char **Dic,int dicount);
//free arrays
void freeArray(char **r,int count);
char ** readArray(char *fileName);