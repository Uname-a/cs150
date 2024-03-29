#include <stdio.h>

// scope 1
char *name = "Ye Olde Flower Shoppe";
int days = 1035;

void
fillOrder(char *flower, int count)
    {
    // scope 2
    char *ending = count == 1? "" : "s";
    printf("Preparing %d flower%s.\n",count,ending);
    return;
    }

void
openStore(char *prop)
    {
    // scope 3
    int months = days / 30;
    if (months > 60)
        {
        // scope 4
        int years = days / 365;
        printf("%s opened '%s' %d years ago.\n",prop,name,years);
        }
    else if (months > 3)
        {
        printf("%s opened '%s' %d months ago.\n",prop,name,months);
        }
    else
        {
        printf("%s opened '%s' %d days ago.\n",prop,name,days);
        }
    return;
    }

void
answers(void)
    {
    printf("In what scope is variable 'ending' defined?\n");
    printf("  scope 2\n");
    printf("In what scope is variable 'years' defined?\n");
    printf("  scope 4\n");
    printf("In what scope is name 'openStore' defined?\n");
    printf("  scope 1\n");
    printf("In what scope or scopes is variable 'type' visible?\n");
    printf("  scope 5\n");
    printf("In what scope or scopes is variable 'name' visible?\n");
    printf("  scope 1,2,3,4,5\n");
    printf("In what scope or scopes is variable 'months' visible?\n");
    printf("  scope 3,4\n");
    printf("What variables are visible in scope 1?\n");
    printf("  name , days ,\n");
    printf("What variables are visible in scope 2?\n");
    printf("  flower , count , ending , name , days\n");
    printf("What variables are visible in scope 4?\n");
    printf("name , days , prop , months , years \n");

    printf("Is there one scope where all the variables are visible?\n");
    printf("  no\n");
    return;
    }

int
main(int argc,char **argv)
    {
    // scope 5
    int num;
    char *type;
    char *proprietor = "Chris A. Mumm";
    openStore(proprietor);
    type = "bouquet";
    num = 20;
    fillOrder(type,num);
    type = "corsage";
    num = 1;
    fillOrder(type,num);
    answers();

    return 0;
    }
