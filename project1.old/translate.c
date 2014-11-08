#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "support.h"
int main(int argc,char **argv)
       {
       int dicount;//holds the number for the dictionary
       int msgcount;//holds the number for the messages
       char ***dic;//holds the array of arrays for the dictionary
       char **msg;//holds the array for the messages
       //checks the number of arguments and exits the program if not met
       if (argc != 3)
            {
            printf("need two arguments!\n");
            exit(1);
            }
        //count and fill arrays
        dicount = countDic(argv[1]);
        dic = readTable(argv[1]);
        msgcount = countTokens(argv[2]);
        msg = readMsg(argv[2]);
        //translate
        char * WorthlessPrint;
        int i;
        
        for (i = 0; i < msgcount; ++i)
        {
          
          WorthlessPrint = translate(msg[i],dic,dicount);
       
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
        freeTable(dic,dicount);
        freeArray(msg,msgcount);
        return 0;
       }