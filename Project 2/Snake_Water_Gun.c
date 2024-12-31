#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));
    int player, computer = rand() % 3;
    /*
    0 --> Snake
    1 --> Water
    2 --> Gun
    */
    printf("Enter 0 for Snake, 1 for Water, 2 for Gun\n");
    scanf("%d", &player);

    if (player < 0 || player > 2) {
        printf("Invalid choice! Please select 0, 1, or 2.\n");
        return 1;
    }

    printf("Computer choose %d\n", computer);
    
    if (player == 0 && computer == 0)
    {
        printf("Game Draw!\n");
    }
    else if (player == 0 && computer == 1)
    {
        printf("You Win!\n");
    }
    else if (player == 0 && computer == 2)
    {
        printf("You Lose!\n");
    }
    else if (player == 1 && computer == 0)
    {
        printf("You Lose!\n");
    }
    else if (player == 1 && computer == 1)
    {
        printf("Game Draw!\n");
    }
    else if (player == 1 && computer == 2)
    {
        printf("You Win!\n");
    }
    else if (player == 2 && computer == 0)
    {
        printf("You Win!\n");
    }
    else if (player == 2 && computer == 1)
    {
        printf("You Lose!\n");
    }
    else if (player == 2 && computer == 2)
    {
        printf("Game Draw!\n");
    }

    return 0;
}