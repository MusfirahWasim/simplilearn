#include <stdio.h>
#include <conio.h>
#include <string.h>

// Function prototypes
void player1(char word[20]);
void title(void);
void instructions(void);
void displayHangman(int remainingTries);
void displayGuessedWord(char guessed[], int wordLength);

int main() {
    char word[20], guessed[20];
    int maxTries = 5, tries = 0, wordLength, i, correctGuess, remainingTries = 5;

    title();
    instructions();

    printf("\n\nPlayer 1: Enter the word to be guessed: ");
    player1(word);

    wordLength = strlen(word);

    for (i = 0; i < wordLength; ++i) {
        guessed[i] = '_';
    }
    guessed[wordLength] = '\0';

    while (tries < maxTries) {
        displayGuessedWord(guessed, wordLength);

        char guess;
        printf("Player 2: Enter a letter: ");
        scanf(" %c", &guess);

        correctGuess = 0;

        for (i = 0; i < wordLength; ++i) {
            if (guessed[i] == guess) {
                printf("You already guessed that letter. Try again.\n");
                correctGuess = 1;
                break;
            }
        }

        if (!correctGuess) {
            for (i = 0; i < wordLength; ++i) {
                if (word[i] == guess) {
                    guessed[i] = guess;
                    correctGuess = 1;
                }
            }
            
			if (correctGuess) {
                printf("Correct!\n");

                if (strcmp(word, guessed) == 0) {
                    displayGuessedWord(guessed, wordLength);
                    printf("Congratulations! You guessed the word.\n");
                    break;
                }
            } 
			else {
                remainingTries = maxTries - tries - 1;
                printf("Incorrect. %d tries remaining.\n", remainingTries);
                tries++;
                displayHangman(remainingTries);
            }

            if (remainingTries == 0) {
                printf("\n\nYOU ARE DEAD! GAME OVER!\n");
                printf("The word was: %s\n", word);
                break;
            }
        }
    }

    return 0;
}

void player1(char word[20]) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();

        if (ch == 13 || ch == 32 || ch == 8) {
            break;
        } else {
            word[i++] = ch;
            printf("*");
        }
    }

    printf("\n");
    word[i] = '\0';
}

void title(void) {
    printf("--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("--------------------------------------------\n\n");
}

void instructions(void) {
    printf("\n\t\t INSTRUCTIONS \n\t\t ============\n");
    printf("\n   1: HANGMAN IS THE GAME WHERE YOU HAVE TO GUESS THE WORD.");
    printf("\n   2: PLAYER 1 WILL ENTER A WORD AND PLAYER 2 HAS TO GUESS THAT WORD.");
    printf("\n   3: PLAYER 2 WILL HAVE A TOTAL OF FIVE CHOICES TO FIND THE MAXIMUM WORDS.");
    printf("\n   4: IF THE CORRECT LETTER IS GUESSED, THE GAME WILL SHOW THE POSITION OF THAT LETTER.\n");
    printf("\n \t\t\t SAVE THE HANGMAN. BEST OF LUCK!\n");
}

void displayHangman(int remainingTries) {
    // Display hangman graphics based on the number of remaining tries
    switch (remainingTries) {
        case 4:
            printf("  _______\n");
            printf("  |      \n");
            printf("  |      \n");
            printf("  |      \n");
            printf("  |      \n");
            printf("  |      \n");
            printf("__|_________\n\n");
            break;

        case 3:
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |      \n");
            printf("  |      \n");
            printf("  |      \n");
            printf("__|_________\n\n");
            break;

        case 2:
            printf("  _______ \n");
            printf("  |/   |  \n");
            printf("  |    O  \n");
            printf("  |    |  \n");
            printf("  |    |  \n");
            printf("  |       \n");
            printf("__|_________\n\n");
            break;

        case 1:
            printf("  _______  \n");
            printf("  |/   |   \n");
            printf("  |    O   \n");
            printf("  |   \\|/ \n");
            printf("  |    |   \n");
            printf("  |   / \\  \n");
            printf("__|_________\n\n");
            break;

        case 0:
            printf("  _______  \n");
            printf("  |/   |   \n");
            printf("  |    X   \n");
            printf("  |   \\|/ \n");
            printf("  |    |   \n");
            printf("  |   / \\ \n");
            printf("__|_________\n\n");
            break;
    }
}

void displayGuessedWord(char guessed[], int wordLength) {
    for (int i = 0; i < wordLength; ++i) {
        printf("%c ", guessed[i]);
    }
    printf("\n");
}
