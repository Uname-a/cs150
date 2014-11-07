/*
 * Was a program for baseball or softball on-base percentage, by John C. Lusth, 2014
 * 
 * this program may be freely distributed and modified, as long as:
 * 
 * a) the authorship of any modifications is added
 *
 * b) the reason for modification is added
 *
 * c) the comments are updated to reflect modifications
 *
 * d) the original authorship and that of any previous modifiers is preserved.
 * 
 */


//modifications by matt baird 
//modified converting this program to calculate soccer offensive production rating


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

// function prototypes

void getData(int *,int *,int *,int *,int *,int*);//added one more varable
void displayData(int,int,int,int,int,int);//added one more varable
double computeRating(int,int,int,int,int,int);//added one more varable

int
main(int argc, char **argv)
    {
    int goals,shots,corner,assists,passes,touches;//converted old varable names to match soccer terms
    double rating;
    
    //get the statistics from the user
    //pass in addresses so getDat can set these variables
    getData(&shots,&corner,&assists,&goals,&passes,&touches);//converted old varable names to match soccer terms

    //compute the rating
    rating = computeRating(shots,corner,assists,goals,passes,touches);//converted old varable names to match soccer terms

    //display the statistics
    displayData(shots,corner,assists,goals,passes,touches);//converted old varable names to match soccer terms

    //display the results
    printf("\nFor these statistics, the offensive production rating is %.3f\n",rating);//changed the words to match soccer terms and added a limiter for the amount of decimal places to 3

    return 0;
    }

void//changed the varable names to go with soccer terms and also the prompts
getData(int *shots,int *corner,int *assists,int *goals,int *passes,int *touches)
    {
    printf("Enter number of goals: ");
    scanf(" %d",goals);
    printf("Enter number of shots: ");
    scanf(" %d",shots);  
    printf("Enter number of corner kicks: ");
    scanf(" %d",corner);
    printf("Enter number of assists: ");
    scanf(" %d",assists);
    printf("Enter number of passes: ");
    scanf(" %d",passes);
    printf("Enter numer of touches\n");
    scanf(" %d",touches);
    }

double//changed the math equation to the one for soccer and added/  changed the varable names
computeRating(int shots,int corner,int assists,int goals,int passes,int touches)
    {
    return ((5 * goals) + (4 * shots) + (3 * corner) + (2 * assists) + 
passes) 
/ 
((double) (touches)); 
    }

void//changed varable names and added one more varable for the conversion
displayData(int shots,int corner,int assists,int goals,int passes,int touches)
    {
    printf("\n");
    printf("goals: %d\n",goals);
    printf("shots: %d\n",shots);
    printf("corner kicks: %d\n",corner);
    printf("assists: %d\n",assists);
    printf("passes: %d\n",passes);
    printf("touches: %d\n", touches);
    }
