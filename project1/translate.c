#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "support.h"
int main(int argc,char **argv)
       {
       int dicount;//holds the number for the dictionary
       int msgcount;//holds the number for the messages
       //char ***dic;//holds the array of arrays for the dictionary
       char **duck;
       char **msg;//holds the array for the messages
       //checks the number of arguments and exits the program if not met
       if (argc != 3)
            {
            printf("need two arguments!\n");
            exit(1);
            }
        //count and fill arrays
        dicount = countDic(argv[1]);
      
        duck = readArray(argv[1]);
      	
        msgcount = countTokens(argv[2]);
        msg = readMsg(argv[2]);
        int i;
    
        //translate
        char * WorthlessPrint;
        
        
      for (i = 0; i < msgcount; ++i)
        {
          WorthlessPrint = translate(msg[i],duck,dicount);

          if (WorthlessPrint == 0)
          {
            printf("%s ",msg[i] );
          }
          else 
          {
            printf("%s ",WorthlessPrint );
          }
        }
        printf("\n");
       
        //free arrays
        //freeTable(dic,dicount);
        freeArray(duck,dicount);
        freeArray(msg,msgcount);
		
        return 0;
       }