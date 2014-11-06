#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getName(char *);
void say();

int main(int argc, char **argv)
{
	char *name = malloc(sizeof(*name));
	getName(name);
	say(name);
	return 0;
}

void getName(char *name)
{
	printf("Enter your name: ");
	scanf(" %s", name);

}

void say(char *name)
{
	printf("Welcome, %s!\n", name );
	printf("Go Crimson Tide!\n");
}