#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computeScore(string word);

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    // Compute the score of each word
    int score1 = computeScore(player1);
    int score2 = computeScore(player2);

    // Print the winner
    if(score1 > score2){
        printf("Player 1 wins!\n");
    } if(score2 > score1){
        printf("Player 2 wins!\n");
    } else if(score1 == score2){
        printf("Tie!\n");
    }
}

int computeScore(string word)
{
    int score = 0;

    for(int i = 0, len = strlen(word); i < len; i++){
        if(isupper(word[i])){
            score += POINTS[word[i] - 'A'];
        } else if(islower(word[i])){
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
