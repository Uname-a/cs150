#include <stdio.h>
#include <stdlib.h> 
#include <string.h>    
#include "scanner.h"
//modified from a program from http://troll.cs.ua.edu/cs150/book/index_16.html
int countDic(char *fileName)
   {
        FILE *in = fopen(fileName,"r");
          if (in == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n",fileName);
            exit(1);
            }    
        int  count = 0;
        char *line;
        char *token;
        token = readToken(in);
        line = readString(in);        //readLine is a scanner module function
        while (!feof(in))
            {
            ++count;
            free(line); 
            free(token);
            token = readToken(in);          //we're done with line, so free it
            line = readString(in);
            }
        //always close your files
        fclose(in);
        return count;
        }
        //modified from a program from http://troll.cs.ua.edu/cs150/book/index_16.html
int countTokens(char *fileName)
        {
        FILE *fp;
        char *token;
        int count = 0;
        
        fp = fopen(fileName,"r");
        if (fp == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n",fileName);
            exit(1);
            }
        // output one token per line
        token = readToken(fp);
        
        while (!feof(fp))
            {
            
            ++count;
            free(token);
            token = readToken(fp);
            
            }
        // always close your open files when finished!!
        fclose(fp);
        return count ;
        }
        //modified from a program from http://troll.cs.ua.edu/cs150/book/index_16.html
char ** readRecord(FILE *fp)                // we pass the file pointer in
        {
        char *one,*two;
        char **record;
        
        one = readToken(fp);           //name is a string, not a token

        if (feof(fp)) { return 0; }      // no record, return null

        two = readString(fp);
        
        //make an empty record
        record = allocate(sizeof(char *) * 2);  //there are four fields

        //fill the record
        record[0] = one;
        record[1] = two;

        return record;
        }
//modified from a program from http://troll.cs.ua.edu/cs150/book/index_16.html
char *** readTable(char *fileName)
        {
        FILE *fp;
        int count;
        int size = 10;                  //initial size of destination array
        char **record;
        char ***table;

        fp = fopen(fileName,"r");     //check for failed open omitted

        //allocate the destination array
        table = allocate(sizeof(char **) * size);

        count = 0;
        record = readRecord(fp);
        while (!feof(fp))
            {
            if (count == size)              //array is full!
                {
                // grow the array by doubling its size
                size = size * 2;
                table = reallocate(table,sizeof(char **) * size);
                //now there is enough room
                }
            table[count] = record;           //DO NOT FREE THE RECORD!
            ++count;
            record = readRecord(fp);
            }
        fclose(fp);

        //shrink the array to 'count' number of elements
        table = reallocate(table,sizeof(char **) * count);

        return table;
        }
//modified from a program from http://troll.cs.ua.edu/cs150/book/index_16.html
char ** readMsg(char *fileName)
        {
        FILE *fp = fopen(fileName,"r");     //check for failed open omitted
        int size = 10;                      //initial size of destination array
        char *token;
        int count;

        char **items = allocate(sizeof(char *) * size);

        count = 0;
        token = readToken(fp);

        while (!feof(fp))
            {
            if (count == size)              //array is full!
                {
                // grow the array by doubling its size
                size = size * 2;
                items = reallocate(items,sizeof(char *) * size);
                //now there is enough room
                }
            items[count] = token;        //DO NOT FREE THE TOKEN!
            ++count;
            token = readToken(fp);
            }
        fclose(fp);
        //shrink the array to 'count' number of elements
        items = reallocate(items,sizeof(char *) * count);
        return items;
        }


char * translate(char *Msg,char ***Dic,int dicount)
{
        char * word;
        word = 0;
		int j;

        

		for(j=0;j < dicount;++j)
		{
            
			
            if (strcmp(Msg,Dic[j][0]) == 0)
			{
				
				word = Dic[j][1];
               
              
			}
			
            else if (strcmp(Msg,Dic[j][0]) == 1)
            {
                
                word = word ;
            }
			
		}
    return word;
}
void freeArray(char **r,int count)
{
	int i;
	for(i =0; i < count ; i++)
		{
			free(r[i]);
		}
		free(r);
}
void
	freeRecord(char **r)
	{

		free(r[0]);
		free(r[1]);
	}
void
    freeTable(char ***table,int size)
        {
        int i;
        //free the records first
        for (i = 0; i < size; ++i)
            {
            freeRecord(table[i]);
            }
        //now free the table array
        free(table);
        }