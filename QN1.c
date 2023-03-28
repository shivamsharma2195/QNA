#include <stdio.h>

#define MAX(M, N)   M>N?M:N     // macro to find maximum of two numbers
#define MIN(M, N)   M<N?M:N     //macro to find minimum of two numbers


int main()
{
    int M, N, max, min, diff, avail_value, i; //define variables to use in code
    printf("enter the size "); 
    scanf("%d %d",&M,&N); //get value from user

    
    max = MAX(M, N);
    min = MIN(M, N);

    while (max > 0 && min > 0) { // loop till every square is covered by loop
        printf("%dx%d\n", min, min); // first print the smaller number available as square
        diff = max - min; // get the difference between the bigger and smaller number
        if (diff >= min) { // if the difference is greater than or equal to the smaller number, print other possible squares
            avail_value = diff / min; // get total squares possible with difference and smaller number
            for (i = 0; i < avail_value; i++){
                printf("%dx%d\n", min, min); // print possible values for squares
            }
            max = min; // set the bigger number equal to the smaller number available for further process
            min = diff % min; // set the smaller number to the remainder of the division
        } else { // if the difference is less than the smaller number, swap the smaller and bigger number
            int temp = max;
            max = min;
            min = temp - min;   
        }
    }
    

    return 0;
}
