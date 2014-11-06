#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdio.h>

typedef struct employee
    {
    char *name;
    char *title;
    int years;
    double salary;
    } Employee;

Employee *newEmptyEmployee(void);
Employee *newEmployee(char *n,char *t,int y,double s);
char *getEmployeeName(Employee *e);
char *getEmployeeTitle(Employee *e);
int getEmployeeYears(Employee *e);
double getEmployeeSalary(Employee *e);
void setEmployeeName(Employee *e,char *n);
void setEmployeeTitle(Employee *e,char *t);
void setEmployeeYears(Employee *e,int y);
void setEmployeeSalary(Employee *e,double s);
Employee *readEmployeeRecord(FILE *fp);
Employee **readAllEmployeeRecords(char *fileName,int *finalSize);
void displayEmployee(Employee *e);
void displayEmployeesInFile(char *fileName);
#endif
