#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getPoints(char *word);
void compare(int points1, int points2);

int main(void)
{
    // Get player words
    char player1Word[50];
    char player2Word[50];

    printf("Player 1: ");
    scanf("%s", player1Word);

    printf("Player 2: ");
    scanf("%s", player2Word);

    // Return number of points for each word
    int player1Points = getPoints(player1Word);
    int player2Points = getPoints(player2Word);

    // Compare total points
    compare(player1Points, player2Points);

}

int getPoints(char *word)
{
    // Array with points
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int sum = 0;

    // Iterate through string
    for (int i = 0, n = strlen(word); i < n; i++)
    {

        // If character is a lowercase letter add its point total to the sum
        if (word[i] < 123 && word[i] > 96)
        {
            sum = sum + points[word[i] - 97];
        }

        // If character is an uppercase letter, convert to lower case then add its point total to the sum
        else if (word[i] < 91 && word[i] > 64)
        {
            sum = sum + points[tolower(word[i]) - 97];
        }
    }
    return sum;
}

void compare(int points1, int points2)
{
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }

    else if (points1 < points2)
    {
        printf("Player 2 wins!\n");
    }

    else
    {
        printf("Tie!");
    }
}