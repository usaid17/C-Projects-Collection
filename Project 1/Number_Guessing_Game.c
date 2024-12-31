#include <stdio.h>   // For input and output functions
#include <stdlib.h>  // For the rand() and srand() functions
#include <time.h>    // For the time() function to seed the random number generator

int main() {
    // Seed the random number generator with the current time
    srand(time(0));  

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int no_of_guesses = 0;
    int guessed;

    do {
        printf("Enter the number: ");
        scanf("%d", &guessed);

        if (guessed < randomNumber) {
            printf("Enter a higher number\n");
        } 
        else if (guessed > randomNumber) {
            printf("Enter a lower number\n");
        } 
        else {
            printf("Congrats! ");
        }

        no_of_guesses++;
    } while (guessed != randomNumber);

    printf("You guessed the number in %d guesses.\n", no_of_guesses);

    return 0;
}
