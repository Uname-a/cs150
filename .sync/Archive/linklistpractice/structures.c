#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "scanner.h"

void
displayEmployeesInFile(char *fileName)
    {
    Employee *e;
    FILE *fp = fopen(fileName,"r");
    if (fp == 0)
        {
        fprintf(stderr,"could not open file %s for reading\n",fileName);
        exit(1);
        }
    e = readEmployeeRecord(fp);
    while (!feof(fp))
        {
        displayEmployee(e);
        e = readEmployeeRecord(fp);
        }
    fclose(fp);
    }

/************* Employee ***************/

Employee *
newEmptyEmployee(void)
    {
    Employee *p = malloc(sizeof(Employee)); //malloc failure test omitted
    p->name = "";                           //set to the empty string
    p->title = "";                          //set to the empty string
    p->years = 0;                           //set to zero
    p->salary = 0.0;                        //set to zero
    return p;
    }

Employee *
newEmployee(char *n,char *t,int y,double s)
    {
    Employee *p = malloc(sizeof(Employee)); //malloc failure test omitted
    p->name = n;
    p->title = t;
    p->years = y;
    p->salary = s;
    return p;
    }

char *getEmployeeName(Employee *e) { return e->name; }
char *getEmployeeTitle(Employee *e) { return e->title; }
int getEmployeeYears(Employee *e) { return e->years; }
double getEmployeeSalary(Employee *e) { return e->salary; }
void setEmployeeName(Employee *e,char *n) { e->name = n; }
void setEmployeeTitle(Employee *e,char *t) { e->title = t; }
void setEmployeeYears(Employee *e,int y) { e->years = y; }
void setEmployeeSalary(Employee *e,double s) { e->salary = s; }

Employee *
readEmployeeRecord(FILE *fp)          // we pass the file pointer in
    {
    char *name,*title;
    int years;
    double salary;
    
    name = readString(fp);           //name is a string, not a token

    if (feof(fp)) { return 0; }      // no record, return the null pointer

    name = name;
    title = readToken(fp);
    years = readInt(fp);
    salary = readReal(fp);

    return newEmployee(name,title,years,salary);
    }

Employee **
readAllEmployeeRecords(char *fileName,int *finalSize)
    {
    FILE *fp;
    int count;
    int size = 10;                //initial size of destination array
    Employee *record;
    Employee **table;

    fp = fopen(fileName,"r");     //check for failed open omitted

    //allocate the destination array
    table = allocate(sizeof(Employee *) * size);

    count = 0;
    record = readEmployeeRecord(fp);
    while (!feof(fp))
        {
        if (count == size)              //array is full!
            {
            // grow the array by doubling its size
            size = size * 2;
            table = reallocate(table,sizeof(Employee *) * size);
            //now there is enough room
            }
        table[count] = record;           //DO NOT FREE THE RECORD!
        ++count;
        record = readEmployeeRecord(fp);
        }
    fclose(fp);

    //shrink the array to 'count' number of elements
    table = reallocate(table,sizeof(Employee *) * count);

    //count holds the number of items, store it in *finalSize
    *finalSize = count;
    return table;
    }

void
displayEmployee(Employee *e)
    {
    printf("Employee: %s\n",getEmployeeName(e));
    printf("    Title: %s\n",getEmployeeTitle(e));
    printf("    Years of Service: %d\n",getEmployeeYears(e));
    printf("    Salary: $%.2f\n",getEmployeeSalary(e));
    }
