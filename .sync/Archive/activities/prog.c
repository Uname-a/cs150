#include <stdio.h>
int main(int argc, char **argv)
{
char name[512];
char answer;
printf("what is your name? ");
scanf("%s",name);
printf("hello,%s\n",name);
printf("Do you find CS150 intellectually stimulating? ");
scanf(" %c",&answer);
if (answer == 'Y' || answer == 'y')
        {
                printf("gretyat!\n");
                        }
else
        {
                printf("you will!\n");
                        }
return 0;
}
