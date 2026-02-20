#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;
    int userScore = 0, compScore = 0;
    int choice;

    srand(time(0));

    printf("=================================\n");
    printf("       HAND CRICKET GAME\n");
    printf("=================================\n");

    printf("Choose:\n1. Bat First\n2. Bowl First\nEnter choice: ");
    scanf("%d", &choice);

    // ---------------- FIRST INNINGS ----------------
    printf("\n--- First Innings ---\n");

    if(choice == 1) {
        printf("You are Batting!\n");
        while(1) {
            printf("Enter runs (1-6): ");
            scanf("%d", &user);

            if(user < 1 || user > 6) {
                printf("Invalid input! Enter 1-6 only.\n");
                continue;
            }

            computer = rand() % 6 + 1;
            printf("Computer chose: %d\n", computer);

            if(user == computer) {
                printf("You are OUT!\n");
                break;
            } else {
                userScore += user;
                printf("Your Score: %d\n", userScore);
            }
        }

        printf("\nTarget for Computer: %d\n", userScore + 1);
        printf("\n--- Second Innings ---\n");
        printf("Computer is Batting!\n");

        while(1) {
            printf("Enter bowl (1-6): ");
            scanf("%d", &user);

            computer = rand() % 6 + 1;
            printf("Computer chose: %d\n", computer);

            if(user == computer) {
                printf("Computer is OUT!\n");
                break;
            } else {
                compScore += computer;
                printf("Computer Score: %d\n", compScore);
            }

            if(compScore > userScore) {
                break;
            }
        }

    } else {
        printf("Computer is Batting!\n");

        while(1) {
            printf("Enter bowl (1-6): ");
            scanf("%d", &user);

            computer = rand() % 6 + 1;
            printf("Computer chose: %d\n", computer);

            if(user == computer) {
                printf("Computer is OUT!\n");
                break;
            } else {
                compScore += computer;
                printf("Computer Score: %d\n", compScore);
            }
        }

        printf("\nTarget for You: %d\n", compScore + 1);
        printf("\n--- Second Innings ---\n");
        printf("You are Batting!\n");

        while(1) {
            printf("Enter runs (1-6): ");
            scanf("%d", &user);

            if(user < 1 || user > 6) {
                printf("Invalid input! Enter 1-6 only.\n");
                continue;
            }

            computer = rand() % 6 + 1;
            printf("Computer chose: %d\n", computer);

            if(user == computer) {
                printf("You are OUT!\n");
                break;
            } else {
                userScore += user;
                printf("Your Score: %d\n", userScore);
            }

            if(userScore > compScore) {
                break;
            }
        }
    }

    // ---------------- RESULT ----------------
    printf("\n=================================\n");
    printf("FINAL SCORE:\nYou: %d\nComputer: %d\n", userScore, compScore);

    if(userScore > compScore)
        printf("🎉 You Win!\n");
    else if(userScore < compScore)
        printf("😢 Computer Wins!\n");
    else
        printf("It's a Draw!\n");

    printf("=================================\n");

    return 0;
}